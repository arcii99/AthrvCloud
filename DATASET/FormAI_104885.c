//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char map[20][20];

void generate_map() {
    srand(time(0));

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            int rnd = rand() % 100;

            if (rnd < 10) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }

    map[0][0] = 'S'; // Start
    map[19][19] = 'E'; // End
}

int main() {
    generate_map();

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            printf("%c", map[i][j]);
        }

        printf("\n");
    }

    return 0;
}