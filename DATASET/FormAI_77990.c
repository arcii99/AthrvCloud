//FormAI DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0, countConsonants = 0, countDigits = 0, countSpaces = 0, countSpecial = 0;
    int messageLength, i;
    float vowelPercent, consonantPercent, digitPercent, spacePercent, specialPercent;

    printf("Please enter your message: ");
    fgets(message, 1000, stdin);

    messageLength = strlen(message);

    for (i = 0; i < messageLength; i++) {
        if (message[i] == 'a' || message[i] == 'A')
            countA++;
        else if (message[i] == 'e' || message[i] == 'E')
            countE++;
        else if (message[i] == 'i' || message[i] == 'I')
            countI++;
        else if (message[i] == 'o' || message[i] == 'O')
            countO++;
        else if (message[i] == 'u' || message[i] == 'U')
            countU++;
        else if ((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z'))
            countConsonants++;
        else if (message[i] >= '0' && message[i] <= '9')
            countDigits++;
        else if (message[i] == ' ')
            countSpaces++;
        else
            countSpecial++;
    }

    vowelPercent = ((float)(countA + countE + countI + countO + countU) / messageLength) * 100;
    consonantPercent = ((float)countConsonants / messageLength) * 100;
    digitPercent = ((float)countDigits / messageLength) * 100;
    spacePercent = ((float)countSpaces / messageLength) * 100;
    specialPercent = ((float)countSpecial / messageLength) * 100;

    printf("\n\nRESULTS:\n");
    printf("Number of vowels: %d\n", countA + countE + countI + countO + countU);
    printf("Number of consonants: %d\n", countConsonants);
    printf("Number of digits: %d\n", countDigits);
    printf("Number of spaces: %d\n", countSpaces);
    printf("Number of special characters: %d\n", countSpecial);
    printf("Percentage of vowels: %.2f%%\n", vowelPercent);
    printf("Percentage of consonants: %.2f%%\n", consonantPercent);
    printf("Percentage of digits: %.2f%%\n", digitPercent);
    printf("Percentage of spaces: %.2f%%\n", spacePercent);
    printf("Percentage of special characters: %.2f%%\n", specialPercent);

    if (vowelPercent >= 30.0 && consonantPercent <= 60.0 && digitPercent <= 10.0 && spacePercent <= 20.0 && specialPercent <= 20.0) {
        printf("\n\nThe message is NOT a spam!");
    } else {
        printf("\n\nThe message is a SPAM!");
    }

    return 0;
}