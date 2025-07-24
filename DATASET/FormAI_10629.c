//FormAI DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

// Function to safely concatenate two strings
char* safe_strcat(char* dest, const char* src, size_t size) {
    size_t dest_len = strnlen(dest, size);
    size_t src_len = strnlen(src, size - dest_len - 1);
    if (dest_len + src_len >= size) {
        return dest;
    }
    strncpy(dest + dest_len, src, src_len);
    dest[dest_len + src_len] = '\0';
    return dest;
}

// Function to safely copy a string
char* safe_strcpy(char* dest, const char* src, size_t size) {
    if (strlen(src) >= size) {
        return dest;
    }
    strncpy(dest, src, size);
    return dest;
}

// Function to safely compare two strings
int safe_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int main() {
    char buffer[BUFFER_SIZE];
    char message[] = "Hello, world!";

    // Safely copy a string
    safe_strcpy(buffer, message, BUFFER_SIZE);
    printf("Original message: %s\n", message);
    printf("Copied message: %s\n", buffer);

    // Safely concatenate two strings
    char greeting[] = "Hi, ";
    char name[] = "Alice";
    safe_strcat(greeting, name, sizeof(greeting));
    printf("%s\n", greeting);

    // Safely compare two strings
    char password[] = "password123";
    char input[] = "password";
    int result = safe_strcmp(password, input);
    if (result == 0) {
        printf("Access granted!\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}