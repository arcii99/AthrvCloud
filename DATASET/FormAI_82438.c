//FormAI DATASET v1.0 Category: System boot optimizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Welcome to C System Boot Optimizer!\n");
    
    // Disable unnecessary services
    system("systemctl disable bluetooth.service");
    system("systemctl disable cups.service");
    system("systemctl disable avahi-daemon.service");
    
    // Optimize the boot process
    system("systemd-analyze blame > temp.txt");
    FILE *file = fopen("temp.txt", "r");
    char line[256];
    int total_time = 0;
    while (fgets(line, sizeof(line), file)) {
        char *ptr = line;
        while (*ptr == ' ') {
            ptr++;
        }
        char *space = strchr(ptr, ' ');
        if (space != NULL) {
            char *time_str = space + 1;
            int time = atoi(time_str);
            total_time += time;
            if (time > 2000) {
                char service[strlen(ptr) + 1];
                strncpy(service, ptr, space - ptr);
                service[space - ptr] = '\0';
                printf("Disabling service: %s\n", service);
                char cmd[strlen(service) + 30];
                sprintf(cmd, "systemctl disable %s", service);
                system(cmd);
            }
        }
    }
    printf("Total boot time: %dms\n", total_time);
    fclose(file);
    remove("temp.txt");
    
    printf("Optimization complete. Press enter to exit.\n");
    getchar();
    return 0;
}