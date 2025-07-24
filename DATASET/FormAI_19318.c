//FormAI DATASET v1.0 Category: String manipulation ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[50];
    char *p;

    // Using strcat to concatenate str1 and str2
    strcat(str1, str2);

    printf("After concatenation: %s\n", str1);

    // Using strcpy to copy str1 to str3
    strcpy(str3, str1);

    printf("str3 after copying str1: %s\n", str3);

    // Using strlen to get the length of str1
    printf("Length of str1: %d\n", strlen(str1));

    // Using strchr to find the first occurrence of 'o' in str1
    p = strchr(str1, 'o');
    printf("First occurrence of 'o' in str1: %s\n", p);

    // Using strstr to find the first occurrence of 'World' in str1
    p = strstr(str1, "World");
    printf("First occurrence of 'World' in str1: %s\n", p);

    // Using memset to set the first 5 bytes of str1 to 'Z'
    memset(str1, 'Z', 5);

    printf("str1 after memset: %s\n", str1);

    return 0;
}