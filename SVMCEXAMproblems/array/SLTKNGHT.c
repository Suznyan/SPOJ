#include <stdio.h>
#include <stdlib.h>
int *selectedKnight(int **board, int boardSize, int **knights, int knightsCount,
                    int *numberOfPiecesTaken) {
    int knightMoves[8][2] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                             {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    int *res = malloc(2 * sizeof(int));
    int piecesCount = 0;
    for (int k = 0; k < knightsCount; k++) {
        int currPiecesCount = 0;
        for (int i = 0; i < 8; i++) {
            int R = knights[k][0] + knightMoves[i][0];
            int C = knights[k][1] + knightMoves[i][1];

            if (R < 0 || C < 0 || R >= boardSize ||
                C >= boardSize || board[R][C] != 1)
                continue;

            currPiecesCount++;
        }
        if (currPiecesCount <= piecesCount) continue;
        piecesCount = currPiecesCount;
        res[0] = knights[k][0];
        res[1] = knights[k][1];
    }
    *numberOfPiecesTaken = piecesCount;
    return res;
}

int main() {
    int **knights, **pawns, **NAs, **board;
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int boardSize, knightsCount, pawnsCount, NACount;
        scanf("%d %d %d %d", &boardSize, &knightsCount, &pawnsCount, &NACount);
        knights = malloc(knightsCount * sizeof *knights);
        for (int i = 0; i < knightsCount; i++) {
            knights[i] = malloc(2 * sizeof **knights);
        }
        pawns = malloc(pawnsCount * sizeof *pawns);
        for (int i = 0; i < pawnsCount; i++) {
            pawns[i] = malloc(2 * sizeof **pawns);
        }
        NAs = malloc(NACount * sizeof *NAs);
        for (int i = 0; i < NACount; i++) {
            NAs[i] = malloc(2 * sizeof **NAs);
        }
        board = malloc(boardSize * sizeof *board);
        for (int i = 0; i < boardSize; i++) {
            board[i] = malloc(boardSize * sizeof **board);
        }

        for (int r = 0; r < boardSize; r++) {
            for (int c = 0; c < boardSize; c++) {
                board[r][c] = 0;
            }
        }

        for (int i = 0; i < knightsCount; i++) {
            scanf("%d %d", &knights[i][0], &knights[i][1]);
            board[knights[i][0]][knights[i][1]] = 1;
        }

        for (int i = 0; i < pawnsCount; i++) {
            scanf("%d %d", &pawns[i][0], &pawns[i][1]);
            board[pawns[i][0]][pawns[i][1]] = 1;
        }

        for (int i = 0; i < NACount; i++) {
            scanf("%d %d", &NAs[i][0], &NAs[i][1]);
            board[NAs[i][0]][NAs[i][1]] = 2;
        }

        int piecesTaken = 0;
        int *ans = selectedKnight(board, boardSize, knights, knightsCount,
                                  &piecesTaken);
        printf("#%d %d %d %d\n", tc, ans[0], ans[1], piecesTaken);
        free(ans);
        ans = NULL;
        free(knights);
        free(pawns);
        free(NAs);
        free(board);
    }
    return 0;
}