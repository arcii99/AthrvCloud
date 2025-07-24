//FormAI DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    char options[4][50];
    char answer;
};

// Function to display a single question
void displayQuestion(struct Question q) {
    printf("%s\n", q.question);
    for(int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, q.options[i]);
    }
}

// Function to read the answer from the user
char readAnswer() {
    char answer;
    do {
        printf("Enter your answer [A/B/C/D]: ");
        scanf(" %c", &answer);
    } while(answer < 'A' || answer > 'D');
    return answer;
}

int main() {
    // Initialize the questions
    struct Question questions[5];
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "Paris");
    strcpy(questions[0].options[1], "Madrid");
    strcpy(questions[0].options[2], "Berlin");
    strcpy(questions[0].options[3], "Rome");
    questions[0].answer = 'A';

    strcpy(questions[1].question, "What is the largest country in the world by area?");
    strcpy(questions[1].options[0], "China");
    strcpy(questions[1].options[1], "Russia");
    strcpy(questions[1].options[2], "USA");
    strcpy(questions[1].options[3], "India");
    questions[1].answer = 'B';

    strcpy(questions[2].question, "What is the currency of Japan?");
    strcpy(questions[2].options[0], "Dollar");
    strcpy(questions[2].options[1], "Euro");
    strcpy(questions[2].options[2], "Pound");
    strcpy(questions[2].options[3], "Yen");
    questions[2].answer = 'D';

    strcpy(questions[3].question, "What is the largest ocean in the world?");
    strcpy(questions[3].options[0], "Atlantic Ocean");
    strcpy(questions[3].options[1], "Indian Ocean");
    strcpy(questions[3].options[2], "Arctic Ocean");
    strcpy(questions[3].options[3], "Pacific Ocean");
    questions[3].answer = 'D';

    strcpy(questions[4].question, "What is the main language spoken in Brazil?");
    strcpy(questions[4].options[0], "Portuguese");
    strcpy(questions[4].options[1], "Spanish");
    strcpy(questions[4].options[2], "French");
    strcpy(questions[4].options[3], "Italian");
    questions[4].answer = 'A';

    // Initialize the score
    int score = 0;

    // Display the questions and read the answers
    for(int i = 0; i < 5; i++) {
        printf("\nQuestion #%d:\n", i + 1);
        displayQuestion(questions[i]);
        char answer = readAnswer();
        if(answer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c) %s\n", questions[i].answer, questions[i].options[questions[i].answer - 'A']);
        }
    }

    // Display the score
    printf("\nYour score is: %d out of 5\n", score);

    return 0;
}