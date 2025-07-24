//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define MAX_ANSWER_LENGTH 2

typedef struct Element {
    int atomicNumber;
    char symbol[3];
    char name[20];
    char category[20];
} Element;

void initElements(Element[]);
void shuffle(Element[], int);
char* getAnswer();
int isValidAnswer(char*);
void printQuestion(Element[], int);
void printScore(int, int);

int main() {
    Element elements[NUM_ELEMENTS];
    initElements(elements);
    int score = 0;
    int numQuestions = 10;
    
    printf("Welcome to the periodic table quiz!\n");
    printf("Answer the following questions with the symbol of the element.\n");
    
    for(int i = 0; i < numQuestions; i++) {
        shuffle(elements, NUM_ELEMENTS);
        printQuestion(elements, i+1);
        char* answer = getAnswer();
        if(isValidAnswer(answer) && strcmp(answer, elements[0].symbol) == 0) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer. The correct answer is %s.\n", elements[0].symbol);
        }
        printf("Your current score is %d out of %d.\n\n", score, i+1);
    }
    
    printScore(score, numQuestions);
    
    printf("Thanks for playing!\n");
    return 0;
}

void initElements(Element elements[]) {
    elements[0] = (Element) {1, "H", "Hydrogen", "Nonmetal"};
    elements[1] = (Element) {2, "He", "Helium", "Noble gas"};
    elements[2] = (Element) {3, "Li", "Lithium", "Alkali metal"};
    elements[3] = (Element) {4, "Be", "Beryllium", "Alkaline earth metal"};
    elements[4] = (Element) {5, "B", "Boron", "Metalloid"};
    // ... And so on for all 118 elements
}

void shuffle(Element arr[], int n) {
    for(int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        Element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

char* getAnswer() {
    char* answer = malloc(MAX_ANSWER_LENGTH * sizeof(char));
    printf("Enter your answer: ");
    scanf("%s", answer);
    return answer;
}

int isValidAnswer(char* answer) {
    if(strlen(answer) != 1 && strlen(answer) != MAX_ANSWER_LENGTH) {
        printf("Invalid answer. Please enter a valid symbol.\n\n");
        return 0;
    }
    for(int i = 0; i < strlen(answer); i++) {
        if(answer[i] < 'A' || answer[i] > 'Z') {
            printf("Invalid answer. Please enter a valid symbol.\n\n");
            return 0;
        }
    }
    return 1;
}

void printQuestion(Element elements[], int questionNumber) {
    printf("Question %d: %s (%s) belongs to which category?\n", questionNumber, elements[0].name, elements[0].symbol);
    printf("a. %s\n", elements[0].category);
    printf("b. %s\n", elements[1].category);
    printf("c. %s\n", elements[2].category);
    printf("d. %s\n\n", elements[3].category);
}

void printScore(int score, int numQuestions) {
    printf("Your final score is %d out of %d.\n", score, numQuestions);
    if(score == numQuestions) {
        printf("Congratulations! You got a perfect score.\n");
    } else if(score >= numQuestions/2) {
        printf("Good job! You know your elements.\n");
    } else {
        printf("Better luck next time. Maybe study up on your periodic table.\n");
    }
}