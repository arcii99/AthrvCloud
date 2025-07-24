//FormAI DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end){
    if(start >= end) return;

    // Swap the characters at start and end indices
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call to reverse the substring between start+1 and end-1
    reverse(str, start+1, end-1);
}

void countVowels(char str[], int start, int end, int* count){
    if(start >= end) return;

    // Check if the character at start index is a vowel
    if(str[start] == 'a' || str[start] == 'e' || str[start] == 'i' ||
       str[start] == 'o' || str[start] == 'u' || str[start] == 'A' ||
       str[start] == 'E' || str[start] == 'I' || str[start] == 'O' ||
       str[start] == 'U'){
        (*count)++;
    }

    // Recursive call to count vowels in the substring between start+1 and end
    countVowels(str, start+1, end, count);
}

int main(){
    char str[50];

    // Input a string from user
    printf("Enter a string: ");
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    // Reverse the string using a recursive function
    reverse(str, 0, strlen(str)-1);

    printf("Reversed string: %s\n", str);

    // Count the number of vowels in the string using a recursive function
    int count = 0;
    countVowels(str, 0, strlen(str), &count);

    printf("Number of vowels: %d\n", count);

    return 0;
}