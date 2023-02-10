#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int flag = 0;
        int N;
        scanf("%d", &N);
        int Matrix[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d ", &Matrix[i][j]);
            }
        }

        // Compare on X-axis
        for (int i = 0; i < N; i++) {
            if (flag == 1) break;
            for (int j = 0; j < N / 2; j++) {
                if (Matrix[i][j] == Matrix[i][(N - 1) - j])
                    continue;
                else {
                    flag = 1;
                    break;
                }
            }
        }

        // Compare on Y-axis
        if (flag == 0)
            for (int j = 0; j < N; j++) {
                if (flag == 1) break;
                for (int i = 0; i < N / 2; i++) {
                    if (Matrix[i][j] == Matrix[(N - 1) - i][j])
                        continue;
                    else {
                        flag = 1;
                        break;
                    }
                }
            }

        printf("#%d %s\n", tc, flag == 0 ? "YES" : "NO");
    }

    return 0;
}