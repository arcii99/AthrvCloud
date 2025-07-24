//FormAI DATASET v1.0 Category: Data recovery tool ; Style: detailed
#include <stdio.h>

int main()
{
    FILE *fp;
    long size;

    fp = fopen("example.txt", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file!\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("File size: %ld bytes\n", size);

    fclose(fp);

    return 0;
}