//FormAI DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include <stdio.h>

// function to optimize system boot time
void optimize_boot_time() {
    // disable unnecessary services
    printf("Disabling unnecessary services...\n");
    system("systemctl disable bluetooth.service");
    system("systemctl disable cups.service");
    system("systemctl disable avahi-daemon.service");

    // remove unnecessary packages
    printf("Removing unnecessary packages...\n");
    system("apt-get remove libreoffice-common");
    system("apt-get remove thunderbird");
    system("apt-get remove gnome-mahjongg");

    // clean up systemd journal logs
    printf("Cleaning up systemd journal logs...\n");
    system("journalctl --vacuum-time=2d");

    // disable graphical login manager
    printf("Disabling graphical login manager...\n");
    system("systemctl disable lightdm.service");

    // optimize boot loader
    printf("Optimizing boot loader...\n");
    system("sed -i 's/GRUB_TIMEOUT=5/GRUB_TIMEOUT=1/g' /etc/default/grub");
    system("update-grub");

    printf("System boot optimized successfully!\n");
}

int main() {
    printf("Welcome to the System Boot Optimizer!\n");

    char choice;
    printf("Would you like to optimize your system boot time? (y/n): ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        optimize_boot_time();
    } else {
        printf("Okay, have a great day!\n");
    }

    return 0;
}