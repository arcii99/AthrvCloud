//FormAI DATASET v1.0 Category: String manipulation ; Style: content
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    char reversed_message[100];
    int length;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    
    length = strlen(message)-1; //remove newline character from fgets

    for (int i = 0; i < length; i++) {
        reversed_message[length-i-1] = message[i];
    }
    reversed_message[length] = '\0'; //add null terminator at the end of the reversed message

    printf("Your message reversed is: %s\n", reversed_message);

    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < length; i++) {
        char letter = message[i];

        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
            letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') {
            vowels++;
        } else if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
            consonants++;
        }
    }

    printf("The number of vowels in your message is: %d\n", vowels);
    printf("The number of consonants in your message is: %d\n", consonants);

    return 0;
}