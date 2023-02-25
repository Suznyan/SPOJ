#include <stdio.h>
#include <stdlib.h>

int isSymmetric(int **matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        int *L = *(matrix + i), *R = *(matrix + i) + matrixSize - 1;
        while (L <= R) {
            if (*L != *R) return 1;
            L++, R--;
        }
        for (int j = 0; j <= matrixSize / 2; j++) {
            int *top = *(matrix + j) + i,
                *bottom = *(matrix + matrixSize - 1 - j) + i;
            if (*top != *bottom) return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int size;
        scanf("%d", &size);
        int **matrix = malloc(size * sizeof *matrix);
        for (int i = 0; i < size; i++) {
            matrix[i] = malloc(size * sizeof **matrix);
        }

        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                scanf("%d", &matrix[r][c]);
            }
        }
        printf("#%d ", tc);
        printf(isSymmetric(matrix, size) ? "NO\n" : "YES\n");
    }
    return 0;
}