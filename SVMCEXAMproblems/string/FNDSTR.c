#include <stdio.h>
#include <stdlib.h>

int strCount(char* s1, char* s2) {
    int res = 0;
    for (int i = 0; s2[i] != '\0'; i++) {
        int flag = 1;
        if (s2[i] == s1[0]) {
            for (int j = 1; j < s1[j] != '\0'; j++) {
                if (s1[j] != s2[i + j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) res++;
        }
    }
    return res;
}

int main() {
    char *str1, *str2;
    int T;
    for (int tc = 1; tc <= 10; tc++) {
        scanf(" %d ", &T);
        str1 = malloc(10 * sizeof(char));
        str2 = malloc(1000 * sizeof(char));
        scanf("%[^\n]%*c", str1);
        scanf("%[^\n]%*c", str2);

        printf("#%d %d\n", T, strCount(str1, str2));
        free(str1), free(str2);
        str1 = NULL, str2 = NULL;
    }
    return 0;
}