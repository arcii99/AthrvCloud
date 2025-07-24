//FormAI DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <string.h>

/* Define a function to find the frequency of each character in a given string */
void findCharFreq(char* str) {
    int len = strlen(str);
    int freq[128] = {0}; /* Array to store frequency of each character */
    printf("--------------------------------------------------\n");
    printf("|    Character    |    Frequency (in the string)   |\n");
    printf("--------------------------------------------------\n");

    /* Loop through the string and find frequency of each character */
    for(int i=0; i<len; i++) {
        freq[str[i]]++;
    }

    /* Print the frequency of each character */
    for(int i=0; i<128; i++) {
        if(freq[i] > 0) {
            printf("|        %c         |             %d               |\n", i, freq[i]);
        }
    }    
}

int main() {
    char str[100];
    printf("Hey there! I am a curious chatbot and I would like to learn more about you.\n");
    printf("Could you please tell me your name? (max 100 characters): ");
    fgets(str, 100, stdin);
    printf("Hi %s! It's great to meet you.\n", str);

    printf("I am curious about the frequency of each character in your name.\n");
    printf("Let's find out!\n");

    /* Call the findCharFreq function to find the frequency of each character in the name */
    findCharFreq(str);

    printf("Thanks for sharing that with me! I hope to learn more about you in the future.\n");
    return 0;
}