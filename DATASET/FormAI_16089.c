//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <string.h>

int scan(char filename[]) {
    FILE* fp;
    fp = fopen(filename, "r");

    char line[256];
    int line_number = 1;
    int virus_found = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "virus") != NULL) {
            printf("Virus found on line %d: %s", line_number, line);
            virus_found = 1;
        }
        line_number++;
    }

    fclose(fp);
    return virus_found;
}

int main() {
    char filename[] = "test.txt";
    int result = scan(filename);

    if (result) {
        printf("File '%s' contains a virus.\n",filename);
    } else {
        printf("File '%s' is clean.\n",filename);
    }

    return 0;
}