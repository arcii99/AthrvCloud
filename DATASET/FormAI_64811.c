//FormAI DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s [input_file_name]\n", argv[0]);
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");
    
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    char buffer[1024];
    int line_num = 1;
    
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strlen(buffer) > 200) {
            printf("Error: line %d is too long (maximum allowed length is 200 characters)\n", line_num);
            exit(1);
        }
        printf("%s", buffer);
        line_num++;
    }

    if (ferror(fp)) {
        printf("Error reading from file %s\n", argv[1]);
        exit(1);
    }
    
    fclose(fp);
    return 0;
}