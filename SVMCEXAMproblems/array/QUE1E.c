#include <stdio.h>
#include <stdlib.h>

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);
        int people[n];
        int ans[n];
        for (int i = 0; i < n; i++) {
            ans[i] = 0;
        }

        int max = 0;
        for (int r = 0; r < n; r++) {
            scanf("%d", &people[r]);
            if (people[r] > max) max = people[r];
        }

        int order[max + 1];
        for (int r = 0; r < n; r++) {
            scanf("%d", &order[people[r]]);
        }

        // counting sort
        int count[max + 1];
        for (int i = 0; i <= max; i++) {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            count[people[i]]++;
        }
        int sorted[n];
        int count_indx = 0;
        for (int i = 0; i <= max; i++) {
            for (int j = 0; j < count[i]; j++) {
                sorted[count_indx++] = i;
            }
        }        

        for (int i = 0; i < n; i++) {
            int greaterCount = order[sorted[i]];
            for (int j = 0; j < n; j++) {
                if (greaterCount == 0 && ans[j] == 0) {
                    ans[j] = sorted[i];
                    break;
                }

                if (ans[j] == 0) greaterCount--;
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}