//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: energetic
#include <stdio.h>
#include <string.h>

int main(){
    char input[100];
    int i, j, flag = 0;

    printf("Enter a word to check if it's a palindrome: ");
    scanf("%s", input);

    int length = strlen(input);

    for(i=0, j=length-1; i<length/2; i++, j--){
        if(input[i] != input[j]){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        printf("\nSorry, '%s' is not a palindrome.\n", input);
    }
    else{
        printf("\nCongratulations! '%s' is a palindrome.\n", input);
    }

    return 0;
}