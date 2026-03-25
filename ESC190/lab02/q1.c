#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void set_even_to_zero(int *arr, int size) 
{
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            arr[i] = 0;
        }
    }
}

void str_cat_1(char *dest, char *src) 
{
    int dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}

void str_cat_2(char *dest, char *src) 
{
    char *d = dest;
    while (*d != '\0') {
        d++;
    }
    while (*src != '\0') {
        *d = *src;
        d++;
        src++;
    }
    *d = '\0';
}

int my_strcmp_rec(const char *str1, const char *str2)
{
    if (*str1 != *str2)
    {
        return *str1 - *str2;
    }
    if (*str1 == '\0' && *str2 == '\0')
    {
        return 0;
    }

    return my_strcmp_rec(str1 + 1, str2 + 1);
}

int my_atoi(char *str)
{
    int res = 0;
    int mult = 1;
    int len = 0;

    while (*str != '\0')
    {
        len++;
        str++;
    }
    str--;
    while (len >= 0)
    {
        if (isdigit(*str))
        {
            res += (*str - '0') * mult;
            mult *= 10;
        }
        str--;
        len--;
    }

    return res;
}

int main()
{
    // Q1
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    set_even_to_zero(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    // Q2
    char dest1[50] = "This is ";
    char src1[] = "programiz.com";
    str_cat_1(dest1, src1);
    printf("%s\n", dest1);
    char dest2[50] = "This is also ";
    char src2[] = "programiz.com";
    str_cat_2(dest2, src2);
    printf("%s\n", dest2);

    // Q3
    char *str1 = "[...]";
    char *str2 = "[...]";
    printf("Comparing strings: %d\n", my_strcmp_rec(str1, str2));

    // Q5
    char *str = "1234absc8923";
    printf("atoi result: %d\n", my_atoi(str));
}