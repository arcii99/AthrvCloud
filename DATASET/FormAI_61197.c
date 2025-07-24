//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    char *conspiracies[10] = {
        "The moon landing was faked by the government",
        "9/11 was an inside job orchestrated by the government",
        "Aliens exist and the government is covering it up",
        "The Illuminati controls the world's governments",
        "The earth is flat and the government is covering it up",
        "The Bermuda Triangle is a portal to another dimension",
        "Chemtrails are a secret government program",
        "The JFK assassination was a conspiracy by the CIA",
        "Paul McCartney died in 1966 and was replaced with a look-alike",
        "The government is hiding the cure to cancer"
    };

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while(1){
        printf("\nPress 'Enter' to generate a new conspiracy theory or type 'exit' to quit.\n");
        char input[10];
        fgets(input, 10, stdin);

        if(strcmp(input, "exit\n") == 0){
            printf("Exiting...\n");
            break;
        }

        int random_number = rand() % 10;
        printf("\nYour random conspiracy theory is:\n%s\n", conspiracies[random_number]);
    }

    return 0;
}