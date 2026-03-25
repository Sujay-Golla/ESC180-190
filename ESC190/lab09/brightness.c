// Change brightness of an image

#include "c_img.h"
#include <stdio.h>

int main(){
    float settings[] = {0.25, 0.5, 1.5, 2.0};

    for (int i = 0; i < 4; i++) {
        struct rgb_img *im;
        read_in_img(&im, "image.bin");
        for (int y = 0; y < im->height; y++){
            for (int x = 0; x < im->width; x++){
                int r = get_pixel(im, y, x, 0);
                int g = get_pixel(im, y, x, 1);
                int b = get_pixel(im, y, x, 2);
                r = (int)(r * settings[i]);
                g = (int)(g * settings[i]);
                b = (int)(b * settings[i]);
                if (r > 255) {
                    r = 255;
                }
                if (g > 255) {
                    g = 255;
                }
                if (b > 255) {
                    b = 255;
                }
                set_pixel(im, y, x, r, g, b);
            }
        }
        char filename[] = "cannon1.bin";
        filename[6] = '0' + i;
        write_img(im, filename);
        destroy_image(im);
    }
}