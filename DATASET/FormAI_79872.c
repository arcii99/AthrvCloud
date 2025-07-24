//FormAI DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "hello world";
    char str2[50] = "how are you?";
    char str3[50] = "12345";

    // Concatenate two strings
    char str4[100] = "";
    strcpy(str4, str1);
    strcat(str4, str2);
    printf("Concatenated strings: %s\n", str4);

    // Reverse a string
    printf("Original string: %s\n", str1);
    int len = strlen(str1);
    for (int i = 0; i < len / 2; i++) {
        char temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str1);

    // Convert string to integer
    int num = atoi(str3);
    printf("Integer value: %d\n", num);

    // Convert integer to string
    char str5[50];
    sprintf(str5, "%d", num);
    printf("String value: %s\n", str5);

    // Find substring
    char* ptr = strstr(str4, "are");
    printf("Substring found at: %ld\n", ptr - str4);

    // Replace a character in a string
    char* pos = strchr(str1, 'l');
    pos[0] = 'L';
    printf("Replaced string: %s\n", str1);

    return 0;
}