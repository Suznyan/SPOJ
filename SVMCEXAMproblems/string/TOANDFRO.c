#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    for (int tc = 1; tc; tc++) {
        int col;
        scanf(" %d ", &col);
        if (col == 0) break;
        char string[200];
        scanf(" %s ", &string);

        int row = strlen(string) / col;
        char rearrange[row][col];

        int idx = 0;
        while (string[idx] != '\0')
            for (int r = 0; r < row; r++) {
                if (r % 2 == 0)
                    for (int c = 0; c < col; c++) {
                        rearrange[r][c] = string[idx++];
                    }
                else
                    for (int c = col - 1; c >= 0; c--) {
                        rearrange[r][c] = string[idx++];
                    }
            }

        idx = 0;
        for (int c = 0; c < col; c++) {
            for (int r = 0; r < row; r++) {
                string[idx++] = rearrange[r][c];
            }
        }

        printf("%s\n", string);
    }
    return 0;
}