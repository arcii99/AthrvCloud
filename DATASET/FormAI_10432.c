//FormAI DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>

void main() {
    
    int correct_answers = 0;
    int total_questions = 10;
    char student_answer;
    
    printf("\nWelcome to the C Online Examination System!\n\n");
    printf("Please answer the following questions:\n");
    
    printf("\n1. What year was C Programming Language created?\n");
    printf("a) 1970   b) 1980   c) 1990\n");
    scanf(" %c", &student_answer);
    if(student_answer == 'a') {
        correct_answers++;
    }
    
    // continue with 8 more questions
    
    float percentage = (float)correct_answers / total_questions * 100;
    printf("\nThank you for taking the exam!\n");
    printf("You scored %d out of %d (%.2f%%)\n\n", correct_answers, total_questions, percentage);
    
    if(percentage >= 60) {
        printf("Congratulations! You have passed the exam!\n");
    } else {
        printf("Sorry, you did not pass the exam. Better luck next time.\n");
    }
}