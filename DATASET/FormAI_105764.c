//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkVirus(char arr[], int size) {
    int virus = 0; // assume no virus initially
    char checkArr[3] = {'X','Y','Z'}; // set the virus signature
    for (int i = 0; i < size-2; i++) { // loop through the input array
        if (arr[i] == checkArr[0] && arr[i+1] == checkArr[1] && arr[i+2] == checkArr[2]) {
            virus = 1; // set flag if virus found
            break; // break out of loop if virus found
        }
    }
    return virus; // return flag for virus presence
}

int main() {
    char inputArr[100]; // array to store user input
    printf("Enter a string to check for viruses:\n");
    fgets(inputArr, 100, stdin); // get input from user
    int inputSize = strlen(inputArr); // get size of input
    int virusPresence = checkVirus(inputArr, inputSize); // check for virus
    if (virusPresence == 1) {
        printf("Virus detected!\n");
    } else {
        printf("No viruses found.\n");
    }
    return 0;
}