//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int probability;
    char answer;

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    printf("Please answer a few questions to get your probability:\n");

    printf("Do you believe in life on other planets?(y/n): ");
    scanf("%c", &answer);

    if(answer == 'y' || answer == 'Y'){
        probability = rand() % 80 + 20;
    }
    else if(answer == 'n' || answer == 'N'){
        probability = rand() % 20;
    }
    else{
        printf("Invalid input. Exiting program\n");
        exit(1);
    }

    printf("Based on your belief in life on other planets, your probability of an alien invasion is: %d%%\n", probability);

    return 0;
}