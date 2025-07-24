//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include <stdio.h>
#include <string.h>

int main(){
    char sentence[100];
    int i, count=0;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);  //get input from user

    for(i=0; i<strlen(sentence); i++) {
        //check if the current character is a letter or a digit
        if((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= '0' && sentence[i] <= '9')){
            count++;
            //continue counting the word until the space, tab, or newline is found
            while(sentence[i] != ' ' && sentence[i] != '\t' && sentence[i] != '\n') {
                i++;
            }
        }
    }
    printf("Word count of the given sentence is: %d\n", count);

    return 0;
}