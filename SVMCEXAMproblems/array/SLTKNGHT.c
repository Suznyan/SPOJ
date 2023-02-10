#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int N, K, M, D;
        scanf("%d %d %d %d", &N, &K, &M, &D);

        int board[N][N];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                board[r][c] = 0;
            }
        }

        int knight[K][2];
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &knight[i][0], &knight[i][1]);
            board[knight[i][0]][knight[i][1]] = 2;
        }

        int pawn[M][2];
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &pawn[i][0], &pawn[i][1]);
            board[pawn[i][0]][pawn[i][1]] = 1;
        }

        int NotAllowed[D][2];
        for (int i = 0; i < D; i++) {
            scanf("%d %d", &NotAllowed[i][0], &NotAllowed[i][1]);
            board[NotAllowed[i][0]][NotAllowed[i][1]] = -1;
        }

        int x = 0, y = 0, count = 0;

        int K_Rpath[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int K_Cpath[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int i = 0; i < K; i++) {
            int temp = 0;
            for (int j = 0; j < 8; j++) {
                if (knight[i][0] + K_Rpath[j] < 0 ||
                    knight[i][1] + K_Cpath[j] < 0 ||
                    knight[i][0] + K_Rpath[j] >= N ||
                    knight[i][1] + K_Cpath[j] >= N)
                    continue;

                if (board[knight[i][0] + K_Rpath[j]]
                         [knight[i][1] + K_Cpath[j]] > 0) {
                    temp++;
                }
            }
            if (temp > count) {
                count = temp;
                x = knight[i][0];
                y = knight[i][1];
            } 
        }
        printf("#%d %d %d %d\n", tc, x, y, count);
    }
    return 0;
}