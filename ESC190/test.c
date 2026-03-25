#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    char *str = "hello world";
    char *str2 = "helAhahaha";
    int res = strncmp(str, str2, 3);
    printf("%d\n", res);
}