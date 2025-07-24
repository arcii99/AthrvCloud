//FormAI DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char content[100];
    char answer[50];
};

int main() {
    struct Question questions[10]; // A total of 10 questions
    int i, score = 0;

    // Set the questions and answers
    strcpy(questions[0].content, "What is the capital city of China?");
    strcpy(questions[0].answer, "Beijing");

    strcpy(questions[1].content, "What is the largest country in the world?");
    strcpy(questions[1].answer, "Russia");

    strcpy(questions[2].content, "What is the currency of Japan?");
    strcpy(questions[2].answer, "Yen");

    strcpy(questions[3].content, "Which language is not officially spoken in Switzerland?");
    strcpy(questions[3].answer, "French");

    strcpy(questions[4].content, "What is the currency of United Arab Emirates?");
    strcpy(questions[4].answer, "Dirham");

    strcpy(questions[5].content, "What is the currency of South Africa?");
    strcpy(questions[5].answer, "Rand");

    strcpy(questions[6].content, "What does CPU stand for?");
    strcpy(questions[6].answer, "Central Processing Unit");

    strcpy(questions[7].content, "What is the smallest planet in our solar system?");
    strcpy(questions[7].answer, "Mercury");

    strcpy(questions[8].content, "What is the most abundant gas in the Earth's atmosphere?");
    strcpy(questions[8].answer, "Nitrogen");

    strcpy(questions[9].content, "What is the largest organ in the human body?");
    strcpy(questions[9].answer, "Skin");
    
    // Start the quiz
    printf("Welcome to the Online Quiz!\n");
    printf("You will be asked 10 questions, one at a time. Good luck!\n\n");

    // Ask the questions and check the answers
    for (i = 0; i < 10; i++) {
        char userAnswer[50];
        printf("Question %d: %s\n", i+1, questions[i].content);
        printf("Your answer: ");
        scanf("%s", userAnswer);

        if (strcmp(userAnswer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", questions[i].answer);
        }
        printf("\n");
    }

    // Show the final score
    printf("Quiz complete! You got %d out of 10 questions correct.\n\n", score);

    return 0;
}