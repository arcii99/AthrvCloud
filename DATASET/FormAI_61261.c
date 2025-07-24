//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL)); // Seed for random number generator functions
    int totalCount, i, j, userInput, score = 0;
    printf("Enter count of elements in the memory game: ");
    scanf("%d", &totalCount);

    // Creating the array and filling with random numbers
    int arr[totalCount];
    for(i=0; i<totalCount; i++) {
        arr[i] = (rand() % 100) + 1;
    }

    printf("You will be shown %d numbers, memorize them for 5 seconds.\n", totalCount);

    // Displaying the numbers to user for 5 seconds
    for(i=0; i<totalCount; i++) {
        printf("%d ", arr[i]);
    }
    sleep(5);   // Wait for 5 seconds

    system("clear");    // Clearing the console screen

    // Taking input from user and verifying against the array numbers
    for(i=0; i<totalCount; i++) {
        printf("Enter %dth number: ", i+1);
        scanf("%d", &userInput);
        if(userInput == arr[i]) {
            printf("Match Found!\n");
            score++;
        }
        else {
            printf("Wrong Match\n");
        }
    }

    // Displaying the user's score
    printf("Your Final Score: %d\n", score);
    return 0;
}