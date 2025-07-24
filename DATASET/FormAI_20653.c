//FormAI DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error()
{
    printf("[ERROR] %s\n", strerror(errno));
    exit(EXIT_FAILURE);
}

int main()
{
    FILE *fp;

    fp = fopen("non_existent_file.txt", "r");
    
    if (fp == NULL) {
        printf("File could not be opened.\n");
        handle_error();
    } else {
        printf("File opened successfully.\n");
        fclose(fp);
    }

    return 0;
}