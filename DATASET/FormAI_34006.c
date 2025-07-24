//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int main(){
    char str[100]; //maximum input size

    printf("Enter the string to check for palindrome: ");
    scanf("%s", str);

    int length = strlen(str);
    int i, j, mid = length/2, palindrome = 1; //initialize palindrome to true

    for (i = 0, j = length-1; i < mid; i++, j--){
        if (str[i] != str[j]){
            palindrome = 0; //set palindrome to false
            break;
        }
    }

    if (palindrome){
        printf("%s is a palindrome!\n", str);
    }
    else {
        printf("%s is not a palindrome!\n", str);
    }

    return 0;
}