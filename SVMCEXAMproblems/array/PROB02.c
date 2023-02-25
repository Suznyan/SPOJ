#include <stdio.h>
#include <stdlib.h>

int *typeCount(char **images, int imagesSize, int *imagesColSize,
               int *returnSize) {
    int *res = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        res[i] = 0;
    }
    *returnSize = 5;

    for (int r = 1; r < 5 * imagesSize + 1; r += 5) {
        for (int c = 1; c < 5 * (*imagesColSize) + 1; c += 5) {
            int starCount = 0;
            for (int i = 0; i < 4; i++) {
                if (images[r + i][c] == '.') break;
                starCount++;
            }

            switch (starCount) {
                case 0:
                    res[starCount]++;
                    break;
                case 1:
                    res[starCount]++;
                    break;
                case 2:
                    res[starCount]++;
                    break;
                case 3:
                    res[starCount]++;
                    break;
                case 4:
                    res[starCount]++;
                    break;
                default:
                    break;
            }
        }
    }
    return res;
}

int main() {
    char **images;
    int row, col;
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d ", &row, &col);
        images = malloc((5 * row + 1) * sizeof *images);
        for (int i = 0; i < 5 * row + 1; i++) {
            images[i] = malloc((5 * col + 1) * sizeof **images);
        }
        for (int r = 0; r < (5 * row + 1); r++) {
            for (int c = 0; c < (5 * col + 1); c++) {
                scanf(" %c", &images[r][c]);
            }
        }

        int returnSize;
        int *ans = typeCount(images, row, &col, &returnSize);
        printf("#%d ", tc);
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        free(ans);
    }
    return 0;
}