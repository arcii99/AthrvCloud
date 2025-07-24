//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {

    char sentence[100];
    printf("Hey there! Let's give your sentence some energy today! Type your sentence here:\n");
    fgets(sentence, sizeof(sentence), stdin);

    // adding excitement to the sentence
    char newSentence[200] = "WOW! ";
    strcat(newSentence, sentence);
    strcat(newSentence, " That's amazing!");

    // reversing the sentence
    int len = strlen(newSentence);
    char reverse[len+1];
    int i, j;
    for (i = len-1, j = 0; i >= 0; i--, j++) {
        reverse[j] = newSentence[i];
    }
    reverse[j] = '\0';

    // counting the number of vowels in the sentence
    int count = 0, vowels = 0;
    for (i = 0; newSentence[i] != '\0'; i++) {
        if (newSentence[i] == ' ') {
            continue;
        }
        else if (newSentence[i] == 'a' || newSentence[i] == 'e' || newSentence[i] == 'i' || newSentence[i] == 'o' || newSentence[i] == 'u' || newSentence[i] == 'A' || newSentence[i] == 'E' || newSentence[i] == 'I' || newSentence[i] == 'O' || newSentence[i] == 'U') {
            vowels++;
            count++;
        }
    }

    // printing out the results
    printf("\nYour energetic sentence is: %s", newSentence);
    printf("\nAnd now, your sentence with energy reversed is: %s", reverse);
    printf("\nAnd lastly, the number of vowels in your sentence is: %d\n", vowels);

    return 0;
}