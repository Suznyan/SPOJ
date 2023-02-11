#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int x, y;
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        int arr[N][N];

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                scanf("%d", &arr[r][c]);
            }
        }

        int smallest_different = 1000 ^ 99, smallest_sum = 1000 ^ 99;

        for (int r = 0; r < N - M + 1; r++) {
            for (int c = 0; c < N - M + 1; c++) {
                int sum = 0;
                for (int i = r; i < (M + r); i++) {
                    for (int j = c; j < (M + c); j++) {
                        sum += arr[i][j];
                    }
                }

                int different = K - sum;
                if (different < 0) different = 0 - different;
                if (r == 0 && c == 0 || different < smallest_different ||
                    different == smallest_different && sum < smallest_sum) {
                    smallest_sum = sum;
                    x = r;
                    y = c;
                    smallest_different = different;
                }
            }
        }

        printf("#%d %d %d\n", tc, x, y);
    }
    return 0;
}