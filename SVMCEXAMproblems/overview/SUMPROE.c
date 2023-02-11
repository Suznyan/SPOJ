#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {
        int num;
        long ans = 0;
        scanf("%d", &num);
        for (int i = 1; i <= num; i++) {
            ans += i * (num / i);
        }
        printf("%d\n", ans % 1000007);
    }

    return 0;
}