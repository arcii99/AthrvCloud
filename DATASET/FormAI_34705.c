//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: optimized
#include <stdio.h>
#include <string.h>

int isPalindrome(char* string){
    int length = strlen(string);
    for(int i=0; i<length/2; i++){
        if(string[i] != string[length-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    char string[100];
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    // Remove the newline character from the end of the string
    string[strcspn(string, "\n")] = 0;
    if(isPalindrome(string)){
        printf("%s is a palindrome", string);
    }
    else{
        printf("%s is not a palindrome", string);
    }
    return 0;
}