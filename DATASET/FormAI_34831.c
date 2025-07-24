//FormAI DATASET v1.0 Category: System boot optimizer ; Style: realistic
#include <stdio.h>

int main() {
    printf("Welcome to C System Boot Optimizer!\n");

    // disable unnecessary services
    system("systemctl disable bluetooth");
    system("systemctl disable cups");
    system("systemctl disable avahi-daemon");

    // remove unnecessary packages
    system("apt-get remove libreoffice*");
    system("apt-get remove thunderbird");
    system("apt-get remove gnome-games");

    // set kernel parameters
    system("echo 'vm.swappiness=10' >> /etc/sysctl.conf");
    system("echo 'net.core.somaxconn=1024' >> /etc/sysctl.conf");
    system("echo 'fs.file-max=2097152' >> /etc/sysctl.conf");

    printf("Boot optimization completed successfully!\n");

    return 0;
}