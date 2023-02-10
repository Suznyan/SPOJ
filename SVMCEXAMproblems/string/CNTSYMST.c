#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSubstrings(char *s) {
    int ans = 0, left, right;
    for (int i = 0; i < strlen(s); i++) {
        left = i;
        right = i;

        while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }

        left = i;
        right = i + 1;

        while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf(" %d ", &T);
    for (int tc = 1; tc <= T; tc++) {
        int ans = 0;
        char *str = malloc(sizeof(char) * 1001);
        scanf("%[^\n]%*c", str);

        ans = countSubstrings(str);

        free(str);
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}