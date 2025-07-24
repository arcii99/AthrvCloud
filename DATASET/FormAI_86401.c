//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void handleError(int lineNum, const char* filename, const char* errorMsg) {
    fprintf(stderr, "ERROR: %s (File: %s, Line: %d) - %s\n", 
            strerror(errno), filename, lineNum, errorMsg);
    exit(1);
}

int main() {
    FILE* file = fopen("non_existent_file.txt", "r");
    if (file == NULL) {
        handleError(__LINE__, __FILE__, "File does not exist");
    }
    
    int nums[3] = {1, 2, 3};
    int index = 4;
    if (index >= sizeof(nums)/sizeof(nums[0])) {
        handleError(__LINE__, __FILE__, "Index is out of bounds");
    }
    
    char* str = malloc(sizeof(char) * 6);
    if (str == NULL) {
        handleError(__LINE__, __FILE__, "Memory allocation failed");
    }
    
    strcpy(str, "hello world");
    if (strlen(str) > 5) {
        handleError(__LINE__, __FILE__, "String is too long");
    }
    
    free(str);
    return 0;
}