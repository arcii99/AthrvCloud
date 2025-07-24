//FormAI DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void error(char* message) {
    printf("Error: %s\n", message);
    exit(1);
}

int main() {
    FILE* file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        error(strerror(errno));
    }

    char str[100];
    if (fgets(str, 100, file) == NULL) {
        error("Failed to read from file");
    }

    printf("Contents of file: %s", str);
    return 0;
}