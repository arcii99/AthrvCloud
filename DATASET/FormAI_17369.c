//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct question {
    int question_id;
    char question_text[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_answer;
};

int main() {
    struct question questions[10];
    int i, j, selected_answer, score = 0;

    printf("Welcome to the Online Examination System!\n\n");

    // Question 1
    questions[0].question_id = 1;
    strcpy(questions[0].question_text, "What is the capital of France?");
    strcpy(questions[0].option1, "London");
    strcpy(questions[0].option2, "Paris");
    strcpy(questions[0].option3, "Madrid");
    strcpy(questions[0].option4, "Berlin");
    questions[0].correct_answer = 2;

    // Question 2
    questions[1].question_id = 2;
    strcpy(questions[1].question_text, "What is the currency of Japan?");
    strcpy(questions[1].option1, "Euro");
    strcpy(questions[1].option2, "Yen");
    strcpy(questions[1].option3, "Dollar");
    strcpy(questions[1].option4, "Pound");
    questions[1].correct_answer = 2;

    // Question 3
    questions[2].question_id = 3;
    strcpy(questions[2].question_text, "What is the largest continent in the world?");
    strcpy(questions[2].option1, "Europe");
    strcpy(questions[2].option2, "Asia");
    strcpy(questions[2].option3, "Africa");
    strcpy(questions[2].option4, "North America");
    questions[2].correct_answer = 2;

    // Question 4
    questions[3].question_id = 4;
    strcpy(questions[3].question_text, "What is the smallest country in the world?");
    strcpy(questions[3].option1, "Vatican City");
    strcpy(questions[3].option2, "Monaco");
    strcpy(questions[3].option3, "San Marino");
    strcpy(questions[3].option4, "Liechtenstein");
    questions[3].correct_answer = 1;

    // Question 5
    questions[4].question_id = 5;
    strcpy(questions[4].question_text, "What is the capital of Australia?");
    strcpy(questions[4].option1, "Melbourne");
    strcpy(questions[4].option2, "Sydney");
    strcpy(questions[4].option3, "Canberra");
    strcpy(questions[4].option4, "Brisbane");
    questions[4].correct_answer = 3;

    // Question 6
    questions[5].question_id = 6;
    strcpy(questions[5].question_text, "What is the highest mountain in the world?");
    strcpy(questions[5].option1, "Kilimanjaro");
    strcpy(questions[5].option2, "Mount Everest");
    strcpy(questions[5].option3, "Matterhorn");
    strcpy(questions[5].option4, "Mount Kilimanjaro");
    questions[5].correct_answer = 2;

    // Question 7
    questions[6].question_id = 7;
    strcpy(questions[6].question_text, "What is the largest animal in the world?");
    strcpy(questions[6].option1, "Elephant");
    strcpy(questions[6].option2, "Blue Whale");
    strcpy(questions[6].option3, "Giraffe");
    strcpy(questions[6].option4, "Hippopotamus");
    questions[6].correct_answer = 2;

    // Question 8
    questions[7].question_id = 8;
    strcpy(questions[7].question_text, "What is the smallest continent in the world?");
    strcpy(questions[7].option1, "Europe");
    strcpy(questions[7].option2, "Antarctica");
    strcpy(questions[7].option3, "North America");
    strcpy(questions[7].option4, "South America");
    questions[7].correct_answer = 2;

    // Question 9
    questions[8].question_id = 9;
    strcpy(questions[8].question_text, "What is the deepest ocean in the world?");
    strcpy(questions[8].option1, "Atlantic Ocean");
    strcpy(questions[8].option2, "Indian Ocean");
    strcpy(questions[8].option3, "Arctic Ocean");
    strcpy(questions[8].option4, "Pacific Ocean");
    questions[8].correct_answer = 4;

    // Question 10
    questions[9].question_id = 10;
    strcpy(questions[9].question_text, "What is the largest planet in the solar system?");
    strcpy(questions[9].option1, "Jupiter");
    strcpy(questions[9].option2, "Saturn");
    strcpy(questions[9].option3, "Mars");
    strcpy(questions[9].option4, "Venus");
    questions[9].correct_answer = 1;

    printf("Answer the following questions:\n\n");

    for(i = 0; i < 10; i++) {
        printf("%d. %s\n", questions[i].question_id, questions[i].question_text);
        printf("   A. %s\n", questions[i].option1);
        printf("   B. %s\n", questions[i].option2);
        printf("   C. %s\n", questions[i].option3);
        printf("   D. %s\n", questions[i].option4);

        printf("Your answer: ");
        scanf("%d", &selected_answer);

        if(selected_answer == questions[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong!\n");
        }

        printf("\n");
    }

    printf("Your final score is %d out of 10\n", score);

    return 0;
}