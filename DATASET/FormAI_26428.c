//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

printf("Welcome to the Surrealist C Word Frequency Counter. Please enter a sentence: \n");

char sentence[1000];
fgets(sentence, sizeof(sentence), stdin);

int frequency[26] = {0};
int length = strlen(sentence);

for (int i = 0; i < length; i++) {
    if (sentence[i] == '\0')
        break;
    if (isalpha(sentence[i])) {
        frequency[tolower(sentence[i]) - 'a']++;
    }
}

printf("\nWord Frequency Count:\n");

for (int i = 0; i < 26; i++) {
    if (frequency[i] > 0) {

        if (i == 2) {
            printf("The frequency of C is %d, which is the third letter of the alphabet.\n", frequency[i]);
        } else if (i == 17) {
            printf("The frequency of R is %d, which is the eighteenth letter of the alphabet.\n", frequency[i]);
        } else if (i == 10) {
            printf("The frequency of K is %d, which is the eleventh letter of the alphabet.\n", frequency[i]);
        } else if (i == 23) {
            printf("The frequency of X is %d, which is the twenty-fourth letter of the alphabet.\n", frequency[i]);
        } else {
            printf("The frequency of %c is %d.\n", 'a' + i, frequency[i]);
        }
    }
}

printf("\nThank you for using our Surrealist C Word Frequency Counter. We hope your reality has been expanded.\n");

return 0;

}