#include <stdio.h>

int sum_to_n(int n) {
    int sum = 0, i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }
    return sum;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n < 1) {
        printf("Error: n must be >= 1\n");
    } else {
        int result = sum_to_n(n);
        printf("The total from 1 to %d is %d\n", n, result);
    }

    return 0;
}
