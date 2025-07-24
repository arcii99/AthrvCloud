//FormAI DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    printf("Enter second string: ");
    fgets(str2, 100, stdin);

    // Finding the length of the strings
    int length1 = strlen(str1) - 1; // fgets inputs '\n' while Enter is pressed, thus subtracting 1.
    int length2 = strlen(str2) - 1;

    // Concatenating the two strings and displaying the result
    printf("\nAfter concatenating the two strings: ");
    strcat(str1, str2);
    printf("%s", str1);

    // Reversing the first string and displaying the result
    printf("\n\nAfter reversing the first string: ");
    for(int i=0, j=length1-1; i<length1/2; i++, j--) {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }
    printf("%s", str1);

    // Checking if the second string is a palindrome
    int flag=1; // flag=1 means the string is a palindrome, flag=0 means the string is not a palindrome
    for(int i=0, j=length2-1; i<length2/2; i++, j--) {
        if(str2[i] != str2[j]) {
            flag=0;
            break;
        }
    }
    if(flag) printf("\n\nThe second string is a palindrome.");
    else printf("\n\nThe second string is not a palindrome.");

    // Counting the number of vowels in the first string and displaying the result
    int vowel_count=0;
    for(int i=0; i<length1; i++) {
        if(str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u'
            || str1[i]=='A' || str1[i]=='E' || str1[i]=='I' || str1[i]=='O' || str1[i]=='U') {
            vowel_count++;
        }
    }
    printf("\n\nThe first string contains %d vowels.", vowel_count);

    // Replacing all occurrences of a with x in the second string and displaying the result
    for(int i=0; i<length2; i++) {
        if(str2[i]=='a') {
            str2[i] = 'x';
        }
    }
    printf("\n\nAfter replacing all occurrences of a with x in the second string: %s", str2);

    return 0;
}