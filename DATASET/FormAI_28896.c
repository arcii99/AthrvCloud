//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Cryptic
#include <stdio.h>

int main() {
    char input[500];
    int count = 0, i;
    
    printf("Please enter a sentence to count the words in: ");
    fgets(input, 500, stdin);
    
    for(i = 0; input[i] != '\0'; i++){
        if(input[i] == ' ' || input[i] == '\n' || input[i] == '\t'){
            count++;
        }
    }
    
    if(count > 0){
        count++;
    }
    
    printf("The sentence contains %d words.\n", count);
    return 0;
}