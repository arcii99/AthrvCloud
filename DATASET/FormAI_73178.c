//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int scan(char *filename);
int is_virus(char *buffer);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
    } else {
        for (int i = 1; i < argc; i++) {
            if (scan(argv[i])) {
                printf("%s infected with virus!\n", argv[i]);
            } else {
                printf("%s clean.\n", argv[i]);
            }
        }
    }
    return 0;
}

int scan(char *filename) {
    int infected = 0;
    FILE *fp;
    char buffer[MAX_SIZE] = {0};
    fp = fopen(filename, "rb");
    if (fp != NULL) {
        while (fread(buffer, 1, MAX_SIZE, fp) == MAX_SIZE) {
            if (is_virus(buffer)) {
                infected = 1;
                break;
            }
        }
        fclose(fp);
    }
    return infected;
}

int is_virus(char *buffer) {
    // This is a simple example of virus scanning 
    // based on a specific virus signature "virus123".
    // In real-world scenarios, more complex scanning algorithms 
    // and virus signature databases are used.

    char signature[] = "virus123";
    char *match = strstr(buffer, signature);
    if (match != NULL) {
        return 1;
    } else {
        return 0;
    }
}