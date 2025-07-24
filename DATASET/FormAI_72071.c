//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COORDINATE 2000 /* Maximum value of coordinates */
#define MIN_COORDINATE -2000 /* Minimum value of coordinates */
#define SIZE_OF_ARRAY 100 /* Size of the navigation array */

/* Function prototype */
int getRandomCoordinate();
void initializeNavigation(int navigationArray[][2]);
void printNavigation(int navigationArray[][2], int currentIndex);
void navigate(int navigationArray[][2], int currentIndex);

/* Function to get a random coordinate within the range */
int getRandomCoordinate() {
    int randCoordinate = (rand() % (MAX_COORDINATE - MIN_COORDINATE + 1)) + MIN_COORDINATE;
    return randCoordinate;
}

/* Function to initialize the navigation array with random coordinates */
void initializeNavigation(int navigationArray[][2]) {
    int i;
    for(i = 0; i < SIZE_OF_ARRAY; i++) {
        navigationArray[i][0] = getRandomCoordinate();
        navigationArray[i][1] = getRandomCoordinate();
    }
}

/* Function to print the current location and nearby locations */
void printNavigation(int navigationArray[][2], int currentIndex) {
    printf("Current Location: (%d, %d)\n", navigationArray[currentIndex][0], navigationArray[currentIndex][1]);
    if(currentIndex > 0) {
        printf("Previous Location: (%d, %d)\n", navigationArray[currentIndex-1][0], navigationArray[currentIndex-1][1]);
    }
    if(currentIndex < SIZE_OF_ARRAY-1) {
        printf("Next Location: (%d, %d)\n", navigationArray[currentIndex+1][0], navigationArray[currentIndex+1][1]);
    }
}

/* Function for navigation */
void navigate(int navigationArray[][2], int currentIndex) {
    char direction;
    printf("Enter direction (N for North, S for South, E for East, W for West): ");
    scanf(" %c", &direction);

    switch(direction) {
        case 'N':
            if(navigationArray[currentIndex][1] < MAX_COORDINATE) {
                navigationArray[currentIndex][1]++;
                printf("Moving North.\n");
            } else {
                printf("Cannot move in that direction.\n");
            }
            break;
        case 'S':
            if(navigationArray[currentIndex][1] > MIN_COORDINATE) {
                navigationArray[currentIndex][1]--;
                printf("Moving South.\n");
            } else {
                printf("Cannot move in that direction.\n");
            }
            break;
        case 'E':
            if(navigationArray[currentIndex][0] < MAX_COORDINATE) {
                navigationArray[currentIndex][0]++;
                printf("Moving East.\n");
            } else {
                printf("Cannot move in that direction.\n");
            }
            break;
        case 'W':
            if(navigationArray[currentIndex][0] > MIN_COORDINATE) {
                navigationArray[currentIndex][0]--;
                printf("Moving West.\n");
            } else {
                printf("Cannot move in that direction.\n");
            }
            break;
        default:
            printf("Invalid direction.\n");
    }
}

/* Main function */
int main() {
    int navigationArray[SIZE_OF_ARRAY][2];
    int currentIndex = 0;

    srand(time(NULL)); /* Seed for random number generator */

    initializeNavigation(navigationArray);

    while(1) {
        printNavigation(navigationArray, currentIndex);
        navigate(navigationArray, currentIndex);

        char input;
        printf("Do you want to exit? (Y/N): ");
        scanf(" %c", &input);
        if(input == 'Y' || input == 'y') {
            break; /* Exit loop */
        } else if(currentIndex < SIZE_OF_ARRAY-1) {
            currentIndex++;
        } else {
            printf("Navigation complete.\n");
            break; /* Exit loop */
        }
    }
    return 0;
}