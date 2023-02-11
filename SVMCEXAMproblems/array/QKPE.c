#include <stdio.h>
#include <stdlib.h>

int board[1000][1000];

int main() {
    for (int tc = 1; tc; tc++) {
        int row, col;
        scanf("%d %d", &row, &col);
        if (row == 0 && col == 0) break;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                board[r][c] = 0;
            }
        }

        int QueenCount;
        scanf("%d", &QueenCount);
        int queen[QueenCount][2];
        for (int i = 0; i < QueenCount; i++) {
            scanf("%d %d", &queen[i][0], &queen[i][1]);
            board[queen[i][0] - 1][queen[i][1] - 1] = 1;
        }

        int knightCount;
        scanf("%d", &knightCount);
        int knight[knightCount][2];
        for (int i = 0; i < knightCount; i++) {
            scanf("%d %d", &knight[i][0], &knight[i][1]);
            board[knight[i][0] - 1][knight[i][1] - 1] = 1;
        }

        int pawnCount;
        scanf("%d", &pawnCount);
        int pawn[pawnCount][2];
        for (int i = 0; i < pawnCount; i++) {
            scanf("%d %d", &pawn[i][0], &pawn[i][1]);
            board[pawn[i][0] - 1][pawn[i][1] - 1] = 1;
        }

        int K_Rpath[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int K_Cpath[] = {1, 2, 2, 1, -1, -2, -2, -1};

        int ans = (row * col) - QueenCount - knightCount - pawnCount;

        // Check Knights Paths
        for (int k_no = 0; k_no < knightCount; k_no++) {
            for (int i = 0; i < 8; i++) {
                if ((knight[k_no][0] - 1 + K_Rpath[i]) < 0 ||
                    (knight[k_no][1] - 1 + K_Cpath[i]) < 0 ||
                    knight[k_no][0] - 1 + K_Rpath[i] >= row ||
                    knight[k_no][1] - 1 + K_Cpath[i] >= col)
                    continue;

                if ((board[knight[k_no][0] - 1 + K_Rpath[i]]
                          [knight[k_no][1] - 1 + K_Cpath[i]]) != 1 &&
                    board[knight[k_no][0] - 1 + K_Rpath[i]]
                         [knight[k_no][1] - 1 + K_Cpath[i]] != 2) {
                    board[knight[k_no][0] - 1 + K_Rpath[i]]
                         [knight[k_no][1] - 1 + K_Cpath[i]] = 2;
                    ans--;
                }
            }
        }

        // Check Queens Paths
        for (int q_no = 0; q_no < QueenCount; q_no++) {
            // Upper Right Diagonal
            int i = 1;
            while (board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1 + i] != 1) {
                if ((queen[q_no][0] - 1 - i) < 0 ||
                    (queen[q_no][1] - 1 + i) < 0 ||
                    (queen[q_no][0] - 1 - i) >= row ||
                    (queen[q_no][1] - 1 + i) >= col)
                    break;
                if (board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1 + i] ==
                    0) {
                    board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1 + i] = 2;
                    ans--;
                }
                i++;
            }

            // lower Right Diagonal
            i = 1;
            while (board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1 + i] != 1) {
                if ((queen[q_no][0] - 1 + i) < 0 ||
                    (queen[q_no][1] - 1 + i) < 0 ||
                    (queen[q_no][0] - 1 + i) >= row ||
                    (queen[q_no][1] - 1 + i) >= col)
                    break;

                if (board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1 + i] ==
                    0) {
                    board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1 + i] = 2;
                    ans--;
                }
                i++;
            }

            // Upper left Diagonal
            i = 1;
            while (board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1 - i] != 1) {
                if ((queen[q_no][0] - 1 - i) < 0 ||
                    (queen[q_no][1] - 1 - i) < 0 ||
                    (queen[q_no][0] - 1 - i) >= row ||
                    (queen[q_no][1] - 1 - i) >= col)
                    break;

                if (board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1 - i] ==
                    0) {
                    board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1 - i] = 2;
                    ans--;
                }
                i++;
            }

            // Lower Left Diagonal
            i = 1;
            while (board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1 - i] != 1) {
                if ((queen[q_no][0] - 1 + i) < 0 ||
                    (queen[q_no][1] - 1 - i) < 0 ||
                    (queen[q_no][0] - 1 + i) >= row ||
                    (queen[q_no][1] - 1 - i) >= col)
                    break;
                if (board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1 - i] ==
                    0) {
                    board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1 - i] = 2;
                    ans--;
                }
                i++;
            }

            // Up
            i = 1;
            while (board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1] != 1) {
                if ((queen[q_no][0] - 1 - i) < 0 || (queen[q_no][1] - 1) < 0 ||
                    (queen[q_no][0] - 1 - i) >= row ||
                    (queen[q_no][1] - 1) >= col)
                    break;
                if (board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1] == 0) {
                    board[queen[q_no][0] - 1 - i][queen[q_no][1] - 1] = 2;
                    ans--;
                }
                i++;
            }

            // Down
            i = 1;
            while (board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1] != 1) {
                if ((queen[q_no][0] - 1 + i) < 0 || (queen[q_no][1] - 1) < 0 ||
                    (queen[q_no][0] - 1 + i) >= row ||
                    (queen[q_no][1] - 1) >= col)
                    break;

                if (board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1] == 0) {
                    board[queen[q_no][0] - 1 + i][queen[q_no][1] - 1] = 2;
                    ans--;
                }
                i++;
            }

            // left
            i = 1;
            while (board[queen[q_no][0] - 1][queen[q_no][1] - 1 - i] != 1) {
                if ((queen[q_no][0] - 1) < 0 || (queen[q_no][1] - 1 - i) < 0 ||
                    (queen[q_no][0] - 1) >= row ||
                    (queen[q_no][1] - 1 - i) >= col)
                    break;

                if (board[queen[q_no][0] - 1][queen[q_no][1] - 1 - i] == 0) {
                    board[queen[q_no][0] - 1][queen[q_no][1] - 1 - i] = 2;
                    ans--;
                }
                i++;
            }

            // Right
            i = 1;
            while (board[queen[q_no][0] - 1][queen[q_no][1] - 1 + i] != 1) {
                if ((queen[q_no][0] - 1) < 0 || (queen[q_no][1] - 1 + i) < 0 ||
                    (queen[q_no][0] - 1) >= row ||
                    (queen[q_no][1] - 1 + i) >= col)
                    break;

                if (board[queen[q_no][0] - 1][queen[q_no][1] - 1 + i] == 0) {
                    board[queen[q_no][0] - 1][queen[q_no][1] - 1 + i] = 2;
                    ans--;
                }
                i++;
            }
        }

        printf("Board %d has %d safe squares.\n", tc, ans);
    }
    return 0;
}