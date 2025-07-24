//FormAI DATASET v1.0 Category: Online Examination System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

// Structure definition for questions
struct question{
    char q[150]; // Maximum character limit for each question is set to 150
    char options[4][50]; // Maximum character limit for each option is set to 50
    char answer;
};

// Function to create new question
void new_question(struct question q[], int n){
    printf("\nEnter the question: "); // Prompt to enter the question
    fflush(stdin); // Flush the input buffer
    fgets(q[n].q, 150, stdin); // Read the question
    printf("\nEnter option A: "); // Prompt to enter option A
    fflush(stdin); // Flush the input buffer
    fgets(q[n].options[0], 50, stdin); // Read option A
    printf("Enter option B: "); // Prompt to enter option B
    fflush(stdin); // Flush the input buffer
    fgets(q[n].options[1], 50, stdin); // Read option B
    printf("Enter option C: "); // Prompt to enter option C
    fflush(stdin); // Flush the input buffer
    fgets(q[n].options[2], 50, stdin); // Read option C
    printf("Enter option D: "); // Prompt to enter option D
    fflush(stdin); // Flush the input buffer
    fgets(q[n].options[3], 50, stdin); // Read option D
    printf("Enter the answer (A/B/C/D): "); // Prompt to enter the answer
    fflush(stdin); // Flush the input buffer
    scanf("%c", &q[n].answer); // Read the answer
}

// Function to display the questions and options
void display_question(struct question q){
    printf("\n%s\n", q.q); // Print the question
    printf("A. %s", q.options[0]); // Print option A
    printf("B. %s", q.options[1]); // Print option B
    printf("C. %s", q.options[2]); // Print option C
    printf("D. %s", q.options[3]); // Print option D
}

// Function to take the test
void take_test(struct question q[], int n){
    char choice;
    int score = 0;
    for(int i=0; i<n; i++){
        printf("\n\nQuestion %d:", i+1);
        display_question(q[i]); // Display the question
        printf("\nEnter your choice (A/B/C/D): "); // Prompt to enter the answer
        fflush(stdin); // Flush the input buffer
        scanf("%c", &choice); // Read the answer
        if(choice == q[i].answer) // Check if the answer is correct
            score++;
    }
    printf("\n\nYour score is %d/%d", score, n); // Display the score
}

// Main function
int main(){
    int n, menu_choice;
    printf("***** Welcome to the Online Examination System *****\n");
    printf("\nEnter the number of questions for the test: ");
    scanf("%d", &n); // Read the number of questions
    struct question q[n]; // Create an array of questions
    for(int i=0; i<n; i++)
        new_question(q, i); // Create a new question
    do{
        printf("\n\n********** MENU **********\n");
        printf("1. Display test questions\n");
        printf("2. Take the test\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice); // Read the menu choice
        switch(menu_choice){
            case 1:
                for(int i=0; i<n; i++)
                    display_question(q[i]); // Display the questions and options
                break;
            case 2:
                take_test(q, n); // Take the test
                break;
            case 3:
                printf("\nThank you for taking the test.\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }while(menu_choice != 3); // Loop until the menu choice is 3
    return 0;
}