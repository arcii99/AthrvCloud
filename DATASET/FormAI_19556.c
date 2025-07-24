//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include<stdio.h>

int main() {
    printf("Welcome to the Happy System Administration Example Program!\n");
    printf("So, what do you want to do today? Let's get started!\n");
    
    // Getting the current directory
    char pwd[100];
    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        printf("Current directory: %s\n", pwd);
    } else {
        printf("Failed to get current directory!\n");
    }
    
    // Creating a new directory
    char new_dir_name[50];
    printf("What should we name the new directory? ");
    scanf("%s", new_dir_name);
    if (mkdir(new_dir_name, 0777) == -1) {
        printf("Failed to create directory.\n");
    } else {
        printf("Directory '%s' created successfully!\n", new_dir_name);
    }
    
    // Running a system command
    char command[100];
    printf("Let's execute a system command! What's your favorite Linux command? ");
    scanf("%s", command);
    int ret = system(command);
    if (ret != 0) {
        printf("Sorry, failed to execute command!\n");
    } else {
        printf("Yay! Command executed successfully!\n");
    }
    
    // Removing the new directory
    if (rmdir(new_dir_name) == -1) {
        printf("Failed to remove directory!");
    } else {
        printf("Directory '%s' removed successfully!\n", new_dir_name);
    }
    
    printf("Thanks for using the Happy System Administration Example Program! Have a nice day!\n");
    return 0;
}