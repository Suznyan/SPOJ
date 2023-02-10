#include <stdio.h>

int main() {
    int a;
    while (scanf("%d", &a) > 0 && a != 42) printf("%d\n", a);

    return 0;
}