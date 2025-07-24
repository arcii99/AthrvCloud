//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    char morse[100][10] = {".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ",
                           "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ",
                           "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. "};
    
    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    printf("Morse code: ");
    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == ' ') {
            printf(" / ");
        } else {
            int morseIndex = tolower(text[i]) - 'a'; // convert character to Morse code index
            printf("%s", morse[morseIndex]);
        }
    }
    
    return 0;
}