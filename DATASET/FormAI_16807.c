//FormAI DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int i, vowels = 0, consonants = 0, digits = 0, spaces = 0, specialChars = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for(i=0; sentence[i]!='\0'; i++) {
        if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' ||
           sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'A' ||
           sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' ||
           sentence[i] == 'U') {
            vowels++;
        }
        else if((sentence[i]>='a'&& sentence[i]<='z') || (sentence[i]>='A'&& sentence[i]<='Z')) {
            consonants++;
        }
        else if(sentence[i]>='0' && sentence[i]<='9') {
            digits++;
        }
        else if(sentence[i]==' ') {
            spaces++;
        }
        else {
            specialChars++;
        }
    }

    printf("\nAnalysis of Input Sentence:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Special Characters: %d\n", specialChars);

    return 0;
}