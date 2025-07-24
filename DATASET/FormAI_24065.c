//FormAI DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants for the number of questions and the passing score
#define NUM_QUESTIONS 10
#define PASS_SCORE 7

// Define a structure to hold the question and its answers
typedef struct {
    char question[100];
    char options[4][50];
    int answer;
} Question;

// Function to get user input for each question
int getAnswer() {
    char str[10];
    printf("\nEnter the correct option: ");
    scanf("%s", str);
    int ans = atoi(str);
    return ans;
}

// Main function to execute the exam
int main() {
    // Declare an array of questions
    Question questions[NUM_QUESTIONS];
    
    // Add questions and their answers to the array
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "1. Paris");
    strcpy(questions[0].options[1], "2. London");
    strcpy(questions[0].options[2], "3. Madrid");
    strcpy(questions[0].options[3], "4. Berlin");
    questions[0].answer = 1;

    strcpy(questions[1].question, "What is the currency of Japan?");
    strcpy(questions[1].options[0], "1. Dollar");
    strcpy(questions[1].options[1], "2. Pound");
    strcpy(questions[1].options[2], "3. Yen");
    strcpy(questions[1].options[3], "4. Euro");
    questions[1].answer = 3;

    strcpy(questions[2].question, "What is the largest planet in our solar system?");
    strcpy(questions[2].options[0], "1. Saturn");
    strcpy(questions[2].options[1], "2. Venus");
    strcpy(questions[2].options[2], "3. Jupiter");
    strcpy(questions[2].options[3], "4. Mars");
    questions[2].answer = 3;

    strcpy(questions[3].question, "What is the powerhouse of the cell?");
    strcpy(questions[3].options[0], "1. Ribosomes");
    strcpy(questions[3].options[1], "2. Mitochondria");
    strcpy(questions[3].options[2], "3. Nucleus");
    strcpy(questions[3].options[3], "4. Chloroplasts");
    questions[3].answer = 2;

    strcpy(questions[4].question, "What is the atomic number of Oxygen?");
    strcpy(questions[4].options[0], "1. 8");
    strcpy(questions[4].options[1], "2. 16");
    strcpy(questions[4].options[2], "3. 20");
    strcpy(questions[4].options[3], "4. 14");
    questions[4].answer = 1;

    strcpy(questions[5].question, "What is the largest organ in the human body?");
    strcpy(questions[5].options[0], "1. Skin");
    strcpy(questions[5].options[1], "2. Heart");
    strcpy(questions[5].options[2], "3. Lungs");
    strcpy(questions[5].options[3], "4. Liver");
    questions[5].answer = 1;

    strcpy(questions[6].question, "What is the smallest country in the world?");
    strcpy(questions[6].options[0], "1. Monaco");
    strcpy(questions[6].options[1], "2. San Marino");
    strcpy(questions[6].options[2], "3. Vatican City");
    strcpy(questions[6].options[3], "4. Liechtenstein");
    questions[6].answer = 3;

    strcpy(questions[7].question, "Which country is known as the land of the rising sun?");
    strcpy(questions[7].options[0], "1. Thailand");
    strcpy(questions[7].options[1], "2. China");
    strcpy(questions[7].options[2], "3. Japan");
    strcpy(questions[7].options[3], "4. Vietnam");
    questions[7].answer = 3;

    strcpy(questions[8].question, "Who is the author of The Great Gatsby?");
    strcpy(questions[8].options[0], "1. Ernest Hemingway");
    strcpy(questions[8].options[1], "2. F. Scott Fitzgerald");
    strcpy(questions[8].options[2], "3. William Faulkner");
    strcpy(questions[8].options[3], "4. J.D. Salinger");
    questions[8].answer = 2;

    strcpy(questions[9].question, "What is the name of the world's largest ocean?");
    strcpy(questions[9].options[0], "1. Indian Ocean");
    strcpy(questions[9].options[1], "2. Atlantic Ocean");
    strcpy(questions[9].options[2], "3. Arctic Ocean");
    strcpy(questions[9].options[3], "4. Pacific Ocean");
    questions[9].answer = 4;

    // Declare variables to store exam results
    int score = 0;
    bool passed = false;
    
    // Display instructions for the exam and get user confirmation to proceed
    printf("Welcome to the C Online Exam System!\n");
    printf("You will have 10 minutes to complete the exam, and must score 70 percent or higher to pass.\n");
    printf("Do you wish to proceed?\n");
    printf("(Type 'y' for Yes and 'n' for No): ");
    char confirm[10];
    scanf("%s", confirm);
    
    // If user confirms, proceed with the exam
    if (strcmp(confirm, "y") == 0) {
        printf("\nBEGIN EXAM\n");
        printf("You will have 10 seconds per question.\n");
        printf("Good luck!\n");
        
        // Loop through each question and get user input
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            printf("\nQuestion %d:\n", i+1);
            printf("%s\n", questions[i].question);
            printf("%s\n", questions[i].options[0]);
            printf("%s\n", questions[i].options[1]);
            printf("%s\n", questions[i].options[2]);
            printf("%s\n", questions[i].options[3]);
            int ans = getAnswer();
            if (ans == questions[i].answer) {
                score++;
            }
        }
        
        // Calculate exam results and display them to the user
        float percentage = (float) score / NUM_QUESTIONS * 100;
        printf("\nEXAM COMPLETED\n");
        printf("Your score: %d/%d\n", score, NUM_QUESTIONS);
        printf("Percentage: %f%%\n", percentage);
        if (percentage >= PASS_SCORE * 10) {
            printf("Congratulations, you passed the exam!\n");
            passed = true;
        } else {
            printf("Sorry, you did not pass the exam.\n");
        }
    } else {
        printf("\nExam cancelled.\n");
    }

    // Display a personalized message of appreciation to the user
    if (passed) {
        printf("\nThank you for participating in our exam. We hope you found it to be a valuable learning experience!\n");
    } else {
        printf("\nWe are sorry that you did not pass our exam. We hope that you will continue to study and try again in the future.\n");
    }

    // End program
    return 0;
}