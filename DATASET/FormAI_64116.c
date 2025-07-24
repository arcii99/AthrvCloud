//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    char file_name[100];
    printf("Enter a file name: ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strlen(file_name) - 1] = '\0';  // remove newline character from input
    
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }
    
    // read file contents
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    
    if (ferror(fp)) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
    }
    
    fclose(fp);
    return 0;
}