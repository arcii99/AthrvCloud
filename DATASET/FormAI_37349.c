//FormAI DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char question[200];
    char options[4][50];
    int answer;
} Question;

void clear_screen() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #endif
}

void print_question(Question* q) {
    printf("%s\n", q->question);
    for(int i=0; i<4; i++) {
        printf("%c. %s\n", 65+i, q->options[i]);
    }
}

int check_answer(Question* q, char ans) {
    if(ans>=65 && ans<=69) {
        if(q->answer == ans-65) {
            return 1;   // Correct Answer
        } else {
            return 0;   // Wrong Answer
        }
    } else {
        return -1;      // Invalid Input
    }
}

int main() {

    int score = 0;
    const int num_of_questions = 3;
    Question questions[num_of_questions];

    strcpy(questions[0].question, "What is the capital of India?");
    strcpy(questions[0].options[0], "Mumbai");
    strcpy(questions[0].options[1], "New Delhi");
    strcpy(questions[0].options[2], "Kolkata");
    strcpy(questions[0].options[3], "Chennai");
    questions[0].answer = 1;

    strcpy(questions[1].question, "What is the largest planet in our Solar System?");
    strcpy(questions[1].options[0], "Earth");
    strcpy(questions[1].options[1], "Jupiter");
    strcpy(questions[1].options[2], "Saturn");
    strcpy(questions[1].options[3], "Mars");
    questions[1].answer = 1;

    strcpy(questions[2].question, "What is the smallest country in the world?");
    strcpy(questions[2].options[0], "India");
    strcpy(questions[2].options[1], "USA");
    strcpy(questions[2].options[2], "Vatican City");
    strcpy(questions[2].options[3], "Australia");
    questions[2].answer = 2;

    clear_screen();

    printf("Welcome to the Online Examination System!\n\n");
    printf("You will be presented with %d multiple-choice questions.\n", num_of_questions);
    printf("Enter the option character (A/B/C/D) for your choice.\n");
    printf("Press Enter to submit each answer.\n\n");
    printf("Let's begin!\n\n");
    printf("Press Enter to start...");
    getchar();

    for(int i=0; i<num_of_questions; i++) {
        clear_screen();
        printf("Question %d:\n\n", i+1);
        print_question(&questions[i]);

        char input;
        do {
            printf("\nYour answer: ");
            scanf(" %c", &input);
            input = toupper(input);
        } while(check_answer(&questions[i], input) == -1);

        if(check_answer(&questions[i], input) == 1) {
            printf("\nCongratulations, %c is the correct answer!\n", input);
            score++;
        } else {
            printf("\nSorry, %c is the wrong answer!\n", input);
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();      // getch() function does not work on all platforms
    }

    clear_screen();
    printf("Thank you for taking the Online Examination!\n\n");
    printf("Your final score is %d out of %d.\n", score, num_of_questions);

    return 0;
}