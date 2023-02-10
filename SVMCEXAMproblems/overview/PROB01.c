#include <stdio.h>
#include <stdlib.h>

int compressNumSum(int num) {
    int sum = 0;

    while (num > 0) {
        int temp = num % 10;
        sum += temp;
        num /= 10;
    }

    if (sum >= 10)
        return compressNumSum(sum);
    else
        return sum;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int input;
        scanf("%d", &input);

        printf("#%d %d\n", tc, compressNumSum(input));
    }

    return 0;
}