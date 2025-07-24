//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>

int main(){
    int count = 0;
    char input[50];
    
    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter a sentence: ");
    fgets(input, 50, stdin);
    
    for(int i=0; input[i]!='\0'; i++){
        // If current letter is a space, increment count
        if(input[i] == ' '){
            count++;
        }
    }
    // Since the last word might not have a space after it,
    // we add one to the word count to include it
    count++;
    
    printf("\nYour sentence contains %d words.", count);
    printf("\nThank you for using the C Word Count Tool!\n");
    
    return 0;
}