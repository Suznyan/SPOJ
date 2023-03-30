#include <stdbool.h>
#include <stdio.h>
int s, n, k;
bool fin;
int a[22][22], x[22];
int tmp;

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void init() {
    scanf("%d", &s);
    scanf("%d", &k);
    scanf("%d", &n);
    for (int i = 1; i <= n; i = i + 1)
        for (int j = 1; j <= k; j = j + 1) scanf("%d", &a[i][j]);
    fin = false;
    for (int i = 1; i <= k; i = i + 1)
        for (int j = 1; j < n; j = j + 1)
            for (int l = j + 1; l <= n; l = l + 1)
                if (a[j][i] < a[l][i]) swap(&a[j][i], &a[l][i]);
    tmp = 0;
    x[0] = -1;
}

void print(void) {
    if (s != tmp) return;
    printf("YES\n");
    int i;
    for (int i = 1; i < k; i = i + 1) printf("%d ", x[i]);
    printf("%d", x[k]);
    fin = true;
}

void backtrack(int t) {
    int i;
    for (int i = 1; i <= n; i = i + 1) {
        if (a[i][t] < x[t - 1]) break;
        x[t] = a[i][t];
        tmp = tmp + a[i][t];
        if (s - tmp >= x[t] * (k - t)) {
            if (t == k)
                print();
            else if (!fin)
                btrk(t + 1);
        }
        tmp = tmp - a[i][t];
    }
}

int main() {
    init();
    backtrack(1);
    if (!fin) printf("NO");
}
