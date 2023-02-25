#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int obstaclePassed(int **nums, int numsSize, int x, int y) {
    int moves[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                       {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

    int res = 0;
    for (;;) {
        int smallest = INT_MAX;
        int tempx = -1, tempy;
        for (int i = 0; i < 8; i++) {
            int R = x + moves[i][0];
            int C = y + moves[i][1];
            if (R >= numsSize || C >= numsSize || R < 0 || C < 0 ||
                nums[R][C] <= nums[x][y] || nums[R][C] >= smallest)
                continue;
            smallest = nums[R][C];
            tempx = R;
            tempy = C;
        }
        if (tempx == -1) return res;
        x = tempx;
        y = tempy;
        res++;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    int **nums;
    for (int tc = 1; tc <= T; tc++) {
        int size, x, y;
        scanf("%d %d %d", &size, &x, &y);
        nums = malloc(size * sizeof *nums);
        for (int i = 0; i < size; i++) {
            nums[i] = malloc(size * sizeof **nums);
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                scanf("%d", &nums[i][j]);
            }
        }
        printf("#%d %d\n", tc, obstaclePassed(nums, size, x, y));
        free(nums);
    }
    return 0;
}