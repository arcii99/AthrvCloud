//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    srand((unsigned)time(NULL));
    int risk_factor, invasion_chance, army_strength, castle_strength;
    char name[20], response[50];

    printf("Hail, brave knight! What is your name?\n");
    scanf("%s", name);
    printf("Welcome, %s! Are you prepared to assess the risk of an alien invasion?\n", name);
    printf("Please enter a number between 1 and 10, with 10 being the highest risk:\n");
    scanf("%d", &risk_factor);
    printf("Great! Now that we have determined the risk factor, let's assess the chance of an invasion.\n");
    
    invasion_chance = rand() % 101;
    printf("The probability of an invasion is %d%%.\n", invasion_chance);

    if (invasion_chance <= risk_factor*10) {
        printf("Oh no! It looks like an invasion is likely. Time to prepare for battle!\n");
        printf("How strong is your army, %s?\n", name);
        scanf("%d", &army_strength);
        printf("And how strong is your castle?\n");
        scanf("%d", &castle_strength);

        if (army_strength + castle_strength >= 150) {
            printf("Wonderful news, %s! Your forces are strong enough to repel the aliens and defend your kingdom!\n", name);
        }
        else {
            printf("I’m sorry, %s. Your kingdom is overrun by the aliens. You have been defeated. Better luck next time!\n", name);
        }
    }
    else {
        printf("Phew! It looks like your kingdom is safe from an alien invasion for now.\n");
    }

    printf("\n%s, was it helpful to assess the probability of an alien invasion?\n", name);
    scanf("%s", response);
    if(strcmp(response, "yes") == 0){
        printf("Glad to help, %s! Stay vigilant and be prepared for anything!\n", name);
    }
    else{
        printf("I'm sorry to hear that, %s. Perhaps we can try again at a later time.\n", name);
    }

    return 0;
}