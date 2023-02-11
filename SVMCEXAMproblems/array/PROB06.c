#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int m, n;
        int ans = 0;
        scanf("%d %d", &m, &n);

        char map[m][n];
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                scanf(" %c", &map[r][c]);
                if (map[r][c] == 'H') ans++;
            }
        }

        int Ai[4] = {-1, 0, 1, 0};
        int Aj[4] = {0, 1, 0, -1};

        int Bi[8] = {-1, 0, 1, 0, -2, 0, 2, 0};
        int Bj[8] = {0, 1, 0, -1, 0, 2, 0, -2};

        int Ci[12] = {-1, 0, 1, 0, -2, 0, 2, 0, -3, 0, 3, 0};
        int Cj[12] = {0, 1, 0, -1, 0, 2, 0, -2, 0, 3, 0, -3};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (map[r][c] == 'A') {
                    for (int i = 0; i < 4; i++) {
                        if (r + Ai[i] < 0 || c + Aj[i] < 0 || r + Ai[i] >= m ||
                            c + Aj[i] >= n)
                            continue;
                        if (map[r + Ai[i]][c + Aj[i]] == 'H') {
                            map[r + Ai[i]][c + Aj[i]] = 'x';
                            ans--;
                        } else
                            continue;
                    }
                } else if (map[r][c] == 'B') {
                    for (int i = 0; i < 8; i++) {
                        if (r + Bi[i] < 0 || c + Bj[i] < 0 || r + Bi[i] >= m ||
                            c + Bj[i] >= n)
                            continue;
                        if (map[r + Bi[i]][c + Bj[i]] == 'H') {
                            map[r + Bi[i]][c + Bj[i]] = 'x';
                            ans--;
                        } else
                            continue;
                    }
                } else if (map[r][c] == 'C') {
                    for (int i = 0; i < 12; i++) {
                        if (r + Ci[i] < 0 || c + Cj[i] < 0 || r + Ci[i] >= m ||
                            c + Cj[i] >= n)
                            continue;
                        if (map[r + Ci[i]][c + Cj[i]] == 'H') {
                            map[r + Ci[i]][c + Cj[i]] = 'x';
                            ans--;
                        } else
                            continue;
                    }
                } else
                    continue;
            }
        }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}