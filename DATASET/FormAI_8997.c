//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Welcome to the Random Conspiracy Theory Generator\n");
    printf("Generating conspiracy theory in 3...2...1...\n");

    srand(time(0));
    int r = rand() % 10 + 1;

    if(r == 1){
        printf("The moon landing was faked by the government to distract from the Vietnam War.\n");
    }
    else if(r == 2){
        printf("The flu shot is actually a mind control vaccine created by the Illuminati.\n");
    }
    else if(r == 3){
        printf("The government is secretly controlling the weather and causing natural disasters.\n");
    }
    else if(r == 4){
        printf("The Earth is flat and NASA has been lying to us all along.\n");
    }
    else if(r == 5){
        printf("Reptilian shape-shifters are secretly running the world's governments.\n");
    }
    else if(r == 6){
        printf("Chemtrails are actually a government plot to poison us all with mind control drugs.\n");
    }
    else if(r == 7){
        printf("The Illuminati is controlling the music industry and using it to brainwash us.\n");
    }
    else if(r == 8){
        printf("The government is hiding evidence of alien life to prevent widespread panic.\n");
    }
    else if(r == 9){
        printf("The Denver International Airport is actually a secret underground government bunker.\n");
    }
    else{
        printf("9/11 was an inside job orchestrated by the US government.\n");
    }

    printf("Thanks for using the Random Conspiracy Theory Generator. Stay woke!\n");

    return 0;
}