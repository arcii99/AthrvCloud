//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ELEMENTS 30
#define MAX_QUESTIONS 10

typedef struct{
    char symbol[3];
    char name[20];
    double atomic_weight;
} Element;

const Element PeriodicTable[MAX_ELEMENTS] = {
    {"H",  "Hydrogen",        1.008},
    {"He", "Helium",          4.003},
    {"Li", "Lithium",         6.941},
    {"Be", "Beryllium",       9.012},
    {"B",  "Boron",          10.81},
    {"C",  "Carbon",         12.01},
    {"N",  "Nitrogen",       14.01},
    {"O",  "Oxygen",         16.00},
    {"F",  "Fluorine",       19.00},
    {"Ne", "Neon",           20.18},
    {"Na", "Sodium",         22.99},
    {"Mg", "Magnesium",      24.31},
    {"Al", "Aluminum",       26.98},
    {"Si", "Silicon",        28.09},
    {"P",  "Phosphorus",     30.97},
    {"S",  "Sulfur",         32.07},
    {"Cl", "Chlorine",       35.45},
    {"K",  "Potassium",      39.10},
    {"Ca", "Calcium",        40.08},
    {"Sc", "Scandium",       44.96},
    {"Ti", "Titanium",       47.87},
    {"V",  "Vanadium",       50.94},
    {"Cr", "Chromium",       52.00},
    {"Mn", "Manganese",      54.94},
    {"Fe", "Iron",           55.85},
    {"Ni", "Nickel",         58.69},
    {"Cu", "Copper",         63.55},
    {"Zn", "Zinc",           65.38},
    {"Ga", "Gallium",        69.72}
};

typedef struct{
    char question_text[100];
    int correct_answer_index;
} Question;

void create_question(Question* q, int element_count){
    Element element1, element2;
    int option1, option2;

    do{
        option1 = rand() % element_count;
        element1 = PeriodicTable[option1];

        option2 = rand() % element_count;
        element2 = PeriodicTable[option2];
    }while(option1 == option2);

    q->correct_answer_index = rand() % 2;
    if(q->correct_answer_index == 0){
        sprintf(q->question_text, "What is the symbol for %s and %s?", element1.name, element2.name);
    } else {
        sprintf(q->question_text, "What is the symbol for %s and %s?", element2.name, element1.name);
    }
}

int main(){
    srand(time(NULL));

    int points = 0;
    int total_questions = 0;
    Question questions[MAX_QUESTIONS];

    for(int i=0; i<MAX_QUESTIONS; i++){
        create_question(&questions[i], MAX_ELEMENTS);
    }

    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("Instructions:\n");
    printf(" - There are %d questions in this quiz.\n", MAX_QUESTIONS);
    printf(" - For each question, choose the correct answer.\n");
    printf(" - You will earn 1 point for each correct answer.\n");
    printf(" - Let's begin!\n\n");

    for(int i=0; i<MAX_QUESTIONS; i++){
        Question q = questions[i];
        printf("Question %d: %s\n", i+1, q.question_text);

        Element element1, element2;
        int option1, option2;

        do{
            option1 = rand() % MAX_ELEMENTS;
            element1 = PeriodicTable[option1];

            option2 = rand() % MAX_ELEMENTS;
            element2 = PeriodicTable[option2];
        }while(option1 == option2);

        if(q.correct_answer_index == 0){
            printf("A) %s and %s\n", element1.symbol, element2.symbol);
            printf("B) %s and %s\n", element2.symbol, element1.symbol);
        } else {
            printf("A) %s and %s\n", element2.symbol, element1.symbol);
            printf("B) %s and %s\n", element1.symbol, element2.symbol);
        }

        char user_input;
        do{
            printf("Your answer: ");
            scanf(" %c", &user_input);
            user_input = toupper(user_input);
        }while(user_input != 'A' && user_input != 'B');

        int chosen_answer_index = (user_input == 'A') ? 0 : 1;

        if(chosen_answer_index == q.correct_answer_index){
            printf("Correct!\n");
            points++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", q.correct_answer_index ? 'B' : 'A');
        }

        total_questions++;
        printf("Current score: %d/%d\n\n", points, total_questions);
    }

    printf("Quiz complete! You scored %d/%d.\n", points, MAX_QUESTIONS);

    return 0;
}