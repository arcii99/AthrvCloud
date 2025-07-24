//FormAI DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_logo() {
    printf("███████╗██╗      █████╗ ███████╗██╗  ██╗███████╗███████╗\n");
    printf("██╔════╝██║     ██╔══██╗██╔════╝██║ ██╔╝██╔════╝██╔════╝\n");
    printf("███████╗██║     ███████║███████╗█████╔╝ █████╗  █████╗  \n");
    printf("╚════██║██║     ██╔══██║╚════██║██╔═██╗ ██╔══╝  ██╔══╝  \n");
    printf("███████║███████╗██║  ██║███████║██║  ██╗███████╗███████╗\n");
    printf("╚══════╝╚══════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝\n\n");
}

void recover_data(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("File not found!\n");
    } else {
        fseek(fp, 0L, SEEK_END);
        long int file_size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);
        char *buffer = (char*)malloc(file_size * sizeof(char));
        fread(buffer, file_size, 1, fp);
        fclose(fp);

        char *new_filename = (char*)malloc(strlen(filename) + 8);
        strcpy(new_filename, "recovered_");
        strcat(new_filename, filename);
        fp = fopen(new_filename, "wb");
        fwrite(buffer, file_size, 1, fp);
        fclose(fp);
        free(new_filename);
        free(buffer);

        printf("File successfully recovered!\n");
    }
}

int main() {
    print_logo();
    char filename[20];
    printf("Enter the name of the file you want to recover: ");
    scanf("%s", filename);
    recover_data(filename);
    return 0;
}