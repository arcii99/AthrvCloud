//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>

// Define struct for the knights
typedef struct knight {
    char name[25];
    int age;
    char weapon[15];
    float armor_rating;
} knight;

// Define function to find the youngest knight
void findYoungestKnight(knight knights[], int num_knights) {
    int youngest_index = 0;
    for (int i = 1; i < num_knights; i++) {
        if (knights[i].age < knights[youngest_index].age) {
            youngest_index = i;
        }
    }
    printf("\nThe youngest knight is %s, aged %d.\n", knights[youngest_index].name, knights[youngest_index].age);
}

// Define main function
int main() {
    printf("Welcome to the Knight's Data Mining Program.\n");

    // Define and initialize an array of knights
    knight knights[5] = {
        {"Arthur", 33, "Excalibur", 8.5},
        {"Lancelot", 28, "Sword", 7.8},
        {"Galahad", 26, "Spear", 8.3},
        {"Tristan", 31, "Bow", 7.1},
        {"Percival", 24, "Mace", 9.2}
    };
    
    // Print all the knights
    printf("Here are all the knights:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - %d years - %s - Armor Rating: %.1f\n", knights[i].name, knights[i].age, knights[i].weapon, knights[i].armor_rating);
    }

    // Call function to find youngest knight
    findYoungestKnight(knights, 5);

    return 0;
}