//FormAI DATASET v1.0 Category: Online Examination System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Define the structure for the question */
struct Question {
    int qNum;
    char question[500];
    char options[4][100];
    int correctOption;
};

/* Define the structure for the student */
struct Student {
    char name[50];
    int id;
    int score;
};

int main() {
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Define the questions */
    struct Question questions[5];
    questions[0].qNum = 1;
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "A. Paris");
    strcpy(questions[0].options[1], "B. London");
    strcpy(questions[0].options[2], "C. Madrid");
    strcpy(questions[0].options[3], "D. Rome");
    questions[0].correctOption = 0;
    
    questions[1].qNum = 2;
    strcpy(questions[1].question, "What is the largest planet in our solar system?");
    strcpy(questions[1].options[0], "A. Earth");
    strcpy(questions[1].options[1], "B. Mars");
    strcpy(questions[1].options[2], "C. Jupiter");
    strcpy(questions[1].options[3], "D. Venus");
    questions[1].correctOption = 2;
    
    questions[2].qNum = 3;
    strcpy(questions[2].question, "What is the smallest country in the world?");
    strcpy(questions[2].options[0], "A. Monaco");
    strcpy(questions[2].options[1], "B. Vatican City");
    strcpy(questions[2].options[2], "C. San Marino");
    strcpy(questions[2].options[3], "D. Liechtenstein");
    questions[2].correctOption = 1;
    
    questions[3].qNum = 4;
    strcpy(questions[3].question, "What is the chemical symbol for gold?");
    strcpy(questions[3].options[0], "A. G");
    strcpy(questions[3].options[1], "B. A");
    strcpy(questions[3].options[2], "C. Au");
    strcpy(questions[3].options[3], "D. Ag");
    questions[3].correctOption = 2;
    
    questions[4].qNum = 5;
    strcpy(questions[4].question, "Who wrote the novel 'War and Peace'?");
    strcpy(questions[4].options[0], "A. Leo Tolstoy");
    strcpy(questions[4].options[1], "B. Fyodor Dostoevsky");
    strcpy(questions[4].options[2], "C. Anton Chekhov");
    strcpy(questions[4].options[3], "D. Vladimir Nabokov");
    questions[4].correctOption = 0;
    
    /* Define the student */
    struct Student student;
    printf("Welcome to the Online Examination System!\n\n");
    printf("Enter your name: ");
    fgets(student.name, 50, stdin);
    printf("Enter your ID number: ");
    scanf("%d", &student.id);
    
    /* Take the exam */
    printf("\n\n%s, let's begin the exam!\n", student.name);
    printf("You will be given 5 multiple-choice questions.\n");
    printf("Each question has 4 options, and you must select the correct one.\n");
    printf("Good luck!\n\n");
    
    int score = 0;
    for(int i = 0; i < 5; i++) {
        int randomIndex = rand() % 5;
        struct Question question = questions[randomIndex];
        printf("Question %d: %s\n", i+1, question.question);
        for(int j = 0; j < 4; j++) {
            printf("%s\n", question.options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if(answer == question.correctOption + 1) {
            score++;
            printf("Great job! You got that one right.\n\n");
        }
        else {
            printf("Sorry, that's incorrect.\n\n");
        }
    }
    student.score = score;
    printf("Congratulations, %s! You have completed the exam.\n", student.name);
    printf("Your score is %d out of 5.\n", student.score);
    
    return 0;
}