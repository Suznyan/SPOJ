#include <stdio.h>
#include <stdlib.h>

int POW(int a, int time) {
    while (--time > 0) a *= a;
    return a;
}

int satisfiedCount(int *niceNums, int niceNumsSize, int niceNumsNeeded,
                   int start, int end) {
    int res = 0;
    if (POW(10, niceNumsNeeded - 1) - start > 0)
        start = POW(10, niceNumsNeeded - 1) - start;
    for (int from = start; from <= end; from++) {
        int count = 0;
        int num = from;
        while (num > 0) {
            for (int i = 0; i < niceNumsSize; i++) {
                if (num % 10 != niceNums[i]) continue;
                count++;
            }
            num /= 10;
        }
        if (count < niceNumsNeeded) continue;
        res++;
    }
    return res;
}

int main() {
    int T;
    int *niceNums;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int niceNumsCount, niceNumsNeeded;
        scanf("%d %d", &niceNumsCount, &niceNumsNeeded);
        niceNums = malloc(niceNumsCount * sizeof(int));
        for (int i = 0; i < niceNumsCount; i++) scanf("%d", &niceNums[i]);
        int start, end;
        scanf("%d %d", &start, &end);

        printf("#%d %d\n", tc,
               satisfiedCount(niceNums, niceNumsCount, niceNumsNeeded, start,
                              end));
        free(niceNums);
        niceNums = NULL;
    }
    return 0;
}