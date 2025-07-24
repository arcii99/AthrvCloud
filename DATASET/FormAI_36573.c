//FormAI DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_sieges = rand() % 6 + 1;
    int num_defenders = rand() % 1000 + 1;
    int num_arrows = rand() % 2000 + 1;
    int num_men = rand() % 500 + 1;
    int num_babies = rand() % 100 + 1;

    printf("Your castle is under siege by %d enemy armies!\n", num_sieges);
    printf("You have %d defenders to protect the castle!\n", num_defenders);
    printf("You have %d arrows to fire at the enemy!\n", num_arrows);
    printf("You have %d men in your army!\n", num_men);
    printf("You also have %d babies, who may eventually grow up to be warriors!\n", num_babies);

    if(num_sieges > num_defenders) {
        printf("Your castle has fallen to the enemy armies!\n");
    }
    else {
        printf("Your castle holds strong against the enemy armies!\n");
    }

    if(num_arrows < num_sieges * 100) {
        printf("You are out of arrows and must resort to melee combat!\n");
    }
    else {
        printf("Your archers are well-stocked and ready for battle!\n");
    }

    if(num_men < num_sieges * 50) {
        printf("You are severely outnumbered and must call for reinforcements!\n");
    }
    else {
        printf("Your army is ready to fight for the castle!\n");
    }

    if(num_babies > num_men) {
        printf("You have more babies than fighting men in your kingdom. Your future is in jeopardy!\n");
    }
    else {
        printf("Your future is secure with a sufficient number of fighters in your kingdom!\n");
    }

    return 0;
}