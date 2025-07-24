//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Ken Thompson Style Searching Algorithm Example Program

int main() {
    char* haystack = "The quick brown fox jumps over the lazy dog";
    char* needle = "fox";
    
    int i = 0, j = 0, len = 0;
    while(haystack[len]) len++;
    
    for(i = 0; i < len; i++) {
        int flag = 1;
        for(j = 0; needle[j]; j++) {
            if(haystack[i+j] != needle[j]) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            printf("Found '%s' at position %d\n", needle, i);
            exit(0);
        }
    }
    
    printf("'%s' not found.\n", needle);
    return 0;
}