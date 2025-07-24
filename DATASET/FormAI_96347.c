//FormAI DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>

void backup(char *path) {
    char command[100], date[20];
    time_t t = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", gmtime(&t)); // get the current date in YYYY-MM-DD format
    sprintf(command, "cp -r %s %s.bak.%s", path, path, date); // create a backup copy with the current date in the file name
    system(command); // execute the command
    printf("Backup created for %s\n", path);
}

int main() {
    char path[100];
    printf("Enter the path for the directory to backup: ");
    scanf("%s", path);
    DIR *dir = opendir(path);
    if (dir) { // if the directory exists
        backup(path); // create a backup
        closedir(dir);
        return 0; // exit the program successfully
    } else { // if the directory does not exist
        printf("Directory not found.\n");
        return 1; // exit the program with an error
    }
}