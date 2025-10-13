#include <stdio.h>

long long factorial(int n) {
    long long f = 1;
    int i = n;
    while (i > 1) {
        f *= i;
        i--;
    }
    return f;
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Error: n must be >= 0\n");
    } else {
        printf("Factorial of %d is %lld\n", n, factorial(n));
    }

    return 0;
}
