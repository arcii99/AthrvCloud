//FormAI DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_FILE_LEN 100 // Maximum length of file name
#define MAX_BUF_SIZE 1024 // Maximum buffer size for reading/writing files

int main()
{
    char src_file[MAX_FILE_LEN], dest_file[MAX_FILE_LEN], buffer[MAX_BUF_SIZE];
    FILE *fp_src, *fp_dest;
    int read_len, write_len;

    printf("Enter the name of the file to backup: ");
    fgets(src_file, MAX_FILE_LEN, stdin);

    // Removing trailing newline character from file name
    src_file[strcspn(src_file, "\n")] = '\0';

    // Generating backup file name (adding .bak extension)
    strncpy(dest_file, src_file, MAX_FILE_LEN - 4);
    strcat(dest_file, ".bak");

    // Opening source file for reading
    fp_src = fopen(src_file, "r");

    if(fp_src == NULL)
    {
        printf("Error: could not open source file.\n");
        return 1;
    }

    // Opening destination file for writing
    fp_dest = fopen(dest_file, "w");

    if(fp_dest == NULL)
    {
        fclose(fp_src);
        printf("Error: could not create backup file.\n");
        return 1;
    }

    // Reading from source file and writing to destination file
    while((read_len = fread(buffer, sizeof(char), MAX_BUF_SIZE, fp_src)) > 0)
    {
        write_len = fwrite(buffer, sizeof(char), read_len, fp_dest);

        if(write_len != read_len)
        {
            fclose(fp_src);
            fclose(fp_dest);
            printf("Error: could not backup file.\n");
            return 1;
        }
    }

    // Closing files
    fclose(fp_src);
    fclose(fp_dest);

    printf("Backup file created successfully.\n");
    return 0;
}