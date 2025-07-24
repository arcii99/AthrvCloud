//FormAI DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    int num_questions = 5;
    char answer_key[num_questions + 1];
    char student_answers[num_questions + 1];
    int correct_count = 0;
    int i;
    
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the answer key:\n");
    
    for(i = 1; i <= num_questions; i++)
    {
        printf("Enter the correct answer for question %d: ", i);
        scanf(" %c", &answer_key[i]);
    }
    
    printf("Answer key saved successfully!\n");
    
    printf("Please enter the student's answers:\n");
    
    for(i = 1; i <= num_questions; i++)
    {
        printf("Enter the answer for question %d: ", i);
        scanf(" %c", &student_answers[i]);
    }
    
    printf("Student's answers saved successfully!\n");
    
    for(i = 1; i <= num_questions; i++)
    {
        if(student_answers[i] == answer_key[i])
        {
            correct_count++;
        }
    }
    
    printf("The student answered %d questions correctly out of %d.\n", correct_count, num_questions);
    
    return 0;
}