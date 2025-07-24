//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: minimalist
#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome or not
void isPalindrome(char str[]) {
    // Get the length of the string
    int n = strlen(str);
 
    // Initialize flag variable to true
    int flag = 1;
 
    // Check if the string is a palindrome by comparing the characters
    for (int i = 0; i < n/2; i++) {
        if (str[i] != str[n-i-1]) {
            flag = 0;
            break;
        }
    }
 
    // Print the result
    if (flag == 1)
        printf("%s is a palindrome", str);
    else
        printf("%s is not a palindrome", str);
}
 
// Driver program to test the above function
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    isPalindrome(str);
 
    return 0;
}