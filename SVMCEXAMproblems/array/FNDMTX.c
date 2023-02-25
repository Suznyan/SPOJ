#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int *satisfiedMatrixStartPoint(int **matrix, int matrixSize, int subMatrixSize,
                               int k) {
    int *res = malloc(2 * sizeof(int));
    int diff = INT_MAX, smallestSatisfiedSum = INT_MAX;
    for (int i = 0; i < matrixSize - subMatrixSize + 1; i++) {
        for (int j = 0; j < matrixSize - subMatrixSize + 1; j++) {
            int SubSum = 0;
            for (int g = i; g < subMatrixSize + i; g++) {
                for (int h = j; h < subMatrixSize + j; h++) {
                    SubSum += matrix[g][h];
                }
            }
            int currDiff = abs(k - SubSum);
            if (currDiff > diff) continue;
            if (currDiff == diff && SubSum >= smallestSatisfiedSum) continue;
            diff = currDiff;
            smallestSatisfiedSum = SubSum;
            res[0] = i;
            res[1] = j;
        }
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        int **matrix = malloc(N * sizeof *matrix);
        for (int i = 0; i < N; i++) {
            matrix[i] = malloc(N * sizeof **matrix);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int *location = satisfiedMatrixStartPoint(matrix, N, M, K);

        printf("#%d %d %d\n", tc, location[0], location[1]);
        free(location);
        location = NULL;
    }
    return 0;
}