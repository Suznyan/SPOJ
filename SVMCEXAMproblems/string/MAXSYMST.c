#include <stdio.h>
#include <stdlib.h>

int longestPalindrome(char *s) {
    char *start, *end;
    char *p = s;
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
        if (end - start + 1 > maxLen) 
            maxLen = end - start + 1;        
    }
    return maxLen;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    scanf(" %d ", &T);
    for (int tc = 1; tc <= T; tc++) {
        char *str = malloc(sizeof(char) * 1001);
        scanf("%s", str);

        int ans = longestPalindrome(str);

        free(str);
        str = NULL;
        printf("#%d %d\n", tc, ans);
    }

    return 0;
}