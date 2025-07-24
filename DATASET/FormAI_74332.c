//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main() 
{
    char string1[100], string2[100], result[200];
    int i, j = 0, length1, length2;

    printf("Hey there! I am a string manipulating chatbot!\n");
    printf("Give me a string: ");
    scanf("%s", string1);

    printf("Great! Now give me another string: ");
    scanf("%s", string2);

    length1 = strlen(string1);
    length2 = strlen(string2);

    // First string reversal
    for(i = length1 - 1; i >= 0; i--) {
        result[j] = string1[i];
        j++;
    }

    // Add a space
    result[j] = ' ';
    j++;

    // Second string reversal
    for(i = length2 - 1; i >= 0; i--) {
        result[j] = string2[i];
        j++;
    }

    // Add a comma and a space
    result[j] = ',';
    j++;
    result[j] = ' ';
    j++;

    // Third string addition
    strcat(result, "you are so funny!");

    printf("Hahaha! Your strings after manipulation: %s\n", result);

    return 0;
}