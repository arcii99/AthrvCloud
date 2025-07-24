//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ENEMIES 1000
#define ROUNDS 100000

struct enemy {
    int health;
    int armor;
};

int main() {
    srand(time(NULL));
    struct enemy enemies[ENEMIES];
    int total_attacks = 0;
    clock_t start_time, end_time;
    double time_elapsed;

    printf("Loading enemy data...\n");

    for(int i=0; i<ENEMIES; i++) {
        enemies[i].health = 100 + rand() % 100;
        enemies[i].armor = rand() % 50;
    }

    printf("Starting benchmark...\n");
    start_time = clock();

    for(int round=0; round<ROUNDS; round++) {
        for(int i=0; i<ENEMIES; i++) {
            int attack = rand() % 100;
            int damage = attack - enemies[i].armor;
            if(damage > 0) {
                enemies[i].health -= damage;
            }
            total_attacks++;
        }
    }

    end_time = clock();
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Benchmark completed in %.6f seconds.\n", time_elapsed);
    printf("Total attacks: %d\n", total_attacks);

    return 0;
}