#include <stdio.h>
#include <stdlib.h>

int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int ans = -1;

        int arrSize;
        scanf("%d", &arrSize);
        int arr[arrSize];
        int biggest = 0;

        for (int i = 0; i < arrSize; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] > biggest) biggest = arr[i];
        }

        int table[biggest + 1];
        for (int i = 0; i <= biggest; i++) {
            table[i] = 0;
        }

        for (int i = 0; i < arrSize; i++) {
            if (++table[arr[i]] > 1) {
                ans = arr[i];
                break;
            }
        }

        printf("#%d %d\n", tc, ans);
    }
    return 0;
}