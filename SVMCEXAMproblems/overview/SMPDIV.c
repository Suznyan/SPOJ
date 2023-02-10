#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc++) {
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        for (int i = 1; i < n; i++) {
            if (i % x == 0 && i % y != 0)
                printf("%d ", i);
            else
                continue;
        }
        printf("\n");
    }
    return 0;
}