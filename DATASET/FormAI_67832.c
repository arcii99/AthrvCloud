//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Function to generate a random number within a range
int generateRandom(int min, int max){
    int num;
    num = (rand() % (max - min + 1)) + min;
    return num;
}

int main(){
    char* companies[] = {"Google", "Facebook", "Amazon", "Apple", "Microsoft", "Tesla"};
    char* individuals[] = {"Elon Musk", "Mark Zuckerberg", "Bill Gates", "Jeff Bezos", "Tim Cook", "Larry Page"};
    char* actions[] = {"stealing", "hacking", "selling", "monitoring", "manipulating", "destroying"};

    int numCompanies = sizeof(companies)/sizeof(*companies);
    int numIndividuals = sizeof(individuals)/sizeof(*individuals);
    int numActions = sizeof(actions)/sizeof(*actions);

    srand(time(NULL)); // Seed for random number generator

    printf("Welcome to the Conspiracy Theory Generator\n");

    while(1){
        printf("\n\nPress any key to generate a new theory\n");
        getchar();

        printf("\n\nYour conspiracy theory is:\n\n");
        printf("The %s led by %s is %s data from every individual on the planet to gain control and enslave humanity.\n", companies[generateRandom(0, numCompanies-1)], individuals[generateRandom(0, numIndividuals-1)], actions[generateRandom(0, numActions-1)]);

        printf("\n\nDo you want to generate another conspiracy theory? (y/n)\n");
        char choice;
        scanf("%c", &choice);
        if(choice == 'n'){
            break;
        }
    }

    return 0;
}