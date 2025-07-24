//FormAI DATASET v1.0 Category: Data recovery tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to recover lost data */
void data_recovery(char *file_name) {
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("File doesn't exist.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    char *buffer = (char *)malloc(file_size);
    fread(buffer, 1, file_size, fp);

    fclose(fp);

    FILE *recover_file = fopen("recovered_data.txt", "w");
    fwrite(buffer, 1, file_size, recover_file);

    fclose(recover_file);
    free(buffer);

    printf("Data recovered and saved to file 'recovered_data.txt'.\n");
}

int main() {
    char file_name[100];

    printf("Enter the name of the file to recover: ");
    fgets(file_name, 100, stdin);
    file_name[strcspn(file_name, "\n")] = 0;

    data_recovery(file_name);

    return 0;
}