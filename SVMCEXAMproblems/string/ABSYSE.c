#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool allNumber(char s[]) {
    for (int i = 0; i < s[i] != '\0'; i++) {
        if (s[i] == 'm') return false;
    }
    return true;
}

int main() {
    int T;
    scanf(" %d ", &T);
    for (int tc = 1; tc <= T; tc++) {
        char num1[100], num2[100], num3[100], op1[2], op2[2];
        scanf(" %s", &num1);
        scanf(" %s", &op1);
        scanf(" %s", &num2);
        scanf(" %s", &op2);
        scanf(" %s", &num3);

        if (allNumber(num1) && allNumber(num2)) {
            int ans = atoi(num1) + atoi(num2);
            printf("%s + %s = %d\n", num1, num2, ans);
        }
        if (allNumber(num1) && allNumber(num3)) {
            int ans = atoi(num3) - atoi(num1);
            printf("%s + %d = %s\n", num1, ans, num3);
        }
        if (allNumber(num2) && allNumber(num3)) {
            int ans = atoi(num3) - atoi(num2);
            printf("%d + %s = %s\n", ans, num2, num3);
        }
    }
    return 0;
}