#include <stdio.h>
#include <stdlib.h>

void f(int *p) {
    *p = 42;
}

int sum_odd(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void g(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
}

int main() {
    // Part a
    int a = 0;
    int *p = &a;
    f(p);

    // Part b
    int arr[] = {4,3,2,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", sum_odd(arr, n));

    // Part c
    int arrc[] = {4,2,3};
    int nc = sizeof(arrc) / sizeof(arrc[0]);
    g(arrc, nc);
}