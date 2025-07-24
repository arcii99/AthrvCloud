//FormAI DATASET v1.0 Category: System boot optimizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// function to check if program is running with root privileges
bool is_root() {
    uid_t uid = getuid();
    return uid == 0;
}

// function to check if program exists
bool program_exists(char* program) {
    char command[100];
    sprintf(command, "which %s > /dev/null 2>&1", program);
    return system(command) == 0;
}

// main function
int main() {
    printf("Welcome to the C System Boot Optimizer!\n\n");

    // check if running with root privileges
    if (!is_root()) {
        printf("Please run this program as root.\n");
        return 1;
    }

    // check if required programs exist
    if (!program_exists("systemctl") || !program_exists("timedatectl")) {
        printf("Required programs systemctl and timedatectl not found. Please install them.\n");
        return 1;
    }

    // disable unneeded services at boot
    printf("Disabling unneeded services...\n");
    system("systemctl disable bluetooth.service > /dev/null 2>&1");
    system("systemctl disable cups.service > /dev/null 2>&1");
    system("systemctl disable ssh.service > /dev/null 2>&1");
    printf("Done.\n");

    // set timezone and enable NTP
    printf("Setting timezone and enabling NTP...\n");
    system("timedatectl set-timezone Asia/Kolkata > /dev/null 2>&1");
    system("timedatectl set-ntp true > /dev/null 2>&1");
    printf("Done.\n\n");

    printf("C System Boot Optimizer has finished optimizing your system. Enjoy the improved boot time!\n");
    return 0;
}