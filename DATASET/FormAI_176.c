//FormAI DATASET v1.0 Category: Arithmetic ; Style: medieval
#include <stdio.h>

int main() {
    /* Let the battles begin */
    int knights = 8;
    int horses = 12;
    int swords = 15;
    int shields = 18;
    int arrows = 21;

    printf("The number of knights is: %d\n", knights);
    printf("The number of horses is: %d\n", horses);
    printf("The number of swords is: %d\n", swords);
    printf("The number of shields is: %d\n", shields);
    printf("The number of arrows is: %d\n", arrows);

    /* The war has begun */
    int total = knights * (horses - swords) + shields / arrows;
    
    printf("The total number of fighters is: %d\n", total);

    /* The aftermath */
    int remaining_horses = horses % shields;

    printf("The remaining horses are: %d\n", remaining_horses);

    /* The treaty */
    int treaty = total - remaining_horses;
    int fiefs = treaty / swords;

    printf("The number of fiefs to be distributed is: %d\n", fiefs);

    return 0;
}