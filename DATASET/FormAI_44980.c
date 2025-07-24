//FormAI DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[50] = "Linus";
    char str2[] = "Torvalds";
    char buffer[100];
    int len1, len2, len3;

    // concatenate the strings
    strcat(str1, " ");
    strcat(str1, str2);

    // print the concatenated string
    printf("Hi, I am %s!\n", str1);

    // copy the concatenated string to the buffer
    strcpy(buffer, str1);

    // get the lengths of the strings
    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = strlen(buffer);

    // print the lengths
    printf("str1 length: %d\n", len1);
    printf("str2 length: %d\n", len2);
    printf("buffer length: %d\n", len3);

    // convert the first letter to uppercase
    str1[0] = toupper(str1[0]);

    // print the modified string
    printf("My name is %s\n", str1);

    // find the second occurrence of the letter 'o'
    char *ptr = strchr(str1 + 1, 'o');

    // print the substring after the second 'o'
    if (ptr != NULL) {
        printf("Substring after the second 'o': %s\n", ptr);
    }

    // replace all instances of 'o' with '0'
    char *pos;
    while ((pos = strchr(str1, 'o')) != NULL) {
        *pos = '0';
    }

    // print the modified string
    printf("Modified string: %s\n", str1);

    return 0;
}