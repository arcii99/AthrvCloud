//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defines the element structure
struct Element {
    char name[20];
    char symbol[3];
    int number;
};

// Defines a function to populate the periodic table with elements
void populateTable(struct Element table[118]) {
    // Adds Hydrogen to the table
    struct Element hydrogen = {"Hydrogen", "H", 1};
    table[0] = hydrogen;
    // Adds Helium to the table
    struct Element helium = {"Helium", "He", 2};
    table[1] = helium;
    // Continues adding elements to the table
    // ...
}

// Defines a function to shuffle the elements in the periodic table
void shuffleTable(struct Element table[118]) {
    srand((unsigned int)time(NULL));
    for (int i = 117; i >= 0; i--) {
        int j = rand() % (i + 1);
        struct Element temp = table[i];
        table[i] = table[j];
        table[j] = temp;
    }
}

int main() {
    struct Element periodicTable[118];
    // Populates the periodic table with elements
    populateTable(periodicTable);
    // Shuffles the periodic table
    shuffleTable(periodicTable);
    // Prints the shuffled periodic table in a quiz format
    int correctAnswers = 0;
    int totalQuestions = 0;
    for (int i = 0; i < 118; i++) {
        struct Element element = periodicTable[i];
        char answer[20];
        printf("What is the symbol for %s? ", element.name);
        scanf("%s", answer);
        if (strcmp(answer, element.symbol) == 0) {
            printf("Correct!\n\n");
            correctAnswers++;
        } else {
            printf("Incorrect! The symbol for %s is %s.\n\n", element.name, element.symbol);
        }
        totalQuestions++;
    }
    // Prints the quiz results
    printf("Your score: %d/%d\n", correctAnswers, totalQuestions);
    return 0;
}