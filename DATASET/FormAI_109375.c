//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Hello! Welcome to the joyful math exercise program!\n");
    printf("Let's practice some addition and multiplication together!\n\n");
    
    int a, b, c, ans, userAns, correctAnswers = 0, totalQuestions = 0;
    char choice;
    srand(time(0)); //initialize random seed
    
    while(1)
    {
        a = rand()%100; //random number between 0 and 99
        b = rand()%100;
        c = rand()%10; //random number between 0 and 9
        
        printf("What is %d + %d * %d?\n", a, b, c);
        ans = a + b * c;
        scanf("%d", &userAns);
        
        if(userAns == ans)
        {
            printf("Great job! You got it right!\n");
            correctAnswers++;
        }
        else
        {
            printf("Oops! The correct answer is %d.\n", ans);
        }
        
        totalQuestions++;
        
        printf("Do you want to continue? (Y/N)\n");
        scanf(" %c", &choice);
        if(choice == 'N' || choice == 'n')
        {
            printf("Thank you for practicing with me!\n");
            printf("You answered %d out of %d questions correctly.\n", correctAnswers, totalQuestions);
            break;
        }
    }
    
    return 0;
}