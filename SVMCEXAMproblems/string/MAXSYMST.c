#include <stdio.h>
#include <stdlib.h>

int maxPalindrome(char s[], int len) {
    int ans = 1;
    int left, right;
    for (int i = 0; i < len; i++) {
        left = i;
        right = i;
        while (right < len && s[right] == s[right + 1]) {
            right++;
        }
        i = right + 1;
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left + 1 > ans) ans = right - left + 1;
    }

    return ans;
}

int longestPalindrome(char *s) {
    char *start, *end;
    char *p = s, *subStart = s;
    int maxLen = 1;
    while (*p) {
        start = p;
        end = p;

        while (*(end + 1) && *(end + 1) == *end) {
            end++;  // skip duplicate?
        }
        p = end + 1;
        while (*(end + 1) && (start > s) && *(end + 1) == *(start - 1)) {
            start--;
            end++;
        }
        if (end - start + 1 > maxLen) {
            maxLen = end - start + 1;
            subStart = start;
        }
    }
    return maxLen;
}

int lengthOfString(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf(" %d ", &T);
    for (int tc = 1; tc <= T; tc++) {
        // char *str = malloc(sizeof(char) * 1001);
        char str[1001];
        scanf("%s", str);

        // int ans = maxPalindrome(str, lengthOfString(str));
        int ans = longestPalindrome(str);
        // free(str);
        printf("#%d %d\n", tc, ans);
    }

    return 0;
}