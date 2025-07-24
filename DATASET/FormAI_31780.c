//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 256

void scan_file(char *file_name, char *virus_signature_file);
void scan_directory(char *directory_path, char *virus_signature_file);
int search_string_in_file(char *string, char *file_name);

int main(int argc, char **argv)
{
    char *file_name = NULL;
    char *directory_path = NULL;
    char *virus_signature_file = "virus_definitions.txt";

    if (argc == 2) {
        file_name = argv[1];
        printf("Scanning file %s for viruses...\n", file_name);
        scan_file(file_name, virus_signature_file);
    } else if (argc == 3) {
        directory_path = argv[2];
        printf("Scanning directory %s for viruses...\n", directory_path);
        scan_directory(directory_path, virus_signature_file);
    } else {
        printf("Invalid arguments. Usage: %s <file_name> OR %s -d <directory_path>\n", argv[0], argv[0]);
        return -1;
    }

    printf("Scan complete.\n");

    return 0;
}

void scan_file(char *file_name, char *virus_signature_file)
{
    char signature[256];
    FILE *virus_signature = fopen(virus_signature_file, "r");
    if (virus_signature == NULL) {
        printf("Virus signature file not found.\n");
        return;
    }

    while (fgets(signature, 256, virus_signature)) {
        if (strlen(signature) > 0 && signature[strlen(signature) - 1] == '\n') {
            signature[strlen(signature) - 1] = '\0';
        }
        if (search_string_in_file(signature, file_name)) {
            printf("Virus detected: %s\n", signature);
        }
    }

    fclose(virus_signature);
}

void scan_directory(char *directory_path, char *virus_signature_file)
{
    char command[MAX_FILE_PATH];
    sprintf(command, "find %s -type f", directory_path);

    FILE *pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("Error opening pipe.\n");
        return;
    }

    char file_name[MAX_FILE_PATH];
    while (fgets(file_name, MAX_FILE_PATH, pipe)) {
        if (strlen(file_name) > 0 && file_name[strlen(file_name) - 1] == '\n') {
            file_name[strlen(file_name) - 1] = '\0';
        }
        scan_file(file_name, virus_signature_file);
    }

    pclose(pipe);
}

int search_string_in_file(char *string, char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return 0;
    }

    char buffer[256];
    int found = 0;
    while (fgets(buffer, 256, file)) {
        if (strstr(buffer, string) != NULL) {
            found = 1;
            break;
        }
    }

    fclose(file);

    return found;
}