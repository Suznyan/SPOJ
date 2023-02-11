#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int M, N;
        scanf("%d %d", &M, &N);
        int row = 5 * M + 1;
        int col = 5 * N + 1;
        char arr[row][col];
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                scanf(" %c", &arr[r][c]);
            }
        }

        // compute
        int type1 = 0, type2 = 0, type3 = 0, type4 = 0, type5 = 0;

        for (int CurrentWindowR = 1; CurrentWindowR < row;
             CurrentWindowR += 5) {
            for (int CurrentWindowC = 1; CurrentWindowC < col;
                 CurrentWindowC += 5) {
                int star_Count = 0;

                for (int R_Windex = CurrentWindowR;
                     R_Windex <= 4 + CurrentWindowR; R_Windex++) {
                    if (arr[R_Windex][CurrentWindowC] == '.') break;

                    if (arr[R_Windex][CurrentWindowC] == '*') star_Count++;
                }

                switch (star_Count) {
                    case 0:
                        type1++;
                        break;

                    case 1:
                        type2++;
                        break;

                    case 2:
                        type3++;
                        break;

                    case 3:
                        type4++;
                        break;

                    case 4:
                        type5++;
                        break;

                    default:
                        break;
                }
            }
        }

        printf("#%d %d %d %d %d %d\n", tc, type1, type2, type3, type4, type5);
    }

    return 0;
}