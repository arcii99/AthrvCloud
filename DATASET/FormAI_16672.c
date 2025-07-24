//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char myString[] = "I can't believe it's not butter!";
    char shockedString[100];
    int index = 0;
    
    // copy the original string into shockedString, but uppercase all the vowels
    while (myString[index] != '\0') {
        if (myString[index] == 'a' || myString[index] == 'e' || myString[index] == 'i' || myString[index] == 'o' || myString[index] == 'u') {
            shockedString[index] = toupper(myString[index]);
        } else {
            shockedString[index] = myString[index];
        }
        index++;
    }
    shockedString[index] = '\0';
    
    // print out the original and shocked strings
    printf("Original string: %s\nShocked string: %s\n\n", myString, shockedString);
    
    // remove all the spaces from shockedString, add "OMG" to the beginning and end, and swap the case of all the letters
    index = 0;
    char tempString[100];
    memset(tempString, 0, sizeof(tempString));
    while (shockedString[index] != '\0') {
        if (shockedString[index] != ' ') {
            tempString[strlen(tempString)] = shockedString[index];
        }
        index++;
    }
    
    strcpy(shockedString, "OMG");
    strcat(shockedString, tempString);
    strcat(shockedString, "OMG");
    
    index = 0;
    while (shockedString[index] != '\0') {
        if (shockedString[index] >= 'a' && shockedString[index] <= 'z') {
            shockedString[index] = toupper(shockedString[index]);
        } else if (shockedString[index] >= 'A' && shockedString[index] <= 'Z') {
            shockedString[index] = tolower(shockedString[index]);
        }
        index++;
    }
    
    // print out the final result
    printf("Final result: %s", shockedString);
    
    return 0;
}