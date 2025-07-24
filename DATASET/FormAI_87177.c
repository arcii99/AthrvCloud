//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This is an Online Examination System that tests a user's knowledge of the C programming language.
    It consists of 10 multiple choice questions that measure the user's understanding of basic to intermediate C concepts.
    The system generates a random set of questions each time it is taken to prevent cheating.
*/

// Struct to hold question information
typedef struct Question {
    char question[256];
    char choices[4][64];
    int answer;
} Question;

// Function to generate a random set of questions
void generateQuestions(Question* questions) {
    // Array of possible questions
    char questionBank[10][256] = {
        "What is the output of 'printf(\"%d\", 5/2);'?\n",
        "What is the keyword used to define a variable in C?\n",
        "What is the correct syntax of a for loop in C?\n",
        "What is the difference between 'while' and 'do-while' loops?\n",
        "What is the output of 'printf(\"%d\", !0);'?\n",
        "What is the output of 'printf(\"%d\", 2 == 3);'?\n",
        "What is the keyword used to define a function in C?\n",
        "What is the correct syntax of a switch statement in C?\n",
        "What is the difference between a float and a double in C?\n",
        "What is the output of 'printf(\"%d\", 1 && 0);'?\n"
    };

    // Array of possible choices
    char choiceBank[10][4][64] = {
        {"2\n", "2.5\n", "3\n", "2.0\n"},
        {"var\n", "int\n", "float\n", "none of the above\n"},
        {"for(i = 0; i < n; i++) {}\n", "for i = 0, i < n, i++ {}\n", "for(int i = 0; i < n; i++) {}\n", "for(i <= 0; i < n; i++) {}\n"},
        {"while loops execute at least once, do-while loops may not execute at all\n", "while loops may not execute at all, do-while loops execute at least once\n", "while and do-while loops are identical\n", "none of the above\n"},
        {"1\n", "0\n", "true\n", "false\n"},
        {"0\n", "1\n", "true\n", "false\n"},
        {"def\n", "function\n", "func\n", "none of the above\n"},
        {"switch(var) { case 1: break; default: break; }\n", "switch case 1: break; default: break; }\n", "switch(1) { case var: break; default: break; }\n", "none of the above\n"},
        {"floats have more precision than doubles\n", "doubles have more precision than floats\n", "floats and doubles are identical\n", "none of the above\n"},
        {"1\n", "0\n", "true\n", "false\n"},
    };

    // Array of correct answers
    int answerBank[10] = {
        0, 1, 2, 1, 1, 3, 1, 0, 1, 1
    };

    // Generate random set of 5 questions
    int usedQuestions[5];
    for(int i = 0; i < 5; i++) {
        int randomQuestion = rand() % 10;
        if(i > 0) {
            // Ensure no duplicate questions
            while (1) {
                int j;
                for (j = 0; j < i; j++) {
                    if (randomQuestion == usedQuestions[j]) {
                        break;
                    }
                }
                if (j == i) {
                    break;
                }
                randomQuestion = rand() % 10;
            }
        }
        usedQuestions[i] = randomQuestion;
        strcpy(questions[i].question, questionBank[randomQuestion]);
        for(int j = 0; j < 4; j++) {
            strcpy(questions[i].choices[j], choiceBank[randomQuestion][j]);
        }
        questions[i].answer = answerBank[randomQuestion];
    }
}

int main() {
    printf("Welcome to the C Programming Language Online Exam!\n\n");

    // Generate questions
    Question questions[5];
    generateQuestions(questions);

    // Quiz loop
    int score = 0;
    for(int i = 0; i < 5; i++) {
        printf("Question %d:\n%s\n", i+1, questions[i].question);
        for(int j = 0; j < 4; j++) {
            printf("%d. %s", j+1, questions[i].choices[j]);
        }
        printf("Enter your answer (1-4): ");
        int answer;
        scanf("%d", &answer);
        printf("\n");
        if(answer == questions[i].answer+1) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", questions[i].answer+1);
        }
    }

    // Display final score
    printf("You scored %d out of 5.\n", score);

    return 0;
}