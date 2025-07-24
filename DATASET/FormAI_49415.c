//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* input){
    int length = strlen(input);
    for(int i=0; i<length/2; i++){
        if(input[i] != input[length-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    char input[1000];
    printf("Enter input string: ");
    scanf("%s", input);
    if(isPalindrome(input)){
        printf("%s is a palindrome\n", input);
    }
    else{
        printf("%s is not a palindrome\n", input);
    }
    return 0;
}