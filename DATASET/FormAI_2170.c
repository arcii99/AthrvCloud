//FormAI DATASET v1.0 Category: Data recovery tool ; Style: expert-level
/* C Data Recovery Tool - Expert Level Example Program */

#include <stdio.h>
#include <stdlib.h>

/* Function to recover data from file */
void recoverData(char* filename) {
    FILE *fp;
    int i, k, size;
    char* buffer[100];
    
    /* Open file for reading */
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.");
        exit(1);
    }
    
    /* Get size of file */
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    /* Read data from file into buffer */
    fread(buffer, sizeof(char), size, fp);
    fclose(fp);
    
    /* Parse buffer for recovery */
    for (i = 0; i < size; i++) {
        /* Check current character for punctuation or space */
        if (buffer[i] == ',' || buffer[i] == '.' || buffer[i] == ' ') {
            /* Reconstruct word and print */
            for (k = i-1; k >= 0; k--) {
                /* Check for end of word */
                if (buffer[k] == ',' || buffer[k] == '.' || buffer[k] == ' ') {
                    printf(" ");
                    break;
                }
                else {
                    printf("%c", buffer[k]);
                }
            }
            /* Print punctuation or space */
            printf("%c", buffer[i]);
        }
    }
}

int main() {
    char* filename = "data.txt";
    printf("Recovered data from file %s:\n", filename);
    recoverData(filename);
    return 0;
}