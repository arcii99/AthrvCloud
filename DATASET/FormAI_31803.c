//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    printf("Let's process some text! Yay!\n");
    
    char text[] = "Hello, this is an awesome text! Isn't it?";
    printf("Our text is: %s\n", text);
    
    // count the number of words in the text
    int num_words = 0;
    char *token = strtok(text, " ,.!?"); // split the text by ,, ., !, or ?
    while (token != NULL) {
        num_words++;
        token = strtok(NULL, " ,.!?");
    }
    printf("There are %d words in the text.\n", num_words);
    
    // reverse the text
    int len = strlen(text);
    char reversed_text[len+1]; // create a new char array to store the reversed text
    for (int i = len-1; i >= 0; i--) {
        reversed_text[len-1-i] = text[i];
    }
    reversed_text[len] = '\0';
    printf("The reversed text is: %s\n", reversed_text);
    
    // count the number of vowels in the text
    int num_vowels = 0;
    for (int i = 0; i < len; i++) {
        char c = text[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            num_vowels++;
        }
    }
    printf("There are %d vowels in the text.\n", num_vowels);
    
    printf("Yay! We processed the text successfully! :)\n");
    return 0;
}