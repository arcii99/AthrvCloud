//FormAI DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define global variables
int num_questions = 10;
int num_options = 4;
int score = 0;

// Define question structure
struct question {
    char prompt[100];
    char options[4][50];
    int answer;
};

// Define function to shuffle array
void shuffle_array(int arr[], int n) {
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Define function to generate questions
void generate_questions(struct question* questions) {
    // Populate questions and answers
    
    // Shuffle question order
    int question_order[num_questions];
    for (int i = 0; i < num_questions; i++) {
        question_order[i] = i;
    }
    shuffle_array(question_order, num_questions);
    
    // Print questions and ask for answers
    printf("Welcome to the C Online Examination System.\n");
    printf("Please answer the following %d questions:\n", num_questions);
    for (int i = 0; i < num_questions; i++) {
        int idx = question_order[i];
        printf("\n%s\n", questions[idx].prompt);
        for (int j = 0; j < num_options; j++) {
            printf("%d. %s\n", j + 1, questions[idx].options[j]);
        }
        printf("Enter your answer: ");
        int answer;
        scanf("%d", &answer);
        if (answer == questions[idx].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", questions[idx].answer);
        }
    }
    printf("\nYour score is %d/%d.\n", score, num_questions);
}

// Define main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Define questions
    struct question questions[num_questions];
    strcpy(questions[0].prompt, "What is the output of the following code?\nint x = 5;\nprintf(\"%d\", x);");
    strcpy(questions[0].options[0], "5");
    strcpy(questions[0].options[1], "0");
    strcpy(questions[0].options[2], "1");
    strcpy(questions[0].options[3], "Undefined");
    questions[0].answer = 1;
    
    // Generate questions
    generate_questions(questions);

    return 0;
}