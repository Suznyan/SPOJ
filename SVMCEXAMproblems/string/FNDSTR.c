#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int tc = 1; tc <= 10; tc++) {
        int T;
        scanf("%d ", &T);
        int ans = 0;

        char *s1 = malloc(sizeof(char) * 11);
        char *s2 = malloc(sizeof(char) * 1001);

        scanf(" %s ", s1);

        scanf("%[^\n]%*c", s2);

        for (int i = 0; s2[i] != '\0'; i++) {
            if (s2[i] == s1[0]) {
                int flag = 0;
                for (int j = 1; s1[j] != '\0'; j++) {
                    if (s2[j + i] != s1[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) ans++;
            }
        }
        free(s1);
        free(s2);
        s1 = NULL;
        s2 = NULL;
        printf("#%d %d\n", T, ans);
    }
    return 0;
}