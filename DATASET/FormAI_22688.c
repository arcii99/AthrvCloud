//FormAI DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to safely concatenate C strings */
void safe_concat(char* dest, size_t dest_size, const char* src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    
    if (dest_len + src_len < dest_size) {
        strcat(dest, src);
    } else {
        size_t space_left = dest_size - dest_len - 1;
        strncat(dest, src, space_left);
    }
}

int main() {
    char str1[20] = "Hello, ";
    char str2[8] = "world!";
    
    safe_concat(str1, sizeof(str1), str2);
    
    printf("%s\n", str1);
    
    char str3[8] = "Welcome";
    char str4[8] = " home!";
    
    safe_concat(str3, sizeof(str3), str4);
    
    printf("%s\n", str3);
    
    char str5[8] = "Overflow";
    char str6[12] = " detected!";
    
    safe_concat(str5, sizeof(str5), str6);
    
    printf("%s\n", str5);
    
    return 0;
}