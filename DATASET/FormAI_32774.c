//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char str1[50] = "Hello World!";
    char str2[50] = "How are you?";
    char str3[50] = "";

    // Copying str1 to str3
    strncpy(str3, str1, 5);
    printf("str3 after copying str1: %s\n", str3);

    // Clearing str3 and concatenating str2
    memset(str3, 0, sizeof(str3));
    strncpy(str3, str2, 4); // Copying only first 4 characters
    strncat(str3, str1 + 6, sizeof(str3) - strlen(str3) - 1); // Concatenating with str1 from the 7th character
    printf("str3 after concatenating str2: %s\n", str3);

    // Reversing str1
    int len = strlen(str1);
    char temp;
    for (int i = 0; i < len/2; i++) {
        temp = str1[i];
        str1[i] = str1[len-1-i];
        str1[len-1-i] = temp;
    }
    printf("str1 after reversing: %s\n", str1);

    // Reversing str2 in place
    for (int i = 0, j = strlen(str2)-1; i < j; i++, j--) {
        temp = str2[i];
        str2[i] = str2[j];
        str2[j] = temp;
    }
    printf("str2 after reversing in place: %s\n", str2);

    // Finding the index of the first occurrence of 'o' in str1
    char* ptr = strchr(str1, 'o');
    if (ptr != NULL) {
        printf("The first occurrence of 'o' in str1 is at index: %ld\n", ptr - str1);
    } else {
        printf("'o' not found in str1\n");
    }

    // Finding the index of the last occurrence of 'o' in str2
    ptr = strrchr(str2, 'o');
    if (ptr != NULL) {
        printf("The last occurrence of 'o' in str2 is at index: %ld\n", ptr - str2);
    } else {
        printf("'o' not found in str2\n");
    }

    return 0;
}