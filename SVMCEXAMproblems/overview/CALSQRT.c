#include <stdio.h>
#include <stdlib.h>

double findSqrt(double x) {
    // for 0 and 1, the square roots are themselves
    if (x < 2) return x;

    // considering the equation values
    double y = x;
    double z = (y + (x / y)) / 2;

    // as we want to get upto 5 decimal digits, the absolute
    // difference should not exceed 0.00001
    while (abs(y - z) >= 0.00001) {
        y = z;
        z = (y + (x / y)) / 2;
    }
    return z;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int num;
        scanf("%d", &num);
        printf("#%d %d", tc, (int)findSqrt(num));
        printf("\n");
    }

    return 0;
}