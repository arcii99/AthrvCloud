//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

//Structure to hold question and answer information
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][30];
    int correct_option;
} Question;

//Function to create a new question
Question createQuestion(char* question, char* option1, char* option2, char* option3, char* option4, int correct_option) {
    Question q;
    strcpy(q.question, question);
    strcpy(q.options[0], option1);
    strcpy(q.options[1], option2);
    strcpy(q.options[2], option3);
    strcpy(q.options[3], option4);
    q.correct_option = correct_option;
    return q;
}

//Function to display the question and options
void displayQuestion(Question q) {
    printf("\n%s\n", q.question);
    for(int i=0; i<MAX_OPTIONS; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
}

int main() {
    //Create an array of questions
    Question questions[MAX_QUESTIONS];
    questions[0] = createQuestion("What is the symbol for Oxygen?", "Ox", "O", "Oy", "Om", 2);
    questions[1] = createQuestion("Which element is a metalloid?", "Aluminum", "Sulfur", "Silicon", "Carbon", 3);
    questions[2] = createQuestion("Which gas is known as laughing gas?", "Methane", "Nitrogen", "Oxygen", "Nitrous oxide", 4);
    questions[3] = createQuestion("What is the atomic number of Sodium?", "11", "22", "33", "44", 1);
    questions[4] = createQuestion("Which is the most abundant gas in the atmosphere?", "Carbon dioxide", "Nitrogen", "Oxygen", "Helium", 2);
    questions[5] = createQuestion("What is the symbol for Hyrdogen?", "H", "Ho", "Hg", "He", 1);
    questions[6] = createQuestion("Which element is used in making semiconductor devices?", "Copper", "Iron", "Silicon", "Gold", 3);
    questions[7] = createQuestion("What is the atomic number of Chlorine?", "15", "17", "22", "28", 2);
    questions[8] = createQuestion("What is the symbol for Zinc?", "Zn", "Zi", "Zc", "Za", 1);
    questions[9] = createQuestion("Which element is used in making pencils?", "Aluminum", "Graphite", "Phosphorus", "Lead", 2);

    //Initialize variables
    int score = 0, choice, correct_answer;
    srand(time(NULL));

    //Display welcome message and instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be presented with %d questions.\n", MAX_QUESTIONS);
    printf("Select the correct answer from the available options (1-4).\n");
    printf("Good luck!\n");

    //Loop over the questions and ask them
    for(int i=0; i<MAX_QUESTIONS; i++) {
        //Get a random question from the array
        int question_number = rand() % MAX_QUESTIONS;
        Question current_question = questions[question_number];
        displayQuestion(current_question);

        printf("Select your answer: ");
        scanf("%d", &choice);

        correct_answer = current_question.correct_option;
        if(choice == correct_answer) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect! The correct answer is %d\n", correct_answer);
        }
    }

    //Display final score and message
    printf("You got %d out of %d questions correct.\n", score, MAX_QUESTIONS);
    if(score == MAX_QUESTIONS) {
        printf("Congratulations, you got a perfect score!\n");
    }
    else if(score >= MAX_QUESTIONS/2) {
        printf("Not bad, keep practicing!\n");
    }
    else {
        printf("Better luck next time!\n");
    }

    return 0;
}