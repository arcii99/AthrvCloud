//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = system("ls"); // List contents of current directory
    printf("The command returned %d\n", a);
    
    a = system("sudo apt-get update"); // Update package lists with root privileges
    printf("The command returned %d\n", a);
    
    a = system("sudo apt-get upgrade"); // Upgrade all packages with root privileges
    printf("The command returned %d\n", a);
    
    a = system("echo Hello World!"); // Print "Hello World!" to the terminal
    printf("The command returned %d\n", a);
    
    a = system("shutdown now"); // Shutdown the system immediately
    printf("The command returned %d\n", a);
    
    a = system("sudo reboot"); // Reboot the system with root privileges
    printf("The command returned %d\n", a);
    
    a = system("ping 8.8.8.8"); // Ping Google DNS server
    printf("The command returned %d\n", a);
    
    a = system("systemctl status ssh"); // Check status of SSH service
    printf("The command returned %d\n", a);
    
    a = system("uname -a"); // Print system information
    printf("The command returned %d\n", a);
    
    a = system("journalctl --since \"1 hour ago\""); // Show system logs from the past hour
    printf("The command returned %d\n", a);
    
    return 0;
}