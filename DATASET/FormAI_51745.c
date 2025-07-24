//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

void happy_error_handling(int num)
{
    if(num > 5)
    {
        printf("Oh no, the number is too big! Let's try a smaller one.\n");
        exit(1);
    }
    else if(num < 0)
    {
        printf("Oopsies, the number is negative! Let's try a positive one instead.\n");
        exit(1);
    }
    else
    {
        printf("Yay, the number is just perfect!\n");
    }
}

int main()
{
    int number;
    printf("Hello! Let's do some happy error handling. Enter a number between 0 and 5:\n");
    scanf("%d", &number);

    happy_error_handling(number);

    printf("We did it! Congratulate yourself on your excellent number picking skills.\n");
    return 0;
}