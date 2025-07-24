//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 1000
#define MAX_SCAN_DEPTH 10


/* Function prototypes */
void scan(char path[], int depth);
void check_file(char path[]);


/**
 * Main function
 */
int main(int argc, char *argv[]) {

    /* Check if path is provided */
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        exit(1);
    }

    /* Get path from command line argument */
    char path[MAX_PATH_LEN];
    strcpy(path, argv[1]);

    /* Scan the directory */
    scan(path, 0);

    return 0;
}


/**
 * Function to scan the directory recursively
 */
void scan(char path[], int depth) {

    /* Check if maximum depth is reached */
    if (depth > MAX_SCAN_DEPTH) {
        return;
    }

    /* Open directory */
    DIR *dir = opendir(path);

    /* Check if directory opened successfully */
    if (dir == NULL) {
        printf("Error: Unable to open directory %s!\n", path);
        return;
    }

    /* Loop through files in directory */
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {

        /* Ignore parent and current directory */
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        /* Get file path */
        char file_path[MAX_PATH_LEN];
        snprintf(file_path, MAX_PATH_LEN, "%s/%s", path, entry->d_name);

        /* Check if directory */
        if (entry->d_type == DT_DIR) {
            
            /* Recursively scan subdirectory */
            scan(file_path, depth + 1);
            
        } else if (entry->d_type == DT_REG) {

            /* Check the file */
            check_file(file_path);

        }

    }

    /* Close directory */
    closedir(dir);
}


/**
 * Function to check file
 */
void check_file(char path[]) {

    /* Open file */
    FILE *file = fopen(path, "r");

    /* Check if file opened successfully */
    if (file == NULL) {
        printf("Error: Unable to open file %s!\n", path);
        return;
    }

    /* Read file */
    char c;
    while ((c = fgetc(file)) != EOF) {

        /* Check for virus signature */
        if (c == 'C' || c == 'c') {
            printf("Warning: Virus detected in file %s!\n", path);
            break;
        }

    }

    /* Close file */
    fclose(file);
}