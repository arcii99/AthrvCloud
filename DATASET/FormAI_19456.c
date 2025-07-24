//FormAI DATASET v1.0 Category: Math exercise ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    int num1 = rand() % 100;
    int num2 = rand() % 100;
    
    printf("Welcome to the Surreal Math Game!\n");
    printf("Please solve the following equation:\n\n");
    printf("%d + %d = ?\n", num1, num2);
    
    int ans;
    scanf("%d", &ans);
    
    if(ans == num1 + num2)
    {
        printf("\nCongratulations! You have discovered the hidden meaning of the universe.\n");
        printf("Your prize is a giant squid that will follow you around for the rest of your days.\n");
        printf("Please be careful not to get ink on your clothes.\n");
    }
    else
    {
        printf("\nI'm sorry, but that answer is incorrect.\n");
        printf("The correct answer is %d.\n", num1 + num2);
        printf("Please try again and remember that the truth is often stranger than fiction.\n");
    }
    
    return 0;
}