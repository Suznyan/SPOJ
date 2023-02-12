#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int row, col;
        scanf("%d %d", &row, &col);

        int a[row][col];
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                a[r][c] = 0;
            }
        }

        int r_path[] = {0, 1, 0, -1};
        int c_path[] = {1, 0, -1, 0};
        int num = 1;
        a[0][0] = num;
        int R = 0, C = 0, d = 0;
        while (num < row * col) {
            int nextR = R + r_path[d];
            int nextC = C + c_path[d];

            if (nextR < row && nextC < col && nextR >= 0 && nextC >= 0 &&
                a[nextR][nextC] == 0) {
                a[nextR][nextC] = ++num;
                R = nextR;
                C = nextC;
            } else
                d = (d + 1) % 4;
        }

        printf("#%d\n", tc);
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                printf("%d ", a[r][c]);
            }
            printf("\n");
        }
    }
    return 0;
}