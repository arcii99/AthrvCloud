//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <string.h>

int main()
{
    char inputString[100];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, specialcharacters = 0;
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);
    for (int i = 0; i < strlen(inputString); i++){
        if ((inputString[i] >= 'a' && inputString[i] <= 'z') || (inputString[i] >= 'A' && inputString[i] <= 'Z')){
            if (inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u' || inputString[i] == 'A' || inputString[i] == 'E' || inputString[i] == 'I' || inputString[i] == 'O' || inputString[i] == 'U')
                vowels++;
            else
                consonants++;
        }
        else if (inputString[i] >= '0' && inputString[i] <= '9')
            digits++;
        else if (inputString[i] == ' ')
            spaces++;
        else
            specialcharacters++;
    }
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of spaces: %d\n", spaces);
    printf("Number of special characters: %d\n", specialcharacters);
    return 0;
}