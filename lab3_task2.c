/*
Shivang Dash
231ADB209
File: lab3_task2.c
Desc: Pointers as function parameters (swap, modify)
*/

#include <stdio.h>

/* Prototypes */
void swap(int *x, int *y);
void modify_value(int *x);

void swap(int *x, int *y) {
    if (!x || !y) return;
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void modify_value(int *x) {
    if (!x) return;
    *x *= 2;
}

int main(void) {
    int a = 3, b = 7;
    printf("Before swap: a=%d, b=%d\n", a, b);
    swap(&a, &b);
    printf("After swap: a=%d, b=%d\n", a, b);
    modify_value(&a);
    printf("After modify_value: a=%d\n", a);
    return 0;
}
