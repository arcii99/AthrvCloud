//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// function to check if input is a valid number
int isNumber(char* input){
    int i;
    for(i=0; i<strlen(input); i++){
        if(input[i] < '0' || input[i] > '9'){
            return 0;
        }
    }
    return 1;
}

int main(){
    srand(time(NULL));
    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are a brave astronaut on a mission to explore a new solar system.\n");
    printf("However, due to a malfunction in your ship's navigation system, you have been randomly teleported to one of the planets in the system!\n");
    printf("Your goal is to explore the planet, gather resources, and repair your ship so you can continue your mission.\n");

    // randomly generate planet details
    char planets[5][20] = {"Zorbon", "Tyranos", "Omicron", "Quixote", "Neptunus"};
    int planetIndex = rand() % 5;
    printf("\nYou have landed on planet %s!\n", planets[planetIndex]);
    int temperature = rand() % 101 - 50;
    int resources = rand() % 101;
    printf("The temperature is: %d degrees Celsius\n", temperature);
    printf("The available resources are: %d percent\n", resources);

    // loop for player actions
    int repairProgress = 0;
    int fuel = 100;
    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Explore\n");
        printf("2. Gather resources\n");
        printf("3. Repair ship\n");
        printf("4. Refuel ship\n");
        printf("5. Quit\n");

        char choice[10];
        scanf("%s", choice);

        if(!isNumber(choice)){
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        int choiceNum = atoi(choice);

        switch(choiceNum){
            case 1:
                printf("\nYou explore the planet and find nothing of interest.\n");
                break;
            case 2:
                int resourceGathered = rand() % 21;
                resources += resourceGathered;
                printf("\nYou gather %d percent additional resources.\n", resourceGathered);
                printf("Available resources now: %d percent\n", resources);
                break;
            case 3:
                if(resources < 50){
                    printf("\nYou need at least 50 percent resources to repair the ship!\n");
                }else{
                    repairProgress += rand() % 11 + 10;
                    resources -= 50;
                    printf("\nYou repair the ship by %d percent.\n", repairProgress);
                    printf("Remaining resources: %d percent\n", resources);
                }
                break;
            case 4:
                if(repairProgress < 100){
                    printf("\nYou need to repair the ship fully before refueling!\n");
                }else{
                    fuel = 100;
                    printf("\nYou refuel the ship.\n");
                }
                break;
            case 5:
                printf("\nThank you for playing Procedural Space Adventure!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }

        // check win/lose conditions
        if(temperature > 60){
            printf("\nThe temperature is too high! You die from heat exhaustion.\n");
            return 0;
        }
        if(fuel == 0){
            printf("\nYou run out of fuel and are stranded on the planet forever.\n");
            return 0;
        }
        if(repairProgress == 100){
            printf("\nCongratulations! You have repaired the ship and can continue your mission.\n");
            printf("Thank you for playing Procedural Space Adventure!\n");
            return 0;
        }

        // random event every 3 turns
        if(rand() % 3 == 0){
            int event = rand() % 3;
            switch(event){
                case 0:
                    temperature += rand() % 11 - 5;
                    printf("\nThe temperature changes to: %d degrees Celsius\n", temperature);
                    break;
                case 1:
                    resources -= rand() % 21;
                    printf("\nSome of your resources get stolen!\n");
                    printf("Remaining resources: %d percent\n", resources);
                    break;
                case 2:
                    fuel -= rand() % 11 + 5;
                    printf("\nShip fuel decreased by %d percent.\n", rand() % 11 + 5);
                    printf("Remaining fuel: %d percent\n", fuel);
                    break;
            }
        }
    }

    return 0;
}