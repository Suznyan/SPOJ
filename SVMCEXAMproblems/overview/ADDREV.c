#include <stdio.h>
#include <stdlib.h>

int reverseNum(int num) {
    int ans = 0;

    while (num > 0) {
        ans *= 10;
        ans += num % 10;
        num /= 10;
    }

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int num1, num2;
        int ans;

        scanf("%d %d", &num1, &num2);

        ans = reverseNum(num1) + reverseNum(num2);

        printf("%d\n", reverseNum(ans));
    }
    return 0;
}