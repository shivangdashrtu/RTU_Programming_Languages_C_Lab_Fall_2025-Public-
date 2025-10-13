#include <stdio.h>

int is_prime(int x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    for (int d = 3; d * d <= x; d += 2) {
        if (x % d == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter upper limit: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Error: must be >= 2\n");
    } else {
        printf("Prime numbers up to %d:\n", n);
        for (int k = 2; k <= n; k++) {
            if (is_prime(k)) {
                printf("%d ", k);
            }
        }
        printf("\n");
    }

    return 0;
}
