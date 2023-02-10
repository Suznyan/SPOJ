#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int ans = 0;
        int H, W, M, N;
        scanf("%d %d %d %d", &H, &W, &M, &N);

        int arr[M][N];
        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                scanf("%d", &arr[r][c]);
            }
        }

        for (int r = 0; r < M - H + 1; r++) {
            for (int c = 0; c < N - W + 1; c++) {
                int sum = 0;

                for (int horizontal = c; horizontal < c + W; horizontal++) {
                    if (arr[r][horizontal] % 2 == 0) sum += arr[r][horizontal];
                    if (arr[r + H - 1][horizontal] % 2 == 0)
                        sum += arr[r + H - 1][horizontal];
                }

                for (int vertical = r + 1; vertical < r + H - 1; vertical++) {
                    if (arr[vertical][c] % 2 == 0) sum += arr[vertical][c];
                    if (arr[vertical][c + W - 1] % 2 == 0)
                        sum += arr[vertical][c + W - 1];
                }

                if (sum > ans) ans = sum;
            }
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}