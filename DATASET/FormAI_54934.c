//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct representing each element on the periodic table
typedef struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

// A function to populate the periodic table with data
void populate_table(Element *table) {
    strcpy(table[0].symbol, "H");
    strcpy(table[0].name, "Hydrogen");
    table[0].atomic_number = 1;

    strcpy(table[1].symbol, "He");
    strcpy(table[1].name, "Helium");
    table[1].atomic_number = 2;

    // Continue adding elements to the table
}

// A function to display the periodic table
void display_table(Element *table) {
    printf("Atomic Number\tSymbol\tName\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < 118; i++) {
        printf("%d\t\t%s\t%s\n", table[i].atomic_number, table[i].symbol, table[i].name);
    }
}

// A function to quiz the user
void quiz_user(Element *table) {
    char answer[3];
    int score = 0;
    printf("Welcome to the periodic table quiz!\n");
    printf("You will be given the name of an element, and you must enter its symbol.\n");
    printf("You will have 3 attempts for each question.\n");

    for (int i = 0; i < 10; i++) {
        int rand_index = rand() % 118; // Generate a random index between 0-117
        char *name = table[rand_index].name;
        printf("\n%s\n", name);
        for (int j = 0; j < 3; j++) {
            printf("Attempt #%d: ", j+1);
            scanf("%s", answer);
            if (strcmp(answer, table[rand_index].symbol) == 0) {
                printf("Correct!\n");
                score++;
                break;
            } else {
                printf("Incorrect.\n");
            }
        }
    }

    printf("\n\nYou scored %d out of 10.\n", score);
}

int main() {
    Element table[118];
    populate_table(table);
    display_table(table);
    quiz_user(table);

    return 0;
}