//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118 // number of elements in the periodic table
#define MAX_ELECTRONS 118 // maximum number of electrons in an element's electronic configuration
#define MAX_QUESTIONS 10 // maximum number of questions in the quiz

// define an Element struct to hold information about each element in the periodic table
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    int num_electrons;
    int electrons[MAX_ELECTRONS];
} Element;

// function to initialize an Element struct with default values
void init_element(Element *element) {
    strcpy(element->symbol, "");
    strcpy(element->name, "");
    element->atomic_number = 0;
    element->num_electrons = 0;
    for (int i = 0; i < MAX_ELECTRONS; i++) {
        element->electrons[i] = 0;
    }
}

// function to read an Element struct from a file
void read_element(Element *element, FILE *fp) {
    char line[100];
    fgets(line, 100, fp);
    sscanf(line, "%d %s %s", &element->atomic_number, element->symbol, element->name);
    fgets(line, 100, fp);
    sscanf(line, "%d", &element->num_electrons);
    fgets(line, 100, fp);
    char *token = strtok(line, " ");
    for (int i = 0; i < element->num_electrons; i++) {
        sscanf(token, "%d", &element->electrons[i]);
        token = strtok(NULL, " ");
    }
}

// function to print an Element struct in a human-readable format
void print_element(Element *element) {
    printf("Element:\n");
    printf("Atomic number: %d\n", element->atomic_number);
    printf("Symbol: %s\n", element->symbol);
    printf("Name: %s\n", element->name);
    printf("Number of electrons: %d\n", element->num_electrons);
    printf("Electronic configuration: ");
    for (int i = 0; i < element->num_electrons; i++) {
        printf("%d ", element->electrons[i]);
    }
    printf("\n");
}

// function to randomly generate a set of quiz questions
void generate_questions(Element *elements, int num_elements, int num_questions, int *questions) {
    for (int i = 0; i < num_questions; i++) {
        // choose a random element
        int index = rand() % num_elements;
        // choose a random question type (symbol or name)
        int type = rand() % 2;
        // store the chosen question in the questions array
        if (type == 0) {
            questions[i] = index * 2; // symbol question
        } else {
            questions[i] = index * 2 + 1; // name question
        }
    }
}

// function to run the quiz
void run_quiz(Element *elements, int num_elements, int *questions, int num_questions) {
    int score = 0;
    int total = 0;
    for (int i = 0; i < num_questions; i++) {
        int index = questions[i] / 2;
        int type = questions[i] % 2;
        printf("Question %d: ", i + 1);
        if (type == 0) {
            printf("What is the symbol for element %d?\n", index + 1);
            char answer[3];
            scanf("%s", answer);
            if (strcmp(answer, elements[index].symbol) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
            }
        } else {
            printf("What is the name for element %d?\n", index + 1);
            char answer[20];
            scanf("%s", answer);
            if (strcmp(answer, elements[index].name) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", elements[index].name);
            }
        }
        total++;
    }
    printf("Quiz complete. You scored %d out of %d.\n", score, total);
}

int main() {
    // initialize the elements array
    Element elements[MAX_ELEMENTS];
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        init_element(&elements[i]);
    }
    // read the elements from a file
    FILE *fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        read_element(&elements[i], fp);
    }
    fclose(fp);
    // seed the random number generator
    srand(time(NULL));
    // generate the quiz questions
    int questions[MAX_QUESTIONS];
    generate_questions(elements, MAX_ELEMENTS, MAX_QUESTIONS, questions);
    // run the quiz
    run_quiz(elements, MAX_ELEMENTS, questions, MAX_QUESTIONS);
    return 0;
}