//FormAI DATASET v1.0 Category: System administration ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Declare variables
    char hostname[100];
    int is_root = 0;
    int num_users = 0;

    // Get hostname
    if (gethostname(hostname, 100) != 0) {
        perror("Error getting hostname");
        exit(1);
    }

    // Check if user is root
    if (getuid() == 0) {
        is_root = 1;
    }

    // Get number of users
    FILE *passwd_file = fopen("/etc/passwd", "r");
    if (passwd_file == NULL) {
        perror("Error opening password file");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), passwd_file) != NULL) {
        num_users++;
    }
    fclose(passwd_file);

    // Print system information
    printf("Hostname: %s\n", hostname);
    printf("Root access: %s\n", is_root ? "Yes" : "No");
    printf("Number of users: %d\n", num_users);

    // Reboot system (if user is root)
    if (is_root) {
        printf("Do you want to reboot the system? (y/n) ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            system("reboot");
        }
    }

    return 0;
}