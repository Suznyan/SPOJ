#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int n, M1, M2;
        int ans = 0;
        scanf("%d %d %d", &n, &M1, &M2);
        int arr[n];
        int count_size = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d ", &arr[i]);
            if (arr[i] > count_size) count_size = arr[i];
        }

        // Counting Sort
        int count[count_size + 1];
        for (int i = 0; i <= count_size; i++) {
            count[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        int arr_idx = 0;
        for (int i = 0; i <= count_size; i++) {
            for (int j = 1; j <= count[i]; j++) {
                arr[arr_idx++] = i;
            }
        }
        // Finish Sorted brick

        int B[n];
        for (int i = 0; i < n; i++) {
            B[i] = 0;
        }

        for (int i = 0; i < M1; i++) {
            B[i] = i + 1;
        }
        for (int i = 0; i < M2; i++) {
            B[M1 + i] = i + 1;
        }

        int max = 0;
        if (M1 > max) max = M1;
        if (M2 > max) max = M2;

        int tempcount[max + 1];
        for (int i = 0; i <= max; i++) {
            tempcount[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            tempcount[B[i]]++;
        }

        arr_idx = 0;
        for (int i = 0; i <= max; i++) {
            for (int j = 1; j <= tempcount[i]; j++) {
                B[arr_idx++] = i;
            }
        }

        for (int i = 0; i < n; i++) {
            ans += arr[i] * B[n - 1 - i];
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}