//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ELEMENT_COUNT 118

struct Element {
    int number;
    char symbol[3];
    char name[20];
    float mass;
    char state[10];
    char category[20];
    char group[10];
} elements[ELEMENT_COUNT];

void initializeElements() {
    int i;
    for (i = 0; i < ELEMENT_COUNT; i++) {
        elements[i].number = i + 1;

        switch (i + 1) {
            case 1: strcpy(elements[i].symbol, "H"); strcpy(elements[i].name, "Hydrogen"); elements[i].mass = 1.008; strcpy(elements[i].state, "Gas"); strcpy(elements[i].category, "Non-metal"); strcpy(elements[i].group, "1"); break;
            case 2: strcpy(elements[i].symbol, "He"); strcpy(elements[i].name, "Helium"); elements[i].mass = 4.003; strcpy(elements[i].state, "Gas"); strcpy(elements[i].category, "Noble gas"); strcpy(elements[i].group, "18"); break;
            case 3: strcpy(elements[i].symbol, "Li"); strcpy(elements[i].name, "Lithium"); elements[i].mass = 6.941; strcpy(elements[i].state, "Solid"); strcpy(elements[i].category, "Alkali metal"); strcpy(elements[i].group, "1"); break;
            case 4: strcpy(elements[i].symbol, "Be"); strcpy(elements[i].name, "Beryllium"); elements[i].mass = 9.012; strcpy(elements[i].state, "Solid"); strcpy(elements[i].category, "Alkaline earth metal"); strcpy(elements[i].group, "2"); break;
            // and so on for the remaining elements
        }
    }
}

void printInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be given the name or symbol of an element, and you must provide the other piece of information.\n");
    printf("For example, if you are given the symbol 'Fe', you would provide the name 'Iron'.\n\n");
    printf("You can quit the quiz at any time by entering 'quit'.\n\n");
}

void askQuestion(int questionNumber, int elementIndex, char* columnName) {
    printf("[%d] What is the %s of %s? ", questionNumber, columnName, elements[elementIndex].symbol);
}

int validateAnswer(char* answer, char* correctValue) {
    int i;
    for (i = 0; i < strlen(answer); i++) {
        answer[i] = toupper(answer[i]);
    }
    if (strcmp(answer, correctValue) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correctValue);
        return 0;
    }
}

int main() {
    initializeElements();
    printInstructions();

    int questionCount = 0, correctCount = 0, elementIndex, questionType;
    char answer[20], correctValue[20];

    while (1) {
        // randomly choose a type of question (name to symbol or symbol to name), then randomly choose an element to ask about
        questionType = rand() % 2;
        elementIndex = rand() % ELEMENT_COUNT;

        if (questionType == 0) { // ask for symbol
            askQuestion(++questionCount, elementIndex, "symbol");
            scanf("%s", answer);
            if (strcmp(answer, "quit") == 0) {
                printf("\nYou answered %d questions correctly out of %d total questions.\n", correctCount, questionCount - 1);
                break;
            }
            strcpy(correctValue, elements[elementIndex].symbol);
            correctCount += validateAnswer(answer, correctValue);
        } else { // ask for name
            askQuestion(++questionCount, elementIndex, "name");
            scanf("%s", answer);
            if (strcmp(answer, "quit") == 0) {
                printf("\nYou answered %d questions correctly out of %d total questions.\n", correctCount, questionCount - 1);
                break;
            }
            strcpy(correctValue, elements[elementIndex].name);
            correctCount += validateAnswer(answer, correctValue);
        }
    }

    return 0;
}