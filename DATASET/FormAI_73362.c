//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: secure
#include <stdio.h>
#include <string.h>

// define maximum file path length
#define MAX_FILE_PATH_LEN 256

int scan_file(char *file_path) {
    char command[MAX_FILE_PATH_LEN + 16];
    sprintf(command, "clamscan %s", file_path);

    // execute clamscan command
    FILE *fp = popen(command, "r");

    // read the result
    char result[32];
    fgets(result, sizeof(result), fp);

    // close the stream
    pclose(fp);

    // check if the result contains virus
    if (strstr(result, "FOUND") != NULL) {
        printf("%s contains virus!\n", file_path);
        return 1;
    }

    return 0;
}

int main(void) {
    char file_path[MAX_FILE_PATH_LEN];

    printf("Enter file path to scan: ");
    fgets(file_path, sizeof(file_path), stdin);

    // remove newline character from the end
    file_path[strcspn(file_path, "\n")] = 0;

    // scan the file
    if (scan_file(file_path) == 0) {
        printf("%s is clean!\n", file_path);
    }

    return 0;
}