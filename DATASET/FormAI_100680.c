//FormAI DATASET v1.0 Category: Word Count Tool ; Style: energetic
#include<stdio.h>
#include<string.h>

int main(){
    char input[1000]; // declaring a char array for storing user's input
    int count = 0; // initializing the word count to 0

    printf("Enter a sentence:\n");
    fgets(input, sizeof(input), stdin); // getting the user's input

    int len = strlen(input); // getting the length of the input string

    for(int i = 0; i<len; i++){
        // checking whether the current character is a space or newline or tab
        if(input[i]==' ' || input[i]=='\n' || input[i]=='\t'){
            count++; // if space or newline or tab is found, increase the word count by 1
            while(input[i]==' ' || input[i]=='\n' || input[i]=='\t')
                i++; // skipping all the consecutive spaces and tabs
        }
    }

    // handling the special case when the input does not end with a space or newline or tab
    if(input[len-2]!=' ' && input[len-2]!='\n' && input[len-2]!='\t')
        count++;

    printf("\nWord count is %d\n", count); // printing the word count

    return 0;
}