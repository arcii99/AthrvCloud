//FormAI DATASET v1.0 Category: Error handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Error Handling Example Program!\n\n");
    printf("Please enter a number between 1 and 10: ");
    int num;
    scanf("%d", &num);
    if (num < 1 || num > 10) {
        fprintf(stderr, "Error: Number must be between 1 and 10.\n");
        exit(1);
    }
    
    printf("\nPlease enter a file name to open: ");
    char filename[50];
    scanf("%s", filename);
    FILE *fp;
    fp = fopen(filename, "r");
    if (!fp) {
        perror("Error");
        exit(1);
    }
    
    printf("\nPlease enter a string to output: ");
    char str[50];
    scanf("%s", str);
    
    if (fprintf(fp, "%s\n", str) < 0) {
        fprintf(stderr, "Error writing to file.\n");
        fclose(fp);
        exit(1);
    }
    
    printf("\nProgram has successfully written to file.\n");
    fclose(fp);
    return 0;
}