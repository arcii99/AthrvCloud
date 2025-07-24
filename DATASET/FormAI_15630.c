//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    printf("Enter your text here: ");
    scanf("%[^\n]", text);
    printf("Your text is: %s\n", text);

    int len = strlen(text);
    char reversed_text[len+1];
    int j = 0;
    for(int i=len-1; i>=0; i--) {
        reversed_text[j] = text[i];
        j++;
    }
    reversed_text[j] = '\0';
    printf("Reversed text is: %s\n", reversed_text);

    int vowels = 0;
    int consonants = 0;
    for(int i=0; i<len; i++) {
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
           text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
           vowels++;
        }
        else if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            consonants++;
        }
    }
    printf("Vowels in the text: %d\n", vowels);
    printf("Consonants in the text: %d\n", consonants);

    int words = 0;
    for(int i=0; i<len; i++) {
        if(text[i] == ' ' || text[i] == '\t' || text[i] == '\n') {
            words++;
        }
    }
    words++;
    printf("Words in the text: %d\n", words);

    int other_chars = len - vowels - consonants - words + 1;
    printf("Other characters in the text: %d\n", other_chars);

    return 0;
}