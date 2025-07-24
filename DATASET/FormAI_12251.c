//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_NUM_FILES 1000

typedef struct {
    char name[MAX_FILENAME_LEN];
    int size;
} File;

typedef struct {
    File files[MAX_NUM_FILES];
    int num_files;
} Directory;

int main() {

    // welcome message
    printf("Hello, I am your C File Backup System!\n");
    printf("You can use me to backup your important files.\n");

    // initialize empty directory
    Directory dir;
    dir.num_files = 0;

    // loop for user input
    while (1) {

        // display menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Add a file to the backup\n");
        printf("2. Remove a file from the backup\n");
        printf("3. List all files in the backup\n");
        printf("4. Backup all files\n");
        printf("5. Exit\n");

        // get user input
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); // consume newline

        // handle user input
        switch (choice) {

            case 1: // add file

                // get file name and size
                char name[MAX_FILENAME_LEN];
                printf("Enter the name of the file: ");
                fgets(name, MAX_FILENAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // remove trailing newline
                int size;
                printf("Enter the size of the file in bytes: ");
                scanf("%d", &size);
                getchar(); // consume newline

                // create file object and add to directory
                File file;
                strcpy(file.name, name);
                file.size = size;
                dir.files[dir.num_files++] = file;

                // confirmation message
                printf("File added to backup: %s\n", name);
                break;

            case 2: // remove file

                // get file name to remove
                char remove_name[MAX_FILENAME_LEN];
                printf("Enter the name of the file to remove: ");
                fgets(remove_name, MAX_FILENAME_LEN, stdin);
                remove_name[strcspn(remove_name, "\n")] = 0; // remove trailing newline

                // loop through directory to find matching file
                int i;
                for (i = 0; i < dir.num_files; i++) {
                    if (strcmp(remove_name, dir.files[i].name) == 0) {
                        // shift all files after remove file down by 1 to account for removed file
                        for (int j = i; j < dir.num_files - 1; j++) {
                            dir.files[j] = dir.files[j+1];
                        }
                        dir.num_files--;
                        // confirmation message
                        printf("File removed from backup: %s\n", remove_name);
                        break;
                    }
                }
                // file not found message
                if (i == dir.num_files) {
                    printf("File not found in backup: %s\n", remove_name);
                }
                break;

            case 3: // list all files

                // loop through directory to print all file names
                for (int i = 0; i < dir.num_files; i++) {
                    printf("%s\n", dir.files[i].name);
                }
                break;

            case 4: // backup all files

                // check if directory is empty
                if (dir.num_files == 0) {
                    printf("Error: Backup directory is empty.\n");
                    break;
                }

                // create backup file with timestamp
                char timestamp[50];
                time_t t = time(NULL);
                struct tm *tm = localtime(&t);
                strftime(timestamp, sizeof(timestamp), "%Y%m%d-%H%M%S", tm);
                char backup_filename[MAX_FILENAME_LEN];
                sprintf(backup_filename, "backup-%s.tar.gz", timestamp);
                FILE *backup = fopen(backup_filename, "w");

                // loop through directory to add each file to backup
                for (int i = 0; i < dir.num_files; i++) {
                    FILE *fp = fopen(dir.files[i].name, "r");
                    if (fp != NULL) {
                        char buffer[dir.files[i].size];
                        fread(&buffer, dir.files[i].size, 1, fp);
                        fwrite(&buffer, dir.files[i].size, 1, backup);
                        printf("File backed up: %s\n", dir.files[i].name);
                        fclose(fp);
                    } else {
                        printf("Error: File not found: %s\n", dir.files[i].name);
                    }
                }

                // confirmation message
                printf("All files backed up to %s!\n", backup_filename);
                fclose(backup);
                break;

            case 5: // exit program
                printf("Goodbye! Thanks for using C File Backup System.\n");
                exit(0);

            default: // invalid input
                printf("Invalid choice. Please select a number from 1 to 5.\n");
                break;
        }
    }

    return 0;
}