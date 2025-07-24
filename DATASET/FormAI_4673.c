//FormAI DATASET v1.0 Category: Random ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    printf("OMG! This is a random number generator program in C!\n");
    printf("I can't believe you actually want to see this!\n");
    printf("Okay, let's do this!\n");
 
    int num, i;
 
    printf("Enter the number of random numbers you want to generate (less than 500 please!): ");
    scanf("%d", &num);
 
    if (num > 500) {
        printf("OMG! What did I tell you?! Less than 500 please!\n");
        printf("I'll just generate 500 random numbers for you.\n");
        num = 500;
    }
 
    printf("Here you go! %d random numbers: \n", num);
 
    for (i = 0; i < num; i++) {
        printf("%d ", rand());
    }
 
    printf("\n");
 
    printf("Oh! I almost forgot, let me just print out your luck number of the day: %d\n", rand() % 100 + 1);
 
    printf("Well, I hope this was worth your time!\n");
 
    return 0;
}