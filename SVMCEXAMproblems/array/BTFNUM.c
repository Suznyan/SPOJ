#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int ans = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        int NiceNumTable[n];

        for (int i = 0; i < n; i++) {
            scanf("%d ", &NiceNumTable[i]);
        }

        int start, finish;
        scanf("%d %d", &start, &finish);

        for (int i = start; i <= finish; i++) {
            int temp = i;
            int count = 0;
            if (i < m) continue;

            while (temp > 0) {
                int digit = temp % 10;
                temp /= 10;
                for (int NiceNumIndex = 0; NiceNumIndex < n; NiceNumIndex++) {
                    if (digit == NiceNumTable[NiceNumIndex]) count++;
                }
            }
            if (count >= m) ans++;
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}