//FormAI DATASET v1.0 Category: String manipulation ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50], str2[50];

    // Prompt user to enter two strings
    printf("Enter the first string: ");
    fgets(str1, 50, stdin);
    printf("Enter the second string: ");
    fgets(str2, 50, stdin);

    // Remove new lines at the end of strings
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Combine the two strings with a space in between
    char combined[100];
    strcpy(combined, str1);
    strcat(combined, " ");
    strcat(combined, str2);

    // Print the combined string
    printf("Combined string: %s\n", combined);

    // Find the length of the combined string
    int length = strlen(combined);
    printf("Length of the combined string: %d\n", length);

    // Reverse the combined string
    char reversed[length + 1];
    int index = 0;
    for(int i = length - 1; i >= 0; i--) {
        reversed[index] = combined[i];
        index++;
    }
    reversed[length] = '\0';

    // Print the reversed string
    printf("Reversed string: %s\n", reversed);

    // Count the number of vowels in the reversed string
    int vowelCount = 0;
    for(int i = 0; i < length; i++) {
        if(reversed[i] == 'a' || reversed[i] == 'e' || reversed[i] == 'i'
            || reversed[i] == 'o' || reversed[i] == 'u') {
            vowelCount++;
        }
    }
    printf("Number of vowels in the reversed string: %d\n", vowelCount);

    return 0;
}