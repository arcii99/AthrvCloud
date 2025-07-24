//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char* theories[] = {"The moon landing was faked", "Aliens are living among us", "Climate change is a hoax", "The government is controlled by reptilian shape shifters", "Vaccines cause autism", "Chemtrails are being used to control the population", "The earth is flat", "9/11 was an inside job"};
    int numTheories = 8;
    srand(time(NULL));
    int randomIndex = rand() % numTheories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    printf("Here's your conspiracy theory: %s\n", theories[randomIndex]);

    return 0;
}