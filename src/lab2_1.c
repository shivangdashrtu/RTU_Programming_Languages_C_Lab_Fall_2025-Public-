int sum_to_n(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

#include <stdio.h>

int sum_to_n(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n must be >= 1\n");
    } else {
        printf("Sum from 1 to %d = %d\n", n, sum_to_n(n));
    }

    return 0;
}
