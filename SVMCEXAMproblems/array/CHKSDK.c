#include <stdio.h>
#include <stdlib.h>

int isSudokuValid(char **board) {
    int row[9][9];
    int col[9][9];
    int square[9][9];
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            row[r][c] = 0;
            col[r][c] = 0;
            square[r][c] = 0;
        }
    }

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') continue;

            int val = board[r][c] - '0' - 1;
            int area = (r / 3) * 3 + (c / 3);

            if (row[val][r] || col[val][c] || square[val][area]) return 0;

            row[val][r] = 1;
            col[val][c] = 1;
            square[val][area] = 1;
        }
    }
    return 1;
}

int main() {
    char **board = malloc(9 * sizeof *board);
    for (int i = 0; i < 9; i++) {
        board[i] = malloc(9 * sizeof **board);
    }
    int T;
    scanf("%d ", &T);
    for (int tc = 1; tc <= T; tc++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf(" %c", &board[i][j]);
            }
        }
        printf("#%d %d\n", tc, isSudokuValid(board));
    }

    return 0;
}