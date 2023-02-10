#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int a, b;
        int flag = 0;
        scanf("%d %d", &a, &b);
        printf("#%d ", tc);
        for (int i = a; i <= b; i++) {
            if (ceilf(sqrt(i)) == sqrt(i)) {
                printf("%d ", i);
                flag = 1;
            }
        }
        printf("\n");
        if (!flag) printf("NO NUMBER\n");
    }
    return 0;
}