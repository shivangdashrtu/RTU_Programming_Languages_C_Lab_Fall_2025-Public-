/*
Shivang Dash
231ADB209
File: src/week4_1_dynamic_array.c
Desc: Dynamic array with malloc, sum and average, free memory
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid count.\n");
        return 1;
    }

    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Input error.\n");
            free(arr);
            return 1;
        }
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    double avg = (n > 0) ? (double)sum / (double)n : 0.0;

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", avg);

    free(arr);
    return 0;
}
