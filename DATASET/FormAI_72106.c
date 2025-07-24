//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Define a variable for number of bytes in a KB
#define BYTES_IN_KB 1024

// Function to calculate the size of a folder
int folderSize(char* folderName) {
    // Define a variable to store the total size of the folder
    int totalSize = 0;
    DIR *folder;
    struct dirent *entry;
    struct stat folderInfo;
    char* folderPath = (char*)malloc(sizeof(char)*(strlen(folderName)+2));

    // Open the folder
    folder = opendir(folderName);

    // If opening the folder failed, return 0
    if(folder == NULL) {
        return 0;
    }

    // Loop through all the entries in the folder
    while((entry = readdir(folder))) {
        // Ignore the . and .. entries
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path of the entry
        sprintf(folderPath, "%s/%s", folderName, entry->d_name);

        // Get the information about the entry
        if(lstat(folderPath, &folderInfo) == -1) {
            printf("Could not get information about %s\n", folderPath);
            continue;
        }

        // If the entry is a file, add its size to the totalSize variable
        if(S_ISREG(folderInfo.st_mode)) {
            totalSize += folderInfo.st_size;
        }
        // If the entry is a folder, recursively call the folderSize function
        else if(S_ISDIR(folderInfo.st_mode)) {
            totalSize += folderSize(folderPath);
        }
    }

    // Close the folder and free the memory used
    closedir(folder);
    free(folderPath);

    return totalSize;
}

int main() {
    // Define a variable to store the total size of the C drive
    int cDriveSize = 0;
    // Define variables to store the size of each folder
    int windowsSize, programFilesSize, usersSize;

    // Calculate the size of the Windows folder on the C drive
    windowsSize = folderSize("/Windows");

    // Calculate the size of the Program Files folder on the C drive
    programFilesSize = folderSize("/Program Files");

    // Calculate the size of the Users folder on the C drive
    usersSize = folderSize("/Users");

    // Add up the sizes to get the total size of the C drive
    cDriveSize = windowsSize + programFilesSize + usersSize;

    // Display the results to the user
    printf("The size of the Windows folder is %d KB\n", windowsSize/BYTES_IN_KB);
    printf("The size of the Program Files folder is %d KB\n", programFilesSize/BYTES_IN_KB);
    printf("The size of the Users folder is %d KB\n", usersSize/BYTES_IN_KB);
    printf("The total size of the C drive is %d KB\n", cDriveSize/BYTES_IN_KB);

    // Return 0 to indicate that the program ran successfully
    return 0;
}