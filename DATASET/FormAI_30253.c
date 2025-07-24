//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the properties of each element
typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicMass;
    int groupNumber;
    char state[10];
    char classification[4];
} Element;

// Define the periodic table
const Element periodicTable[] = {
    {"H", "Hydrogen", 1, 1.008, 1, "Gas", "Nonmetal"},
    {"He", "Helium", 2, 4.003, 18, "Gas", "Noble Gas"},
    {"Li", "Lithium", 3, 6.941, 1, "Solid", "Alkali Metal"},
    {"Be", "Beryllium", 4, 9.012, 2, "Solid", "Alkaline Earth Metal"},
    {"B", "Boron", 5, 10.81, 13, "Solid", "Metalloid"},
    {"C", "Carbon", 6, 12.01, 14, "Solid", "Nonmetal"},
    {"N", "Nitrogen", 7, 14.01, 15, "Gas", "Nonmetal"},
    {"O", "Oxygen", 8, 16.00, 16, "Gas", "Nonmetal"},
    {"F", "Fluorine", 9, 19.00, 17, "Gas", "Halogen"},
    {"Ne", "Neon", 10, 20.18, 18, "Gas", "Noble Gas"}
};

// Get the user's answer to a question
char getAnswer() {
    char input[5];
    printf("Enter your answer: ");
    fgets(input, 5, stdin);
    return input[0];
}

// Calculate the number of elements in the periodic table
int numElements() {
    return sizeof(periodicTable) / sizeof(Element);
}

// Print out a list of the available groups
void printGroups() {
    printf("Available groups: ");
    for (int i = 0; i < numElements(); i++) {
        printf("%d ", periodicTable[i].groupNumber);
    }
    printf("\n");
}

// Print out a question about an element's group
void groupQuestion() {
    int idx = rand() % numElements();
    Element elem = periodicTable[idx];
    printf("What group is %s (atomic number %d) in?\n", elem.name, elem.atomicNumber);
}

// Print out a question about an element's symbol
void symbolQuestion() {
    int idx = rand() % numElements();
    Element elem = periodicTable[idx];
    printf("What element has the symbol %s?\n", elem.symbol);
}

// Print out a question about an element's name
void nameQuestion() {
    int idx = rand() % numElements();
    Element elem = periodicTable[idx];
    printf("What is the name of element with the symbol %s?\n", elem.symbol);
}

// Main function
int main() {

    // Seed the rand() function for randomizing questions
    srand(time(NULL));

    int score = 0;
    int numQuestions = 3;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("There will be %d questions. Good luck!\n", numQuestions);

    // Ask group questions
    for (int i = 0; i < numQuestions/3; i++) {
        printGroups();
        groupQuestion();
        char answer = getAnswer();
        int idx = rand() % numElements();
        Element elem = periodicTable[idx];
        if (elem.groupNumber == answer - '0') {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer is %d.\n", elem.groupNumber);
        }
    }

    // Ask symbol questions
    for (int i = 0; i < numQuestions/3; i++) {
        symbolQuestion();
        char answer[3];
        fgets(answer, 3, stdin);
        int idx = rand() % numElements();
        Element elem = periodicTable[idx];
        if (strcmp(elem.symbol, answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer is %s.\n", elem.symbol);
        }
    }

    // Ask name questions
    for (int i = 0; i < numQuestions/3; i++) {
        nameQuestion();
        char answer[20];
        fgets(answer, 20, stdin);
        int idx = rand() % numElements();
        Element elem = periodicTable[idx];
        if (strcmp(elem.name, answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer is %s.\n", elem.name);
        }
    }

    printf("Your final score is %d out of %d.\n", score, numQuestions);

    return 0;
}