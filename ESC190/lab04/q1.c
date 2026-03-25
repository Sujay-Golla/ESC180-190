#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 4;
    int b[5] = {1, 2, 3, 4, 5};

    printf("Value of a: %d\n", a);
    // printf("undefined behavior: %d\n", b[100000000000]);

    FILE *file = fopen("a.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    fclose(file);
}