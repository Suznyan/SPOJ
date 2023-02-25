#include <stdio.h>
#include <stdlib.h>

int countKDifference(int* nums, int numsSize, int k) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = numsSize - 1; j > i; j--) {
            if (abs(nums[i] - nums[j]) == k) res++;
        }
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int size, k;
        int* nums;
        scanf("%d %d", &size, &k);
        nums = malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            scanf("%d", &nums[i]);
        }

        printf("%d\n", countKDifference(nums, size, k));
        free(nums);
    }
    return 0;
}