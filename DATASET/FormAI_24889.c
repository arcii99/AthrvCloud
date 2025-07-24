//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    char newSentence[100] = "";
    int count = 0;
    printf("Enter a sentence:\n");
    fgets(sentence, sizeof(sentence), stdin);
    
    // remove extra spaces
    for (int i = 0; i < strlen(sentence) - 1; i++) {
        if (sentence[i] == ' ' && sentence[i+1] == ' ') {
            continue;
        }
        newSentence[count] = sentence[i];
        count++;
    }
    
    newSentence[count] = sentence[strlen(sentence) - 1];
    strcpy(sentence, newSentence);
    
    // convert sentence to uppercase
    for (int i = 0; i < strlen(sentence); i++) {
        sentence[i] = toupper(sentence[i]);
    }
    
    printf("Your manipulated sentence is:\n%s\n", sentence);
    
    return 0;
}