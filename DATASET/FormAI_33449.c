//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include<stdio.h>
#include<string.h>

int main(){
    char myString[1000];
    int counter = 0;

    printf("Enter a sentence: ");
    fgets(myString, sizeof(myString), stdin);

    for(int i=0; i<strlen(myString)-1; i++){
        if(myString[i] == ' '){
            counter++;
        }
    }

    printf("The number of words in the sentence is: %d", counter+1);
    
    return 0;
}