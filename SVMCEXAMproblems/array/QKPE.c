#include <stdio.h>
#include <stdlib.h>

int remainingSafeSquare(int **board, int boardSize, int *boardColSize,
                        int **queens, int queenCount, int **knights,
                        int knightCount, int **pawns, int pawnCount) {
    int res =
        boardSize * (*boardColSize) - queenCount - knightCount - pawnCount;

    /*
    -------|i-2,j-1|-----|i-2,j+1|-------
    i-1,j-2|-------|-----|-------|i-1,j+2
    -------|-------| i,j |-------|-------
    i+1,j-2|-------|-----|-------|i+1,j+2
    -------|i+2,j-1|-----|i+2,j+1|-------
    */
    int knightMoves[8][2] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                             {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};  // R-C
    for (int i = 0; i < knightCount; i++) {
        for (int k = 0; k < 8; k++) {
            int R = knights[i][0] - 1 + knightMoves[k][0];
            int C = knights[i][1] - 1 + knightMoves[k][1];
            if (R >= boardSize || C >= *boardColSize || R < 0 || C < 0 ||
                board[R][C] != 0)
                continue;

            res--;
            board[R][C] = -1;
        }
    }

    /*
    i-1,j-1|i-1,j |i-1,j+1
    i,j-1  | i,j  |i,j+1
    i+1,j-1|i+1,j |i+1,j+1
    */
    int queenMoves[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                            {1, 0},  {1, -1}, {0, -1}, {-1, -1}};  // R-C
    for (int i = 0; i < queenCount; i++) {
        for (int q = 0; q < 8; q++) {
            int R = queens[i][0] - 1 + queenMoves[q][0];
            int C = queens[i][1] - 1 + queenMoves[q][1];
            while (R < boardSize && C < *boardColSize && R >= 0 && C >= 0 &&
                   board[R][C] != 1) {
                if (board[R][C] == 0) {
                    res--;
                    board[R][C] = -1;
                }
                R += queenMoves[q][0];
                C += queenMoves[q][1];
            }
        }
    }
    return res;
}

int main() {
    for (int tc = 1; tc; tc++) {
        int row, col;
        scanf("%d %d", &row, &col);
        if (row == 0 && col == 0) break;
        // row++, col++;
        int **board = malloc(row * sizeof *board);
        for (int i = 0; i < row; i++) {
            board[i] = malloc(col * sizeof **board);
        }

        // Clear the board
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                board[r][c] = 0;
            }
        }

        int queenCount, knightCount, pawnCount;
        scanf("%d", &queenCount);
        int **queens = malloc(queenCount * sizeof *queens);
        for (int i = 0; i < queenCount; i++) {
            queens[i] = malloc(2 * sizeof **queens);
        }
        for (int i = 0; i < queenCount; i++) {
            scanf("%d %d", &queens[i][0], &queens[i][1]);
            board[queens[i][0] - 1][queens[i][1] - 1] = 1;
        }

        scanf("%d", &knightCount);
        int **knights = malloc(knightCount * sizeof *knights);
        for (int i = 0; i < knightCount; i++) {
            knights[i] = malloc(2 * sizeof **knights);
        }
        for (int i = 0; i < knightCount; i++) {
            scanf("%d %d", &knights[i][0], &knights[i][1]);
            board[knights[i][0] - 1][knights[i][1] - 1] = 1;
        }

        scanf("%d", &pawnCount);
        int **pawns = malloc(pawnCount * sizeof *pawns);
        for (int i = 0; i < pawnCount; i++) {
            pawns[i] = malloc(2 * sizeof **pawns);
        }
        for (int i = 0; i < pawnCount; i++) {
            scanf("%d %d", &pawns[i][0], &pawns[i][1]);
            board[pawns[i][0] - 1][pawns[i][1] - 1] = 1;
        }

        int ans = remainingSafeSquare(board, row, &col, queens, queenCount,
                                      knights, knightCount, pawns, pawnCount);

        printf("Board %d has %d safe squares.\n", tc, ans);
        free(board);
        free(queens);
        free(knights);
        free(pawns);
        board = NULL;
        queens = NULL;
        knights = NULL;
        pawns = NULL;
    }

    return 0;
}