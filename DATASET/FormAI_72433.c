//FormAI DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

int main() {
    FILE *fp;
    char fileName[20];
    int num;
    bool success = false;
    
    while(!success) {
        printf("Enter a file name: ");
        scanf("%s", fileName);
        
        fp = fopen(fileName, "r");
        if(fp == NULL) {
            if(errno == ENOENT) {
                printf("File does not exist.\n");
            } else {
                printf("Unable to open file: %s\n", strerror(errno));
            }
            continue;
        }
        
        success = true;
    }
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(ferror(stdin)) {
        printf("Error reading input: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("The number you entered is: %d\n", num);
    
    if(fclose(fp) != 0) {
        printf("Error closing file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    return 0;
}