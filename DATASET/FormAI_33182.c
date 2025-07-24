//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //a new seed for the random number generator 
    srand(time(NULL));

    //an array of fortunes to choose from
    char* fortunes[5] = {
        "You will find success in your near future.",
        "Your luck is about to change for the better.",
        "A great opportunity will come your way.",
        "You will meet someone special soon.",
        "Your hard work will pay off in a big way."
    };

    //a random number between 0 and 4 to select a fortune
    int index = rand() % 5;

    //printing the chosen fortune
    printf("Your fortune for today is: %s\n", fortunes[index]);

    return 0;
}