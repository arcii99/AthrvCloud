//FormAI DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main()
{
    printf("Welcome to the System Administration Program!\n");

    // Get user ID of current user
    uid_t user_id = getuid();

    // Get user name of current user
    struct passwd *pws;
    pws = getpwuid(user_id);
    char *user_name = pws->pw_name;

    // Check if user is root
    if(user_id != 0)
    {
        printf("Error: You need to be root to run this program!\n");
        return 1;
    }

    // Print system information
    printf("Hostname: ");
    system("hostname");
    printf("\n");

    printf("Operating System: ");
    system("lsb_release -d | cut -f2");
    printf("\n");

    // Print available disk space
    printf("Available disk space:\n");
    system("df -h");

    // Print logged in users
    printf("\nLogged in users:\n");
    system("who");

    // Print memory usage
    printf("\nMemory usage:\n");
    system("free -h");

    return 0;
}