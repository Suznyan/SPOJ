#include <stdio.h>
#include <stdlib.h>

int OutOfReachCount(char **map, int mapSize, int *mapColSize) {
    int paths[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int res = 0;
    for (int r = 0; r < mapSize; r++) {
        for (int c = 0; c < *mapColSize; c++) {
            if (map[r][c] == 'H') res++;
        }
    }
    for (int r = 0; r < mapSize; r++) {
        for (int c = 0; c < *mapColSize; c++) {
            if (map[r][c] == 'A') {
                for (int i = 0; i < 4; i++) {
                    int R = r + paths[i][0];
                    int C = c + paths[i][1];
                    if (R >= mapSize || C >= *mapColSize || R < 0 || C < 0 ||
                        map[R][C] != 'H')
                        continue;
                    res--;
                    map[R][C] = 'X';
                }
            } else if (map[r][c] == 'B') {
                for (int i = 0; i < 4; i++) {
                    int R = r + paths[i][0];
                    int C = c + paths[i][1];
                    for (int j = 0; j < 2; j++) {
                        if (R >= mapSize || C >= *mapColSize || R < 0 || C < 0)
                            continue;
                        if (map[R][C] == 'H') {
                            res--;
                            map[R][C] = 'X';
                        }
                        R += paths[i][0];
                        C += paths[i][1];
                    }
                }
            } else if (map[r][c] == 'C') {
                for (int i = 0; i < 4; i++) {
                    int R = r + paths[i][0];
                    int C = c + paths[i][1];
                    for (int j = 0; j < 3; j++) {
                        if (R >= mapSize || C >= *mapColSize || R < 0 || C < 0)
                            continue;
                        if (map[R][C] == 'H') {
                            res--;
                            map[R][C] = 'X';
                        }
                        R += paths[i][0];
                        C += paths[i][1];
                    }
                }
            } else
                continue;
        }
    }
    return res;
}

int main() {
    char **map;
    int row, col;
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d ", &row, &col);
        map = malloc(row * sizeof *map);
        for (int i = 0; i < row; i++) {
            map[i] = malloc(col * sizeof **map);
        }
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                scanf(" %c", &map[r][c]);
            }
        }

        printf("#%d %d\n", tc, OutOfReachCount(map, row, &col));
    }
    return 0;
}