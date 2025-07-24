//FormAI DATASET v1.0 Category: Educational ; Style: funny
#include <stdio.h>

int main()
{
    int num_students;
    printf("How many students are in the class? ");
    scanf("%d", &num_students);

    printf("\n");

    printf("Great! Let's give them all a grade...\n\n");

    for (int i = 1; i <= num_students; i++)
    {
        printf("Student %d, what grade did you get on the exam? ", i);

        int grade;
        scanf("%d", &grade);

        if (grade >= 90)
        {
            printf("A? More like Aye-aye-aye! Well done, Student %d!\n\n", i);
        }
        else if (grade >= 80)
        {
            printf("B? More like Beeeeeeeee-autiful! Great job, Student %d!\n\n", i);
        }
        else if (grade >= 70)
        {
            printf("C? More like See Green! Keep it up, Student %d!\n\n", i);
        }
        else if (grade >= 60)
        {
            printf("D? More like Don't Give Up! You can do this, Student %d!\n\n", i);
        }
        else
        {
            printf("F? More like Fantastic Effort! Keep trying, Student %d!\n\n", i);
        }
    }

    printf("Thanks for grading, Professor Bot out!\n");

    return 0;
}