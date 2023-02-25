#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }
int maxArea(int **matrix, int matrixSize, int *matrixColSize, int width,
            int height) {
    int res = 0;
    for (int r = 0; r < matrixSize - height + 1; r++) {
        for (int c = 0; c < *matrixColSize - width + 1; c++) {
            int sum = 0;

            int top = r, bottom = height + r - 1;
            for (int i = c; i < width + c; i++) {
                if (matrix[top][i] % 2 == 0) sum += matrix[top][i];
                if (matrix[bottom][i] % 2 == 0) sum += matrix[bottom][i];
            }
            top++, bottom--;

            for (int i = top; i <= bottom; i++) {
                if (matrix[i][c] % 2 == 0) sum += matrix[i][c];
                if (matrix[i][c + width - 1] % 2 == 0)
                    sum += matrix[i][c + width - 1];
            }

            res = max(res, sum);
        }
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int row, col, width, height;
        scanf("%d %d %d %d", &height, &width, &row, &col);
        int **matrix = malloc(row * sizeof *matrix);
        for (int i = 0; i < row; i++) {
            matrix[i] = malloc(col * sizeof **matrix);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int ans = maxArea(matrix, row, &col, width, height);

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}