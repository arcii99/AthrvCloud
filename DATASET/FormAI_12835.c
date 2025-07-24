//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000]; // array to store input text
    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin); // get input text

    int vowels = 0; // variable to store number of vowels
    int consonants = 0; // variable to store number of consonants
    int spaces = 0; // variable to store number of spaces
    int symbols = 0; // variable to store number of symbols

    for(int i=0; i<strlen(text); i++) {
        char c = text[i];
        if(c == '\n') { // remove newline character
            text[i] = '\0';
            break;
        } else if(c == ' ') { // increase spaces count
            spaces++;
        } else if(c>='a' && c<='z' || c>='A' && c<='Z') { // check for vowels and consonants
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        } else { // increase symbols count
            symbols++;
        }
    }

    // print result
    printf("\nThe input text contains:\n");
    printf("%d vowels\n", vowels);
    printf("%d consonants\n", consonants);
    printf("%d spaces\n", spaces);
    printf("%d symbols\n", symbols);

    // convert text to upper case
    for(int i=0; i<strlen(text); i++) {
        if(text[i]>='a' && text[i]<='z') {
            text[i] = text[i] - 'a' + 'A';
        }
    }

    // print text in upper case
    printf("\nThis is how the text looks in upper case:\n%s", text);

    return 0;
}