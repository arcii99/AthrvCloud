//FormAI DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void recover_data(const char *file_name)
{
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        printf("Could not open file for reading: %s\n", file_name);
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    int file_number = 0;
    size_t bytes_read = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0)
    {
        char file[BUFFER_SIZE];
        snprintf(file, BUFFER_SIZE, "file_%d.dat", file_number);
        FILE *fw = fopen(file, "wb");
        if (fw == NULL)
        {
            printf("Could not open file for writing: %s\n", file);
            fclose(fp);
            return;
        }
        fwrite(buffer, bytes_read, 1, fw);
        fclose(fw);
        file_number++;
    }

    fclose(fp);
}

int main()
{
    char *file_name = "data.dat";
    recover_data(file_name);

    printf("Data recovery completed successfully!\n");
    return 0;
}