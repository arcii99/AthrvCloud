//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ram_usage[50];
    int i;
    printf("Initializing RAM usage...");
    for (i=0; i<50; i++) {
        ram_usage[i] = rand() % 100;
    }
    printf("Done!\n");

    printf("RAM usage:\n");
    int line_num = 1;
    for (i=0; i<50; i++) {
        printf("%d. %d%%\n", line_num, ram_usage[i]);
        line_num++;
    }
    
    printf("Shape-shifting mode activated...\n");
    int shape_shift_count = 1;
    while (shape_shift_count <= 5) {
        printf("Shape-shifting #%d\n", shape_shift_count);
        for (i=0; i<50; i++) {
            int new_usage = rand() % 100;
            while (new_usage == ram_usage[i]) {
                new_usage = rand() % 100;
            }
            ram_usage[i] = new_usage;
        }
        line_num = 1;
        printf("RAM usage:\n");
        for (i=0; i<50; i++) {
            printf("%d. %d%%\n", line_num, ram_usage[i]);
            line_num++;
        }
        shape_shift_count++;
    }

    printf("Exiting RAM usage monitor.");
    return 0;
}