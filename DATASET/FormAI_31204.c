//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>

int main(){

    char word[100];
    int length;
    int check = 0;
    int i, j;

    printf("Please enter a word: ");
    scanf("%s", word);

    length = strlen(word);

    for(i = 0, j = length - 1; i <= length/2; i++, j--){

        if(word[i] != word[j]){
            
            check = 1;
            break;
        }
    }

    if(check == 0){

        printf("\n%s is a palindrome!\n", word);
    }
    else{

        printf("\n%s is not a palindrome!\n", word);
    }

    return 0;
}