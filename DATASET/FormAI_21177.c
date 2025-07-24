//FormAI DATASET v1.0 Category: System boot optimizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    printf("Starting System Boot Optimizer...\n");
    
    if(getuid() != 0) {
        printf("Error: You must run this program as root.\n");
        return 1;
    }
    
    printf("Checking for unneeded services...\n");
    system("systemctl list-unit-files --type=service --state=enabled > services.txt");
    FILE *fp = fopen("services.txt", "r");
    if(fp == NULL) {
        printf("Error: Failed to open services.txt\n");
        return 1;
    }
    char line[256];
    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, ".service") != NULL && strstr(line, "enabled") != NULL) {
            char *service_name = strtok(line, " ");
            printf("Disabling unneeded service: %s", service_name);
            char command[256] = {0};
            sprintf(command, "systemctl disable %s", service_name);
            system(command);
        }
    }
    fclose(fp);
    remove("services.txt");
    
    printf("Checking for unneeded startup applications...\n");
    system("ls /etc/xdg/autostart/ > startup-apps.txt");
    fp = fopen("startup-apps.txt", "r");
    if(fp == NULL) {
        printf("Error: Failed to open startup-apps.txt\n");
        return 1;
    }
    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, ".desktop") != NULL) {
            char *app_name = strtok(line, ".");
            printf("Disabling unneeded startup application: %s", app_name);
            char command[256] = {0};
            sprintf(command, "mv /etc/xdg/autostart/%s.disabled", line);
            system(command);
        }
    }
    fclose(fp);
    remove("startup-apps.txt");
    
    printf("Cleaning up packages...\n");
    system("apt-get autoclean");
    
    printf("Optimizing swap usage...\n");
    system("sysctl -w vm.swappiness=10 > /dev/null");
    
    printf("Optimizing network settings...\n");
    system("echo 1 > /proc/sys/net/ipv4/tcp_tw_reuse");
    system("echo 1 > /proc/sys/net/ipv4/tcp_tw_recycle");
    
    printf("System Boot Optimizer has finished.\n");
    
    return 0;
}