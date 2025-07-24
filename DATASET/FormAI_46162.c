//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define a custom data type named "Hero"
typedef struct {
    char name[20];
    int level;
} Hero;

// Function to swap two Hero objects
void swapHeroes(Hero *hero1, Hero *hero2) {
    Hero temp = *hero1;
    *hero1 = *hero2;
    *hero2 = temp;
}

// Function to perform selection sort on an array of Hero objects
void selectionSort(Hero heroes[], int numHeroes) {
    int i, j, minIndex;

    for (i = 0; i < numHeroes - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < numHeroes; j++) {
            if (heroes[j].level < heroes[minIndex].level) {
                minIndex = j;
            }
        }
        swapHeroes(&heroes[i], &heroes[minIndex]);
    }
}

int main() {
    // Create an array of Hero objects
    Hero heroes[5] = {
        {"Batman", 15},
        {"Spiderman", 8},
        {"Superman", 20},
        {"Ironman", 10},
        {"Wonder woman", 18}
    };

    // Print the unsorted array
    printf("Unsorted Heroes:\n");
    for (int i = 0; i < 5; i++) {
        printf("Hero %d - Name: %s, Level: %d\n", i+1, heroes[i].name, heroes[i].level);
    }

    // Sort the array using selection sort
    selectionSort(heroes, 5);

    // Print the sorted array
    printf("\nSorted Heroes:\n");
    for (int i = 0; i < 5; i++) {
        printf("Hero %d - Name: %s, Level: %d\n", i+1, heroes[i].name, heroes[i].level);
    }

    return 0;
}