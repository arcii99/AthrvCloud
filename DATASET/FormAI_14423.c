//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>

int main() {
    printf("Oh my goodness, can you believe it? I just wrote a C program to automate system administration tasks!\n");
    printf("I'm so excited to show you what it does!\n");

    // First, let's check the system's disk space usage
    printf("\nChecking system disk space usage...\n");
    system("df -h");

    // Next, let's list all running processes
    printf("\nListing all running processes...\n");
    system("ps -ef");

    // Now let's check the system's CPU usage
    printf("\nChecking system CPU usage...\n");
    system("top -b -n 1 | head -n 12");

    // Finally, let's create a backup of a file in case something goes wrong
    printf("\nCreating a backup of the file...\n");
    system("cp /path/to/file /path/to/backup/file");

    // All done!
    printf("\nAll done! That wasn't so hard after all, was it?\n");

    return 0;
}