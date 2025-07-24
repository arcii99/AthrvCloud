//FormAI DATASET v1.0 Category: Arithmetic ; Style: medieval
#include <stdio.h>

int main() {
    int knightCount, swordCount, shieldCount, totalEquipmentCount;

    printf("Greetings Sir Knight! How many swords do you have?: ");
    scanf("%d", &swordCount);

    printf("How many shields do you have?: ");
    scanf("%d", &shieldCount);

    printf("How many knights do you have in your army?: ");
    scanf("%d", &knightCount);

    totalEquipmentCount = swordCount + shieldCount;

    if (totalEquipmentCount > knightCount) {
        printf("You are well equipped Sir Knight! With %d swords and %d shields, you will surely vanquish your foes! However, you only have %d knights in your army. You may want to hire more troops before engaging in battle.\n", swordCount, shieldCount, knightCount);
    } else if (totalEquipmentCount == knightCount) {
        printf("You are well equipped Sir Knight! With %d swords and %d shields, you can expect to have an evenly matched battle with your foes with your army of %d knights.\n", swordCount, shieldCount, knightCount);
    } else {
        printf("You are not well equipped Sir Knight. With only %d swords and %d shields, your army of %d knights may be cut down by your foes. You may want to acquire more equipment before engaging in battle.\n", swordCount, shieldCount, knightCount);
    }

    return 0;
}