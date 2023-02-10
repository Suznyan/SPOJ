#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = a;
        for (int i = 0; i < b - 1; i++) {
            ans *= a;
        }
        printf("#%d %d\n", tc, ans);
    }

    return 0;
}