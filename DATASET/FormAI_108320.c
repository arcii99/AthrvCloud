//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include<stdio.h>
int main()
{
    int n, q; // n = number of questions, q = number of questions attempted by the student
    printf("Enter the number of questions in the exam: ");
    scanf("%d", &n);
    printf("Enter the number of questions attempted by the student: ");
    scanf("%d", &q);
    int correct_ans[q], student_ans[q]; // arrays to store correct answers and student's answers respectively
    printf("Enter the correct answers:\n");
    for(int i=0; i<q; i++)
    {
        printf("Question %d: ", i+1);
        scanf("%d", &correct_ans[i]);
    }
    printf("Enter the student's answers:\n");
    for(int i=0; i<q; i++)
    {
        printf("Question %d: ", i+1);
        scanf("%d", &student_ans[i]);
    }
    int marks = 0; // variable to store total marks scored by student
    for(int i=0; i<q; i++)
    {
        if(correct_ans[i] == student_ans[i])
            marks++;
    }
    float percentage = ((float)marks/q)*100; // calculating percentage of marks scored
    printf("Total marks scored by student: %d out of %d\n", marks, n);
    printf("Percentage of marks scored by student: %.2f%%", percentage);
    return 0;
}