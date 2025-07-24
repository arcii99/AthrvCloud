//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100]; //declare input string with max length of 100
    printf("Enter a string: ");
    fgets(inputString, 100, stdin); //read input from user

    int length = strlen(inputString); //get length of input string
    printf("The length of the string is: %d\n", length);

    int numVowels = 0; //initialize variable to count number of vowels
    for (int i = 0; i < length; i++) {
        if (inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u') {
            numVowels++;
        }
    }
    printf("The number of vowels in the string is: %d\n", numVowels);

    char reversedString[100]; //declare a new string to store reversed input string
    int j = 0;
    for (int i = length - 1; i >= 0; i--) { //iterate through input string backwards
        reversedString[j] = inputString[i];
        j++;
    }
    reversedString[length] = '\0'; //add null character at end of reversed string
    printf("The reversed string is: %s\n", reversedString);

    char subString[50]; //declare a new string to store substring
    printf("Enter a substring to search for: ");
    scanf("%s", subString);
    char *result = strstr(inputString, subString); //search for substring within input string
    if (result != NULL) {
        printf("The substring '%s' was found at position %ld within the string.\n", subString, result - inputString + 1);
    } else {
        printf("The substring '%s' was not found within the string.\n", subString);
    }

    return 0;
}