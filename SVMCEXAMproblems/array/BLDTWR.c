#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return a > b ? a : b; }
int TowerCost(int *bricks, int bricksSize, int T1Height, int T2Height) {
    int res = 0;
    int maxBrick = 0;
    for (int i = 0; i < bricksSize; i++) maxBrick = max(maxBrick, bricks[i]);

    int *count = malloc((maxBrick + 1) * sizeof(int));
    for (int i = 0; i <= maxBrick; i++) count[i] = 0;

    int idx = 0;
    for (int i = 0; i < bricksSize; i++) count[bricks[i]]++;
    for (int i = maxBrick; i >= 1; i--)
        for (int j = 0; j < count[i]; j++) bricks[idx++] = i;
    idx = 0;

    int *order = malloc(bricksSize * sizeof(int));
    for (int i = 1; i <= max(T1Height, T2Height); i++) count[i] = 0;
    for (int i = 1; i <= T1Height; i++) count[i]++;
    for (int i = 1; i <= T2Height; i++) count[i]++;
    for (int i = 1; i <= max(T1Height, T2Height); i++)
        for (int j = 0; j < count[i]; j++) order[idx++] = i;

    for (int i = 0; i < bricksSize; i++) res += bricks[i] * order[i];

    free(count);
    free(order);
    count = NULL;
    order = NULL;
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int size, t1, t2;
        scanf("%d %d %d", &size, &t1, &t2);
        int *bricks = malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            scanf("%d", &bricks[i]);
        }
        printf("#%d %d\n", tc, TowerCost(bricks, size, t1, t2));
    }
    return 0;
}