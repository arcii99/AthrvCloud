//FormAI DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *string1 = malloc(1024);
    strncpy(string1, "hello world", 11);
    
    char *string2 = calloc(1, 1024);
    strncpy(string2, string1, strlen(string1));
    free(string1);
    
    char *string3 = realloc(string2, 2048);
    strncat(string3, ", how are you today?", 21);
    
    if(!string3) {
        fprintf(stderr, "Insufficient Memory");
        exit(EXIT_FAILURE);
    }
    
    printf("%s", string3);
    free(string3);
    
    return 0;
}