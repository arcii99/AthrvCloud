//FormAI DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Define a constant for the maximum length of a bootable file path
#define MAX_FILE_PATH_LEN 256

// Define a constant for the maximum number of bootable files
#define MAX_BOOT_FILES 10

// Define a structure to hold information about a bootable file
typedef struct {
    char path[MAX_FILE_PATH_LEN];
    bool enabled; 
} BootFile;

// Define a global array of bootable file structures
BootFile bootFiles[MAX_BOOT_FILES];

// Define a function to print the menu options
void print_menu() {
    printf("1. Add bootable file\n");
    printf("2. Remove bootable file\n");
    printf("3. Enable/disable bootable file\n");
    printf("4. Show bootable files\n");
    printf("5. Optimize boot sequence\n");
    printf("6. Exit\n\n");
    printf("Select an option: ");
}

// Define a function to validate a file path
bool validate_path(char *path) {
    // Check if the path is too long
    if (strlen(path) > MAX_FILE_PATH_LEN) {
        printf("Error: Path is too long\n");
        return false;
    }
    // Check if the path contains any invalid characters
    for (int i = 0; path[i] != '\0'; i++) {
        if (!isalnum(path[i]) && path[i] != '_' && path[i] != '/' && path[i] != '.') {
            printf("Error: Path contains invalid character: %c\n", path[i]);
            return false;
        }
    }
    return true;
}

// Define a function to add a bootable file to the array
void add_boot_file() {
    // Get the file path from the user
    char path[MAX_FILE_PATH_LEN];
    bool valid_path = false;
    do {
        printf("Enter the file path: ");
        fgets(path, MAX_FILE_PATH_LEN, stdin);
        // Remove trailing newline character
        path[strcspn(path, "\n")] = '\0';
        valid_path = validate_path(path);
    } while (!valid_path);
    
    // Check if the array is full
    bool array_full = true;
    for (int i = 0; i < MAX_BOOT_FILES; i++) {
        if (!bootFiles[i].enabled) {
            array_full = false;
            break;
        }
    }
    if (array_full) {
        printf("Error: Maximum number of bootable files reached\n");
        return;
    }
    
    // Add the new bootable file to the array
    for (int i = 0; i < MAX_BOOT_FILES; i++) {
        if (!bootFiles[i].enabled) {
            strcpy(bootFiles[i].path, path);
            bootFiles[i].enabled = true;
            printf("Bootable file added successfully\n");
            break;
        }
    }
}

// Define a function to remove a bootable file from the array
void remove_boot_file() {
    // Get the index of the file to remove from the user
    int index = -1;
    bool valid_index = false;
    while (!valid_index) {
        printf("Enter the index of the file to remove: ");
        scanf("%d", &index);
        getchar(); // consume newline character
        if (index >= 0 && index < MAX_BOOT_FILES && bootFiles[index].enabled) {
            valid_index = true;
        } else {
            printf("Error: Invalid index or file not enabled\n");
        }
    }
    
    // Disable the specified bootable file
    bootFiles[index].enabled = false;
    printf("Bootable file removed successfully\n");
}

// Define a function to enable/disable a bootable file in the array
void enable_disable_boot_file() {
    // Get the index of the file to enable/disable from the user
    int index = -1;
    bool valid_index = false;
    while (!valid_index) {
        printf("Enter the index of the file to enable/disable: ");
        scanf("%d", &index);
        getchar(); // consume newline character
        if (index >= 0 && index < MAX_BOOT_FILES && bootFiles[index].enabled) {
            valid_index = true;
        } else {
            printf("Error: Invalid index or file not enabled\n");
        }
    }
    
    // Toggle the enabled/disabled state of the specified bootable file
    bootFiles[index].enabled = !bootFiles[index].enabled;
    printf("Bootable file enabled/disabled successfully\n");
}

// Define a function to show the list of bootable files in the array
void show_boot_files() {
    printf("Index\tPath\t\t\t\t\tEnabled\n");
    for (int i = 0; i < MAX_BOOT_FILES; i++) {
        printf("%d\t%s\t", i, bootFiles[i].path);
        if (bootFiles[i].enabled) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

// Define a function to sort the array of bootable files by enabled state
void sort_boot_files() {
    // Initialize a new array with the sorted bootable files
    BootFile sortedFiles[MAX_BOOT_FILES];
    int sortedIndex = 0;
    
    // Add all enabled bootable files
    for (int i = 0; i < MAX_BOOT_FILES; i++) {
        if (bootFiles[i].enabled) {
            strcpy(sortedFiles[sortedIndex].path, bootFiles[i].path);
            sortedFiles[sortedIndex].enabled = true;
            sortedIndex++;
        }
    }
    // Add all disabled bootable files
    for (int i = 0; i < MAX_BOOT_FILES; i++) {
        if (!bootFiles[i].enabled) {
            strcpy(sortedFiles[sortedIndex].path, bootFiles[i].path);
            sortedFiles[sortedIndex].enabled = false;
            sortedIndex++;
        }
    }
    
    // Copy the sorted array back into the original array
    for (int i = 0; i < MAX_BOOT_FILES; i++) {
        bootFiles[i] = sortedFiles[i];
    }
    printf("Boot sequence optimized successfully\n");
}

int main() {
    // Initialize all bootable files to be disabled
    for (int i = 0; i < MAX_BOOT_FILES; i++) {
        bootFiles[i].enabled = false;
    }
    
    // Print the menu and get user input
    int choice = 0;
    while (choice != 6) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // consume newline character
        printf("\n");
        
        switch (choice) {
            case 1:
                add_boot_file();
                break;
            case 2:
                remove_boot_file();
                break;
            case 3:
                enable_disable_boot_file();
                break;
            case 4:
                show_boot_files();
                break;
            case 5:
                sort_boot_files();
                break;
            case 6:
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }
        printf("\n");
    }
    
    return 0;
}