//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Structure to hold the quiz question and answer
typedef struct question_answer {
    char question[100];
    char answer[3];
} QA;

int main() {
    int num_questions = 15; // Number of questions in the quiz
    QA quiz[num_questions]; // Array to hold the quiz questions and answers
    int score = 0; // Initialize score to 0

    // Questions and answers for the quiz
    strcpy(quiz[0].question, "What is the symbol for Hydrogen?");
    strcpy(quiz[0].answer, "H");
    strcpy(quiz[1].question, "What is the symbol for Silicon?");
    strcpy(quiz[1].answer, "Si");
    strcpy(quiz[2].question, "What is the symbol for Carbon?");
    strcpy(quiz[2].answer, "C");
    strcpy(quiz[3].question, "What is the symbol for Oxygen?");
    strcpy(quiz[3].answer, "O");
    strcpy(quiz[4].question, "What is the symbol for Nitrogen?");
    strcpy(quiz[4].answer, "N");
    strcpy(quiz[5].question, "What is the symbol for Gold?");
    strcpy(quiz[5].answer, "Au");
    strcpy(quiz[6].question, "What is the symbol for Mercury?");
    strcpy(quiz[6].answer, "Hg");
    strcpy(quiz[7].question, "What is the symbol for Lead?");
    strcpy(quiz[7].answer, "Pb");
    strcpy(quiz[8].question, "What is the symbol for Iron?");
    strcpy(quiz[8].answer, "Fe");
    strcpy(quiz[9].question, "What is the symbol for Copper?");
    strcpy(quiz[9].answer, "Cu");
    strcpy(quiz[10].question, "What is the symbol for Magnesium?");
    strcpy(quiz[10].answer, "Mg");
    strcpy(quiz[11].question, "What is the symbol for Sodium?");
    strcpy(quiz[11].answer, "Na");
    strcpy(quiz[12].question, "What is the symbol for Chlorine?");
    strcpy(quiz[12].answer, "Cl");
    strcpy(quiz[13].question, "What is the symbol for Potassium?");
    strcpy(quiz[13].answer, "K");
    strcpy(quiz[14].question, "What is the symbol for Zinc?");
    strcpy(quiz[14].answer, "Zn");

    srand(time(NULL)); // Seed the random number generator

    // Shuffle the quiz questions
    for(int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions;
        QA temp = quiz[i];
        quiz[i] = quiz[j];
        quiz[j] = temp;
    }

    // Start the quiz and display each question
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be asked %d multiple choice questions.\n", num_questions);

    for(int i = 0; i < num_questions; i++) {
        printf("\n%d. %s\n", i+1, quiz[i].question);
        printf("Enter your answer: ");
        char user_answer[3];
        scanf("%s", user_answer);

        // Check if the answer is correct and update the score
        if(strcmp(user_answer, quiz[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %s.\n", quiz[i].answer);
        }
    }

    // Display the final score
    printf("\nCongratulations, you finished the quiz!\n");
    printf("Your final score is %d/%d.\n", score, num_questions);

    return 0;
}