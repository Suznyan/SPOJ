#include <stdio.h>

int ans;

bool isOperand(char x) {
    if (x - 48 >= 0 && x - 48 <= 9)
        return true;
    else
        return false;
}

char *getString(int N, int *key, int *returnSize) {
    char *s = new char[100];
    int idx = 0;
    s[idx++] = 1 + '0';
    for (int i = 0; i < N - 1; i++) {
        if (key[i] == 0) s[idx++] = (i + 2) + '0';
        if (key[i] == 1) {
            s[idx++] = '+';
            s[idx++] = (i + 2) + '0';
        }
        if (key[i] == 2) {
            s[idx++] = '-';
            s[idx++] = (i + 2) + '0';
        }
    }
    *returnSize = idx;
    return s;
}

int checkEnd(int N, int *key) {
    int bieuthucSize;
    char *bieuthuc = getString(N, key, &bieuthucSize);
    int k = 0, t = 0;
    int *num = new int[N];
    int *op = new int[N - 1];
    for (int i = 0; i < bieuthucSize; i++) {
        if (isOperand(bieuthuc[i])) {
            num[k] = num[k] * 10 + (bieuthuc[i]) - '0';
        } else {
            if (bieuthuc[i] == '+')
                op[t] = 1;
            else
                op[t] = 2;
            t++, k++;
            num[k] = 0;
        }
    }

    int res = num[0];
    for (int i = 0; i < t; i++) {
        if (op[i] == 1)
            res += num[i + 1];
        else
            res -= num[i + 1];
    }
    return res;
}

void backtrack(int num, int N, int *key) {
    if (num == N - 1) {
        if (checkEnd(N, key) == 0) ans++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        key[num] = i;
        backtrack(num + 1, N, key);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);
        int *key = new int[N - 1];
        ans = 0;
        backtrack(0, N, key);
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
