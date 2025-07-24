//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include <stdio.h> 

void reverseString(char string[]){ 
    int length = 0;
    while(string[length] != '\0'){
        length++;
    }

    char reversedString[length+1];
    int i, j;
    for(i = length-1, j = 0; i >= 0; i--, j++){
        reversedString[j] = string[i];
    }
    reversedString[j] = '\0';

    printf("Reversed string is: %s\n", reversedString);

    if(strcmp(string,reversedString) == 0){
        printf("The string is a Palindrome.\n");
    }
    else{
        printf("The string is not a Palindrome.\n");
    }

}

int main(){
    char string[100];
    printf("Enter the string: ");
    scanf("%s", string);

    reverseString(string);

    return 0;
}