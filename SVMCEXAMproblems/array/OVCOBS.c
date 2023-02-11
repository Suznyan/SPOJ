#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int n, x, y, ans = 0;
        scanf("%d %d %d", &n, &x, &y);
        int matrix[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d ", &matrix[i][j]);
            }
        }

        int i_Route[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int j_Route[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (;;) {
            int sastified_num = 1001, new_x = -1, new_y = -1;
            for (int i = 0; i < 8; i++) {
                if (x + i_Route[i] < 0 || y + j_Route[i] < 0) continue;

                if (matrix[x + i_Route[i]][y + j_Route[i]] > matrix[x][y] &&
                    matrix[x + i_Route[i]][y + j_Route[i]] < sastified_num) {
                    sastified_num = matrix[x + i_Route[i]][y + j_Route[i]];
                    new_x = x + i_Route[i];
                    new_y = y + j_Route[i];
                }
            }

            if (new_x != -1 && new_y != -1) {
                x = new_x;
                y = new_y;
                ans++;
            }else break;
        }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}