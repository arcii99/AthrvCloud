//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: careful
#include <stdio.h>

void scan_file(char *filename);

int main() {
    char filename[50];
    printf("Enter the file name (including extension): ");
    scanf("%s", filename);
    scan_file(filename);
    return 0;
}

void scan_file(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    char c;
    int virus_flag = 0;
    while((c = fgetc(file)) != EOF) {
        if(c == 'v' || c == 'V') {
            char buffer[4];
            buffer[0] = c;
            c = fgetc(file);
            buffer[1] = c;
            c = fgetc(file);
            buffer[2] = c;
            buffer[3] = '\0';
            if(strcmp(buffer, "vrs") == 0 || strcmp(buffer, "VRS") == 0) {
                virus_flag = 1;
                break;
            }
        }
    }
    fclose(file);
    if(virus_flag) {
        printf("%s is infected with virus!\n", filename);
    } else {
        printf("%s is not infected with virus.\n", filename);
    }
}