//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: excited
#include <stdio.h>

// function prototype
void delay(unsigned int);

int main()
{
    printf("Let's start the traffic light show! \n");

    // infinite loop
    while(1)
    {
        // RED light ON
        printf("\nRED Light ON! \n");
        delay(2000); // delay of 2 seconds

        // RED light OFF and YELLOW light ON
        printf("\nRED Light OFF! \nYELLOW Light ON! \n");
        delay(1000); // delay of 1 second

        // YELLOW light OFF and GREEN light ON
        printf("\nYELLOW Light OFF! \nGREEN Light ON! \n");
        delay(3000); // delay of 3 seconds

        // GREEN light OFF and YELLOW light ON
        printf("\nGREEN Light OFF! \nYELLOW Light ON! \n");
        delay(1000); // delay of 1 second

    }

    return 0;
}

// function definition
void delay(unsigned int n)
{
    for(int i=0; i<n*1000; i++);
}