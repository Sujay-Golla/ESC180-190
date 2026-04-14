#include "seamcarving.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int dx(struct rgb_img *im, int y, int x) {
    int delta_red, delta_green, delta_blue;
    if (x == 0) {
        delta_red   = get_pixel(im, y, x + 1, 0) - get_pixel(im, y, (im->width) - 1, 0);
        delta_green = get_pixel(im, y, x + 1, 1) - get_pixel(im, y, (im->width) - 1, 1);
        delta_blue = get_pixel(im, y, x + 1, 2) - get_pixel(im, y, (im->width) - 1, 2);

    } else if (x == im->width - 1) {
        delta_red   = get_pixel(im, y, x - 1, 0) - get_pixel(im, y, 0, 0);
        delta_green = get_pixel(im, y, x - 1, 1) - get_pixel(im, y, 0, 1);
        delta_blue = get_pixel(im, y, x - 1, 2) - get_pixel(im, y, 0, 2);

    } else {
        delta_red   = get_pixel(im, y, x + 1, 0) - get_pixel(im, y, x - 1, 0);
        delta_green = get_pixel(im, y, x + 1, 1) - get_pixel(im, y, x - 1, 1);
        delta_blue  = get_pixel(im, y, x + 1, 2) - get_pixel(im, y, x - 1, 2);

    }

    return delta_red*delta_red + delta_green*delta_green + delta_blue*delta_blue;
}

int dy(struct rgb_img *im, int y, int x) {
    int delta_red, delta_green, delta_blue;
    if (y == 0) {
        delta_red   = get_pixel(im, y + 1, x, 0) - get_pixel(im, (im->height) - 1, x, 0);
        delta_green = get_pixel(im, y + 1, x, 1) - get_pixel(im, (im->height) - 1, x, 1);
        delta_blue = get_pixel(im, y + 1, x, 2) - get_pixel(im, (im->height) - 1, x, 2);

    } else if (y == im->height - 1) {
        delta_red   = get_pixel(im, y - 1, x, 0) - get_pixel(im, 0, x, 0);
        delta_green = get_pixel(im, y - 1, x, 1) - get_pixel(im, 0, x, 1);
        delta_blue = get_pixel(im, y - 1, x, 2) - get_pixel(im, 0, x, 2);

    } else {
        delta_red   = get_pixel(im, y + 1, x, 0) - get_pixel(im, y - 1, x, 0);
        delta_green = get_pixel(im, y + 1, x, 1) - get_pixel(im, y - 1, x, 1);
        delta_blue  = get_pixel(im, y + 1, x, 2) - get_pixel(im, y - 1, x, 2);

    } 

    return delta_red*delta_red + delta_green*delta_green + delta_blue*delta_blue;
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad) {
    create_img(grad, im->height, im->width);
    for (int y = 0; y < im->height; y++) {
        for (int x = 0; x < im->width; x++) {
            int energy_x = dx(im, y, x);
            int energy_y = dy(im, y, x);
            double energy_total = sqrt((double)((double)energy_x + (double)energy_y))/10;
            int energy = (uint8_t)(energy_total);
            set_pixel(*grad, y, x, energy, energy, energy);
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr){
    *best_arr = malloc(sizeof(double) * grad->height * grad->width);
    for (int y = 0; y < grad->height; y++) {
        for (int x = 0; x < grad->width; x++) {
            if (y == 0) {
                (*best_arr)[y * grad->width + x] = get_pixel(grad, y, x, 0);
            } else {
                double best = (*best_arr)[(y - 1) * grad->width + x];
                if (x == 0) {
                    best = fmin(best, (*best_arr)[(y - 1) * grad->width + x + 1]);
                } else if (x == grad->width - 1) {
                    best = fmin(best, (*best_arr)[(y - 1) * grad->width + x - 1]);
                } else {
                    best = fmin(fmin(best, (*best_arr)[(y - 1) * grad->width + x + 1]), (*best_arr)[(y - 1) * grad->width + x - 1]);
                }
                (*best_arr)[y * grad->width + x] = get_pixel(grad, y, x, 0) + best;
            }
        }
    }
}

void recover_path(double *best, int height, int width, int **path){
    *path = malloc(sizeof(int) * height);
    (*path)[height - 1] = 0;

    for (int x = 0; x < width; x++) {
        if (best[(height - 1) * width + x] < best[(height - 1) * width + (*path)[height - 1]]) {
            (*path)[height - 1] = x;
        }
    }

    for (int y = height - 2; y >= 0; y--) {
        int x = (*path)[y + 1];
        int best_x = x;
        double best_above = best[y * width + x];

        if (x == 0) {
            if (best[y * width + x + 1] < best_above) {
                best_x = x + 1;
                best_above = best[y * width + x + 1];
            }
        } else if (x == width - 1) {
            if (best[y * width + x - 1] < best_above) {
                best_x = x - 1;
                best_above = best[y * width + x - 1];
            }
        } else {
            if (best[y * width + x + 1] < best_above) {
                best_x = x + 1;
                best_above = best[y * width + x + 1];
            }
            if (best[y * width + x - 1] < best_above) {
                best_x = x - 1;
                best_above = best[y * width + x - 1];
            }
        }

        (*path)[y] = best_x;
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    create_img(dest, src->height, src->width - 1);
    for (int y = 0; y < src->height; y++) {
        for (int x = 0; x < path[y]; x++) {
            set_pixel(*dest, y, x, get_pixel(src, y, x, 0), get_pixel(src, y, x, 1), get_pixel(src, y, x, 2));
        }
        for (int x = path[y] + 1; x < src->width; x++) {
            set_pixel(*dest, y, x - 1, get_pixel(src, y, x, 0), get_pixel(src, y, x, 1), get_pixel(src, y, x, 2));
        }
    }
}

int main(){
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");

    for(int i = 0; i < 200; i++){
        calc_energy(im, &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        char filename[200];
        sprintf(filename, "images/img%d.bin", i);
        write_img(cur_im, filename);

        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    destroy_image(im);
}
