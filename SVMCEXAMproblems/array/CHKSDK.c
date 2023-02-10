#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool SudokuCheck(char board[9][9], int boardSize) {
    bool row[boardSize][boardSize];
    bool col[boardSize][boardSize];
    bool square[boardSize][boardSize];

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            row[boardSize][boardSize] = false;
            col[boardSize][boardSize] = false;
            square[boardSize][boardSize] = false;
        }
    }

    for (int r = 0; r < boardSize; r++) {
        for (int c = 0; c < boardSize; c++) {
            if (board[r][c] == '.') continue;

            int ValueChecking = board[r][c] - '0' - 1;
            int area = (r / 3) * 3 + (c / 3);

            if (row[ValueChecking][r] || col[ValueChecking][c] ||
                square[ValueChecking][area])
                return false;

            row[ValueChecking][r] = true;
            col[ValueChecking][c] = true;
            square[ValueChecking][area] = true;
        }
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        char board[9][9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                board[i][j] = 0;
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf(" %c", &board[i][j]);
            }
        }

        bool ans = SudokuCheck(board, 9);

        printf("#%d %d\n", tc, ans ? 1 : 0);
    }

    return 0;
}