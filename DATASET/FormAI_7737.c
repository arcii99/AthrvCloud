//FormAI DATASET v1.0 Category: Data mining ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to find the frequency of a character in a string
int findFrequency(char *str, char ch) {
    int frequency = 0;
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ch) {
            frequency++;
        }
    }
    return frequency;
}

// Function to find the most frequent character in a string
char findMostFrequentChar(char *str) {
    char mostFrequentChar = str[0];
    int highestFrequency = 0;
    
    for(int i=0; i<strlen(str); i++) {
        int frequency = findFrequency(str, str[i]);
        if(frequency > highestFrequency) { // if frequency of current char is higher than the highest frequency
            highestFrequency = frequency; // update the highest frequency
            mostFrequentChar = str[i]; // set the most frequent char
        }
    }
    return mostFrequentChar;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Finding the most frequent character in the string
    char mostFrequentChar = findMostFrequentChar(str);

    // Printing result in medieval style
    printf("The most frequent character in the string \"");
    printf("%s", str);
    printf("\" is: \'%c\'", mostFrequentChar);
    printf("\nHear ye, hear ye! The character \'%c\' hath been declared the most frequent character in the land of %s!", mostFrequentChar, str);

    return 0;
}