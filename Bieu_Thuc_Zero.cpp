#include <stdio.h>

int ans;

bool isOperand(char x) {
    if (x - 48 >= 0 && x - 48 <= 9)
        return true;
    else
        return false;
}

char *getString(int N, int *key, int *returnSize) {
    char *s = new char[200];
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
    for(int i = 0; i<N; i++) num[i] = 0;
    for(int i = 0; i<N-1; i++) op[i] = 0;
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
    freopen("input.txt", "r", stdin);
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
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
/*#include <iostream>
using namespace std;
#define cons 110
int n;
int cach;
char arr_so[cons];
char arr_dau[cons];
char arr_bieuthuc[cons];
int check[cons];

int tinh() {
    int dem = 0;
    for (int i = 0; i < 2 * n - 1; i++)  // tao thanh bieu thuc tu dau vua so
    {
        arr_bieuthuc[i] = arr_so[dem];
        i++;
        arr_bieuthuc[i] = arr_dau[dem];
        dem++;
    }
    int sum = 0, dau = 1, index = 0, temp = 0;
    while (arr_bieuthuc[index] != '\0')  // tinh tinh toan bieu thuc
    {
        if (arr_bieuthuc[index] != '+' && arr_bieuthuc[index] != '-' &&
            arr_bieuthuc[index] != '.') {
            temp = temp * 10 + arr_bieuthuc[index] - '0';
        } else {
            if (arr_bieuthuc[index] == '+') {
                sum = sum + temp * dau;
                dau = 1;
                temp = 0;
            } else if (arr_bieuthuc[index] == '-') {
                sum = sum + temp * dau;
                dau = -1;
                temp = 0;
            }
        }
        index++;
    }
    sum = sum + temp * dau;

    return sum;
}

void back_track(int dem) {
    if (dem == n - 1) {
        int kq = tinh();
        if (kq == 0) cach++;
        return;
    }

    for (int i = 0; i < 3; i++)  // 3 cach chon dau
    {
        if (check[dem] == 0) {
            if (i == 0) {
                check[dem] = 1;
                arr_dau[dem] = '+';
                back_track(dem + 1);
                check[dem] = 0;
            }
            if (i == 1) {
                check[dem] = 1;
                arr_dau[dem] = '-';
                back_track(dem + 1);
                check[dem] = 0;
            }
            if (i == 2) {
                check[dem] = 1;
                arr_dau[dem] = '.';
                back_track(dem + 1);
                check[dem] = 0;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int th;
    cin >> th;
    for (int tc = 1; tc <= th; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            arr_so[i] = (i + 1) + '0';  // tao so thanh chu
            check[i] = 0;
        }
        cach = 0;
        back_track(0);

        cout << "#" << tc << " " << cach << endl;
    }

    return 0;
}
*/
