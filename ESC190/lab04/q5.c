#include <stdio.h>
#include <stdlib.h>

typedef struct daylight {
    int hr;
    int min;
} daylight;

void create_daylight_pt_block(daylight ***p_p_d, int *data, int n) {
    *p_p_d = (daylight **)malloc(n * sizeof(daylight*));
    
    for (int i = 0; i < n; i++) {
        (*p_p_d)[i] = (daylight *)malloc(sizeof(daylight));
        (*p_p_d)[i]->hr = data[i * 2];
        (*p_p_d)[i]->min = data[i * 2 + 1];
    }
}

int main()
{
    int data[] = {11, 29, 12, 9};
    daylight **p_d;
    create_daylight_pt_block(&p_d, data, 2);
    for (int i = 0; i < 2; i++) {
        printf("%d - %d hrs %d min\n", i, p_d[i]->hr, p_d[i]->min);
    }
}

