//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("nonexistent_file.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file!\n");
        return 1;
    }

    //rest of the program

    return 0;
}