//FormAI DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random function
    
    int randomTemp = (rand() % 20) - 10; // generates random temperature from -10 to 10
    
    // prints temperature and condition based on temperature
    printf("Today's temperature is %d degrees Celsius.\n", randomTemp);
    if (randomTemp < 0) {
        printf("It's freezing cold outside!");
    } else if (randomTemp < 10) {
        printf("It's chilly outside.");
    } else {
        printf("It's a beautiful day!");
    }
    
    return 0;
}