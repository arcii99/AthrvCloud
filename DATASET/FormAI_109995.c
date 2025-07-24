//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_conspiracy_theory(){
    srand(time(NULL));  // Seed the random number generator with current time
    int random = rand() % 5;  // Generate a random number between 0 and 4
    
    // Conspiracy Theory 1
    if(random == 0){
        printf("The moon landing was faked to win the space race.");
    }
    // Conspiracy Theory 2
    else if(random == 1){
        printf("The government is hiding evidence of extraterrestrial life.");
    }
    // Conspiracy Theory 3
    else if(random == 2){
        printf("The earth is actually flat and the government is covering it up.");
    }
    // Conspiracy Theory 4
    else if(random == 3){
        printf("The Illuminati controls the world's governments from behind the scenes.");
    }
    // Conspiracy Theory 5
    else if(random == 4){
        printf("9/11 was an inside job orchestrated by the US government.");
    }
}

int main(){
    generate_conspiracy_theory();
    return 0;
}