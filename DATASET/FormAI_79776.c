//FormAI DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include<stdio.h>

void main()
{
    int i, j, num_of_questions, num_of_students, total_score;
    printf("Welcome to the online examination system!\n");

    printf("How many questions are on the test?\n");
    scanf("%d", &num_of_questions);

    printf("How many students are taking the test?\n");
    scanf("%d", &num_of_students);

    int correct_answers[num_of_questions];
    char student_answers[num_of_students][num_of_questions];

    // Input correct answers from the teacher
    for(i = 0; i < num_of_questions; i++)
    {
        printf("Enter the correct answer for question %d:\n", i+1);
        scanf(" %c", &correct_answers[i]);
    }

    // Input student answers
    for(i = 0; i < num_of_students; i++)
    {
        printf("Enter the answers for student %d:\n", i+1);
        for(j = 0; j < num_of_questions; j++)
        {
            scanf(" %c", &student_answers[i][j]);
        }
    }

    // Check student answers and calculate scores
    for(i = 0; i < num_of_students; i++)
    {
        total_score = 0;
        for(j = 0; j < num_of_questions; j++)
        {
            if(student_answers[i][j] == correct_answers[j])
            {
                total_score++;
            }
        }
        printf("Total score for student %d is %d/%d\n", i+1, total_score, num_of_questions);
    }

    printf("Thank you for using the online examination system!\n");
}