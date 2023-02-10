#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int a) {
    if (a <= 1) return false;    
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int m = 0, n = 0;
        scanf("%d%d", &m, &n);
        for (int i = m; i <= n; i++) {
            if (isPrime(i)) printf("%d\n", i);
        }
        printf("\n");
    }

    return 0;
}
