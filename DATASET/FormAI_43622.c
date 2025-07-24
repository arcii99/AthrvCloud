//FormAI DATASET v1.0 Category: Browser Plugin ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void printInstructions() {
    printf("Welcome to the Mind-Bending Browser Plugin Example\n");
    printf("Please enter a valid website URL\n");
}

void convertToUpper(char* string) {
    int i = 0;
    while (string[i]) {
        string[i] = toupper(string[i]);
        i++;
    }
}

void addMindBendingFeature(int num) {
    printf("Number of Mind-Bending Features Added: %d\n", num);
}

int main() {
    char url[100];
    char response;
    int numFeatures = 0;

    printInstructions();

    scanf("%s", url);

    printf("You Entered: %s\n", url);

    printf("Would you like to add mind-bending features? (Y/N)\n");
    scanf(" %c", &response);

    if (toupper(response) == 'Y') {
        numFeatures += 1;
        addMindBendingFeature(numFeatures);
    }

    convertToUpper(url);
    printf("%s\n", url);

    return 0;
}