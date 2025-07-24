//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("Please answer the following questions truthfully to determine your chance of alien invasion.\n");
    printf("Have you ever seen a UFO? (y/n): ");
    char answer = getchar();
    if (answer == 'y' || answer == 'Y') {
        printf("You have already made contact with the aliens. Your chances of an invasion are high.\n");
        return 0;
    }
    printf("Do you live in a metropolitan city? (y/n): ");
    answer = getchar();
    if (answer == 'y' || answer == 'Y') {
        printf("You are in a prime location for an alien invasion. Your chances have increased.\n");
    }
    printf("Have you ever had a strange dream involving aliens? (y/n): ");
    answer = getchar();
    if (answer == 'y' || answer == 'Y') {
        printf("The aliens may have already communicated with you subconsciously. Your chances are rising.\n");
    }
    printf("Do you believe in extraterrestrial life? (y/n): ");
    answer = getchar();
    if (answer == 'n' || answer == 'N') {
        printf("You are in denial. The aliens are out there and your refusal to accept it may make you a prime target for invasion.\n");
    }
    printf("Please enter the number of times you have watched the movie 'Independence Day': ");
    int id_count;
    scanf("%d", &id_count);
    if (id_count >= 3) {
        printf("You are obsessed with the idea of alien invasions. The aliens may now be obsessed with you.\n");
    }
    int prob = rand() % 101; // generate a random probability between 0 and 100
    printf("Calculating your probability of an alien invasion...\n");
    printf("You have a %d%% chance of an alien invasion.\n", prob);
    printf("Thank you for using our calculator. Stay safe and stay vigilant.\n");
    return 0;
}