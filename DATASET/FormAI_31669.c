//FormAI DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int count = 0;

    printf("Enter a sentence:\n");
    fgets(sentence, 1000, stdin); // read input from stdin
    
    for(int i=0; i<strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            count++;
        }
    }
    
    printf("The number of words in the sentence is: %d\n", count+1);
    
    return 0;
}