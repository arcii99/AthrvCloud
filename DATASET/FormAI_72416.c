//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    printf("Welcome to the Grateful System Administration program!\n");
    fflush(stdout);

    // get the current user's ID and username
    uid_t user_id = getuid();
    char* username = getlogin();

    printf("Current user ID: %d\n", user_id);
    printf("Current username: %s\n", username);
    fflush(stdout);

    // create a new file
    int fd = open("grateful_file.txt", O_CREAT | O_WRONLY, 0666);

    if(fd < 0)
    {
        perror("Error creating file");
        exit(1);
    }

    // write some data to the file
    char* message = "Thank you for using the Grateful System Administration program!\n";
    int len = strlen(message);
    ssize_t bytes_written = write(fd, message, len);

    if(bytes_written != len)
    {
        perror("Error writing to file");
        exit(1);
    }

    close(fd);

    printf("File created and data written successfully!\n");
    fflush(stdout);

    // reboot the system
    system("reboot");

    // program ends here because the system will reboot

    return 0;
}