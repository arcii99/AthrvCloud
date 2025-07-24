//FormAI DATASET v1.0 Category: String manipulation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// Define our own strcat function
void my_strcat(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

// Define our own strstr function
char *my_strstr(char *haystack, const char *needle) {
    while (*haystack) {
        char *start = haystack;
        const char *substr = needle;
        while (*haystack && *substr && *haystack == *substr) {
            haystack++;
            substr++;
        }
        if (!*substr) {
            return start;
        }
        haystack = start + 1;
    }
    return NULL;
}

int main() {
    char string1[50] = "Hello, ";
    char string2[50] = "world!";
    char string3[50] = "the quick brown fox jumps over the lazy dog";

    // Using strcat function
    my_strcat(string1, string2);
    printf("%s\n", string1); // Output: Hello, world!

    // Using strchr function
    printf("%s\n", strchr(string1, 'o')); // Output: o, world!

    // Using strstr function
    printf("%s\n", my_strstr(string3, "brown")); // Output: brown fox jumps over the lazy dog

    return 0;
}