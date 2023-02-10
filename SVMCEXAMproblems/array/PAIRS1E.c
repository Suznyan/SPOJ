#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int n, k, ans = 0;
        scanf("%d %d", &n, &k);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d ", &arr[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (abs(arr[i] - arr[j]) == k) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}