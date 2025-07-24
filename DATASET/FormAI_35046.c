//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <string.h>

void scan_file(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_path);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, file) != NULL) {
        int len = strlen(buffer);
        if (len > 2 && buffer[len - 2] == '\r') {
            buffer[len - 2] = '\0';
        } else if (len > 1 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && (buffer[i+3] == 'u' || buffer[i+3] == 'a') && buffer[i+4] == 's') {
                printf("Virus detected in file %s\n", file_path);
                fclose(file);
                return;
            }
        }
    }

    printf("No virus found in file %s\n", file_path);
    fclose(file);
}

int main() {
    char file1[] = "/var/files/test1.txt";
    char file2[] = "/var/files/test2.txt";
    char file3[] = "/var/files/test3.txt";

    scan_file(file1);
    scan_file(file2);
    scan_file(file3);

    return 0;
}