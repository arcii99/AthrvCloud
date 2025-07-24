//FormAI DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int questionId;
    char question[100];
    char option1[50], option2[50], option3[50], option4[50];
    int correctOption;
}Question;

void displayInstructions(){
    printf("\n\n********** Welcome to the Online Examination System **********\n\n");
    printf("Instructions: \n");
    printf("1. This exam consists of 20 questions. \n");
    printf("2. Each question carries 5 marks. \n");
    printf("3. There is no negative marking for wrong answers. \n");
    printf("4. Enter the appropriate option number (1-4) as your answer and press enter. \n");
    printf("5. All the best! \n\n");
}

void loadQuestions(Question questions[]){
    Question q1 = {1, "What is the capital of India?", "Delhi", "Mumbai", "Kolkata", "Chennai", 1};
    Question q2 = {2, "What is the national animal of India?", "Lion", "Tiger", "Elephant", "Deer", 2};
    Question q3 = {3, "What is the smallest continent in the world?", "North America", "South America", "Europe", "Australia", 4};
    Question q4 = {4, "What is the largest planet in our solar system?", "Venus", "Saturn", "Jupiter", "Mars", 3};
    Question q5 = {5, "Which company created the iPhone?", "Microsoft", "Apple", "Samsung", "Sony", 2};
    
    questions[0] = q1;
    questions[1] = q2;
    questions[2] = q3;
    questions[3] = q4;
    questions[4] = q5;
}

int generateRandomNumber(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void shuffleQuestions(Question questions[], int numberOfQuestions){
    for(int i=0; i<numberOfQuestions; i++){
        int randomIndex = generateRandomNumber(0, numberOfQuestions-1);
        Question temp = questions[randomIndex];
        questions[randomIndex] = questions[i];
        questions[i] = temp;
    }
}

void displayQuestions(Question questions[], int numberOfQuestions){
    printf("\n\n********** Exam Questions **********\n\n");
    for(int i=0; i<numberOfQuestions; i++){
        printf("%d. %s\n", i+1, questions[i].question);
        printf("   1. %s\n", questions[i].option1);
        printf("   2. %s\n", questions[i].option2);
        printf("   3. %s\n", questions[i].option3);
        printf("   4. %s\n", questions[i].option4);
    }
}

int getAnswer(){
    int answer;
    scanf("%d", &answer);
    return answer;
}

int calculateScore(Question questions[], int numberOfQuestions, int answers[]){
    int score = 0;
    for(int i=0; i<numberOfQuestions; i++){
        if(answers[i] == questions[i].correctOption){
            score += 5;
        }
    }
    return score;
}

void displayResult(int score){
    printf("\n\n********** Exam Results **********\n\n");
    printf("Your score is: %d / 100", score);
}

int main(){
    int numberOfQuestions = 5;
    Question questions[numberOfQuestions];
    int answers[numberOfQuestions];
    loadQuestions(questions);
    shuffleQuestions(questions, numberOfQuestions);
    displayInstructions();
    displayQuestions(questions, numberOfQuestions);
    printf("\n\n********** Exam Begins **********\n\n");
    for(int i=0; i<numberOfQuestions; i++){
        printf("\nQuestion %d: ", i+1);
        answers[i] = getAnswer();
    }
    int score = calculateScore(questions, numberOfQuestions, answers);
    displayResult(score);
    return 0;
}