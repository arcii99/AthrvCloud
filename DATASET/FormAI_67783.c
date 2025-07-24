//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define element structure
struct Element {
    char name[20];
    char symbol[5];
    int atomicNumber;
};

// Define quiz question structure
struct Question {
    char question[50];
    char answer[5];
};

// Define function to add element to periodic table
void addElement(struct Element *pt, char name[20], char symbol[5], int atomicNumber, int index) {
    strcpy(pt[index].name, name);
    strcpy(pt[index].symbol, symbol);
    pt[index].atomicNumber = atomicNumber;
}

// Define function to generate quiz questions
void generateQuestions(struct Element *pt, struct Question *q, int numQuestions) {
    srand(time(NULL)); // set seed for random number generator
    for(int i=0; i < numQuestions; i++) {
        int randIndex = rand() % 118; // generate random number between 0 and 117
        // Generate fill-in-the-blank question
        sprintf(q[i].question, "What is the symbol for %s? Fill in the blank: _ _ %c _", pt[randIndex].name, pt[randIndex].symbol[3]);
        strcpy(q[i].answer, pt[randIndex].symbol); // store answer to question
    }
}

int main() {
    // Initialize periodic table
    struct Element periodicTable[118];
    addElement(periodicTable, "Hydrogen", "H", 1, 0);
    addElement(periodicTable, "Helium", "He", 2, 1);
    addElement(periodicTable, "Lithium", "Li", 3, 2);
    // add the rest of the elements...

    // Generate quiz questions
    struct Question questions[10];
    generateQuestions(periodicTable, questions, 10);

    // Display quiz questions and prompt for answers
    printf("Welcome to the periodic table quiz!\n");
    int score = 0;
    for(int i=0; i < 10; i++) {
        printf("\nQuestion %d:\n%s\n", i+1, questions[i].question);
        char answer[5];
        printf("Enter your answer: ");
        scanf("%s", &answer);
        if(strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", questions[i].answer);
        }
    }
    printf("\nQuiz complete! You scored %d out of 10.\n", score);

    return 0;
}