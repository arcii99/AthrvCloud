//FormAI DATASET v1.0 Category: String manipulation ; Style: content
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[50] = ", World!";
    char str3[50];

    // Copying str1 and str2 into str3
    strcpy(str3, str1);
    strcat(str3, str2); // Concatenating str1 and str2

    printf("The concatenated string is: %s\n", str3);

    // Reversing the string
    char str4[50] = "racecar";
    int len = strlen(str4);
    char temp;

    for (int i = 0; i < len / 2; i++) {
        // Swap characters from the beginning and end
        temp = str4[i];
        str4[i] = str4[len - 1 - i];
        str4[len - 1 - i] = temp;
    }

    printf("The reversed string is: %s\n", str4);

    // Counting vowels in a string
    char str5[50] = "This is a sentence";
    int count = 0;

    for (int i = 0; str5[i] != '\0'; i++) {
        // Check if character is a vowel
        if (str5[i] == 'a' || str5[i] == 'e' || str5[i] == 'i' || str5[i] == 'o' || str5[i] == 'u') {
            count++;
        }
    }

    printf("There are %d vowels in the string.\n", count);

    return 0;
}