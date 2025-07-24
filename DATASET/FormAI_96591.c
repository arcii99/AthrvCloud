//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to predict the user's future
void predictFuture() {
    // generate a random number between 1 and 5
    int num = rand() % 5 + 1;

    switch(num) {
        case 1:
            printf("You will receive some good news today.\n");
            break;
        case 2:
            printf("A big change is coming your way.\n");
            break;
        case 3:
            printf("You will meet someone special soon.\n");
            break;
        case 4:
            printf("Your financial situation will improve.\n");
            break;
        case 5:
            printf("You will overcome a challenge that has been troubling you.\n");
            break;
    }
}

int main() {
    int numPredictions;

    printf("Welcome to the Automated Fortune Teller!\n\n");

    printf("How many predictions would you like to receive? ");
    scanf("%d", &numPredictions);

    // seed the random number generator
    srand(time(NULL));

    // generate the specified number of predictions
    for(int i = 0; i < numPredictions; i++) {
        printf("\nPrediction %d: ", i+1);
        predictFuture();
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}