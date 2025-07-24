//FormAI DATASET v1.0 Category: Text processing ; Style: surrealist
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char sentence[1000], new_sentence[1000];
    int i,j;
    printf("Enter a sentence:\n");
    fgets(sentence, 1000, stdin);

    // Process the sentence in a surrealistic way
    for(i=0,j=0;i<strlen(sentence);i++,j++){
        if(isalpha(sentence[i])){
            if(i%2==0){
                new_sentence[j] = toupper(sentence[i]-7); // subtract 7 from ASCII value of character to make it surreal
            }
            else{
                new_sentence[j] = tolower(sentence[i]+7); // add 7 to ASCII value of character to make it even more surreal
            }
        }
        else{
            new_sentence[j] = sentence[i];
        }
    }

    printf("\nYour surrealistic sentence is:\n%s", new_sentence);
    return 0;
}