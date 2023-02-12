#include <stdio.h>
#include <stdlib.h>

const int R_path[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
const int C_path[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

int check(int num, int len) {
    if (len < 4) return 0;
    int map[3][3];
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            map[r][c] = 0;
        }
    }

    int preR = R_path[(num % 10) - 1];
    int preC = C_path[(num % 10) - 1];
    map[preR][preC] = 1;
    num /= 10;

    while (num > 0) {
        int next = num % 10;

        int R = R_path[next - 1];
        int C = C_path[next - 1];

        if (abs(R - preR) == 2 && C == preC && map[1][C] == 0) return 0;
        if (abs(C - preC) == 2 && R == preR && map[R][1] == 0) return 0;
        if (abs(R - preR) == 2 && abs(C - preC) == 2 && map[1][1] == 0)
            return 0;

        if (map[R][C] == 1) return 0;
        map[R][C] = 1;
        preR = R;
        preC = C;

        num /= 10;
    }
    return 1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int pattern_count;
        scanf("%d", &pattern_count);

        int arr[pattern_count];
        int ans[pattern_count];

        for (int i = 0; i < pattern_count; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < pattern_count; i++) {
            ans[i] = 1;
        }

        // Compute
        for (int i = 0; i < pattern_count; i++) {
            if (arr[i] < 4) ans[i] = 0;

            int inv = 0;
            int len = 0;
            while (arr[i] > 0) {
                inv *= 10;
                inv += (arr[i] % 10);
                arr[i] /= 10;
                len++;
            }
            ans[i] = check(inv, len);
        }

        printf("#%d ", tc);
        for (int i = 0; i < pattern_count; i++) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}