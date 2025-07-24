//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main()
{
    int probability = 0;
    char name[20], response;
 
    printf("Hello there! What is your name? \n");
    scanf("%s", &name);
 
    printf("\nNice to meet you, %s! \n", name);
    printf("Are you worried about a potential alien invasion? (y/n): ");
    scanf(" %c", &response);
 
    if(response == 'y' || response == 'Y')
    {
        printf("\nDon't worry, I can help you calculate the probability of an alien invasion! \n");
        printf("Please wait while I process the data...\n");
        srand(time(0));
        probability = rand() % 100 + 1;
 
        printf("\nAlright, I have calculated the probability! \n");
        printf("The probability of an alien invasion is %d%% \n", probability);
 
        if(probability >= 95)
        {
            printf("Based on the data, I suggest you start preparing for an alien invasion!\n");
        }
        else if(probability >= 50 && probability < 95)
        {
            printf("The probability is moderate, so it may be a good idea to have a plan of action just in case. \n");
        }
        else
        {
            printf("The probability is relatively low, so there's probably no need to worry right now. \n");
        }
    }
    else
    {
        printf("\nAlright, have a great day %s!\n", name);
    }
    
    return 0;
}