//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char sentence[100] = "tHis progrAM iS tacky and unwieldy.";
    printf("Before Processing: %s\n", sentence);

    // Convert all characters to lowercase
    for(int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z') {
            sentence[i] += 32;
        }
    }

    // Remove all vowels
    for(int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u') {
            for(int j = i; j < strlen(sentence) - 1; j++) {
                sentence[j] = sentence[j+1];
            }
            sentence[strlen(sentence)-1] = '\0';
            i--;
        }
    }

    // Capitalize first letters of each word
    for(int i = 0; i < strlen(sentence); i++) {
        if(i == 0 || sentence[i-1] == ' ') {
            if(sentence[i] >= 'a' && sentence[i] <= 'z') {
                sentence[i] -= 32;
            }
        }
    }

    printf("After Processing: %s\n", sentence);

    return 0;
}