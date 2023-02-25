#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }
int firstDup(int *nums, int numsSize) {
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        maxNum = max(maxNum, nums[i]);
    }
    int *count = malloc((maxNum + 1) * sizeof(int));
    for (int i = 0; i <= maxNum; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < numsSize; i++) {
        if (count[nums[i]] >= 1) {
            free(count);
            count = NULL;
            return nums[i];
        } else
            count[nums[i]]++;
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int size;
        scanf("%d", &size);
        int *nums = malloc(size * sizeof *nums);
        for (int i = 0; i < size; i++) {
            scanf("%d", &nums[i]);
        }

        printf("#%d %d\n", tc, firstDup(nums, size));
    }
    return 0;
}