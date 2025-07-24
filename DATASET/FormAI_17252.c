//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count=0;
    char input;
    printf("Welcome to the Traffic Light Controller Program!\n");
    printf("Press 's' to start the program.\n");
    scanf("%c", &input);
    
    while(input!='s')
    {
        printf("Invalid input. Press 's' to start the program.\n");
        scanf("%c", &input);
    }
    
    printf("Starting the program...\n");
    printf("Traffic light controller starting in 3... 2... 1...\n");
    
    while(count<10)
    {
        printf("\n***COUNT %d***\n", count);
        printf("RED!\n");
        count++;
        sleep(2);
        printf("RED AND YELLOW!\n");
        sleep(1);
        printf("GREEN!\n");
        sleep(2);
        printf("YELLOW!\n");
        sleep(1);
    }
    
    printf("\n***COUNT %d***\n", count);
    printf("RED!\n");
    printf("Program complete.\n");
    
    return 0;
}