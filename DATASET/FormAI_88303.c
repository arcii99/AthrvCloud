//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the Happy System Administration Program!\n");

    // Create a directory
    int dir_created = mkdir("happy_dir", 0777);
    if (dir_created == 0) {
        printf("Hooray! A new directory called happy_dir has been created!\n");
    } else {
        printf("Uh-oh, something went wrong and the directory was not created.\n");
        exit(1);
    }

    // Change the owner of the directory
    int owner_changed = chown("happy_dir", 1000, 1000);
    if (owner_changed == 0) {
        printf("Yay! The owner of the directory has been changed to user with UID 1000!\n");
    } else {
        printf("Oops, there was an error and the owner could not be changed.\n");
        exit(1);
    }

    // Create a file inside the directory
    FILE *fp = fopen("happy_dir/happy_file.txt", "w");
    if (fp != NULL) {
        printf("Happiness! A new file called happy_file.txt has been created inside the directory!\n");
    } else {
        printf("No happiness today, the file could not be created.\n");
        exit(1);
    }

    // Change the permissions of the file
    int permissions_changed = chmod("happy_dir/happy_file.txt", 0644);
    if (permissions_changed == 0) {
        printf("Joy! The file permissions have been changed to read and write for the owner and read only for others!\n");
    } else {
        printf("No joy for us, the file permissions could not be changed.\n");
        exit(1);
    }

    printf("Thank you for using the Happy System Administration Program. Have a nice day!\n");
    return 0;
}