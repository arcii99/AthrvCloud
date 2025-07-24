//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[20];
    float goldCoins;
} villager;

int main() {
    // Initialize array of villagers
    villager villagers[5] = {
        {35, "John", 10.0},
        {24, "Mary", 5.5},
        {45, "William", 20.0},
        {31, "Elizabeth", 8.0},
        {50, "Richard", 15.0}
    };
    
    // Print out all villagers
    printf("All villagers:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d, %.1f gold coins\n", villagers[i].name, villagers[i].age, villagers[i].goldCoins);
    }
    
    // Find villagers with the most gold coins
    float maxCoins = 0.0;
    for (int i = 0; i < 5; i++) {
        if (villagers[i].goldCoins > maxCoins) {
            maxCoins = villagers[i].goldCoins;
        }
    }
    
    printf("\nVillagers with the most gold coins:\n");
    for (int i = 0; i < 5; i++) {
        if (villagers[i].goldCoins == maxCoins) {
            printf("%s, %d, %.1f gold coins\n", villagers[i].name, villagers[i].age, villagers[i].goldCoins);
        }
    }
    
    // Find average age of all villagers
    int totalAge = 0;
    for (int i = 0; i < 5; i++) {
        totalAge += villagers[i].age;
    }
    float avgAge = (float)totalAge / 5.0;
    printf("\nAverage age of all villagers: %.1f\n", avgAge);
    
    return 0;
}