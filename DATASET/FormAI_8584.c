//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>

// function prototypes
void redLight();
void yellowLight();
void greenLight();

int main()
{
    int count = 10; // set count to 10
    
    while (count > 0) // loop while count is greater than 0
    {
        redLight(); // red light for 5 seconds
        yellowLight(); // yellow light for 2 seconds
        greenLight(); // green light for 5 seconds
        
        count--; // decrement count by 1
    }
    
    return 0;
}

// function to turn on red light
void redLight()
{
    printf("Red Light!\n");
    // code to turn on red light
    sleep(5); // wait for 5 seconds
}

// function to turn on yellow light
void yellowLight()
{
    printf("Yellow Light!\n");
    // code to turn on yellow light
    sleep(2); // wait for 2 seconds
}

// function to turn on green light
void greenLight()
{
    printf("Green Light!\n");
    // code to turn on green light
    sleep(5); // wait for 5 seconds
}