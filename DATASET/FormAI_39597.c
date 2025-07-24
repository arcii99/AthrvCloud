//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //seed the random number generator
    
    int fortune = rand() % 5; //generate a number between 0 and 4
    
    switch(fortune){
        case 0:
            printf("Today is your lucky day!\n");
            break;
        case 1:
            printf("It is not a good day for taking risks.\n");
            break;
        case 2:
            printf("You will meet someone special soon.\n");
            break;
        case 3:
            printf("Be patient and your hard work will pay off.\n");
            break;
        case 4:
            printf("You will face a challenge, but you have the strength to overcome it.\n");
            break;
        default:
            printf("Something went wrong.\n");
    }
    
    return 0;
}