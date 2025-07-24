//FormAI DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void handleError(int errorCode);

int main() {
    int randomNumber;
    srand(time(0));
    randomNumber = rand() % 4;
    switch(randomNumber) {
        case 0:
            printf("Everything looks good!\n");
            break;
        case 1:
            handleError(100);
            break;
        case 2:
            handleError(200);
            break;
        case 3:
            handleError(300);
            break;
        default:
            printf("Unknown error occurred.\n");
            break;
    }
    return 0;
}

void handleError(int errorCode) {
    char message[50];
    switch(errorCode) {
        case 100:
            strcpy(message, "Oops! Something went wrong.");
            break;
        case 200:
            strcpy(message, "Error: Cannot open file.");
            break;
        case 300:
            strcpy(message, "Error: Cannot allocate memory.");
            break;
        default:
            strcpy(message, "Unknown error occurred.");
            break;
    }
    printf("%s\n", message);
    exit(errorCode);
}