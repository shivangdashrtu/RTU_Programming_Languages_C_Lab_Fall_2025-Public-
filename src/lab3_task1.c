/*
Shivang Dash
231ADB209
File: lab3_task1.c
Desc: Array algorithms: min, max, sum, average
*/

#include <stdio.h>

/* Prototypes */
int array_min(int arr[], int size);
int array_max(int arr[], int size);
int array_sum(int arr[], int size);
float array_avg(int arr[], int size);

int array_min(int arr[], int size) {
    if (size <= 0) return 0;
    int m = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < m) m = arr[i];
    }
    return m;
}

int array_max(int arr[], int size) {
    if (size <= 0) return 0;
    int m = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

int array_sum(int arr[], int size) {
    int s = 0;
    for (int i = 0; i < size; i++) s += arr[i];
    return s;
}

float array_avg(int arr[], int size) {
    if (size <= 0) return 0.0f;
    return (float)array_sum(arr, size) / (float)size;
}

int main(void) {
    int arr[] = {10, 20, 5, 30, 15};
    int n = (int)(sizeof(arr)/sizeof(arr[0]));
    printf("Min: %d\n", array_min(arr, n));
    printf("Max: %d\n", array_max(arr, n));
    printf("Sum: %d\n", array_sum(arr, n));
    printf("Avg: %.2f\n", array_avg(arr, n));
    return 0;
}
