//FormAI DATASET v1.0 Category: String manipulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char originalString[100];
    char modifiedString[100];
    char tempString[100];
    int i, j, k, n, flag;

    printf("Enter a string: ");
    fgets(originalString, 100, stdin);

    // Remove new line character at the end of the string
    originalString[strcspn(originalString, "\n")] = '\0';

    // Convert every character to uppercase
    for(i = 0; originalString[i]; i++){
        modifiedString[i] = toupper(originalString[i]);
    }

    // Reverse the string
    n = strlen(modifiedString);
    for(i = n-1, j = 0; i >= 0; i--, j++){
        tempString[j] = modifiedString[i];
    }
    tempString[j] = '\0';
    strcpy(modifiedString, tempString);

    // Remove any vowels from the string
    k = 0;
    for(i = 0; modifiedString[i]; i++){
        flag = 0;
        switch(modifiedString[i]){
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                flag = 1;
                break;
        }
        if(flag == 0){
            modifiedString[k] = modifiedString[i];
            k++;
        }
    }
    modifiedString[k] = '\0';

    // Insert a '*' after every consonant
    k = 0;
    for(i = 0; modifiedString[i]; i++){
        if(strchr("BCDFGHJKLMNPQRSTVWXYZ", modifiedString[i])){
            tempString[k] = modifiedString[i];
            k++;
            tempString[k] = '*';
            k++;
        }
        else{
            tempString[k] = modifiedString[i];
            k++;
        }
    }
    tempString[k] = '\0';
    strcpy(modifiedString, tempString);

    // Print the modified string
    printf("The modified string is: %s", modifiedString);

    return 0;
}