//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>

void welcome_banner() {
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*           Welcome to Sys Admin           *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");
    printf("\n");
}

void restart_server() {
    char cmd[50] = "sudo reboot";
    printf("Are you sure you want to restart the server? (y/n)\n");
    char c = getchar();
    if (c == 'y') {
        printf("Countdown to server restart...\n");
        for (int i = 10; i >= 1; i--) {
            printf("%d\n", i);
            sleep(1);
        }
        printf("Restarting server...\n");
        system(cmd);
    } else {
        printf("Restart aborted. Whew, that was close!\n");
    }
}

void ban_users() {
    printf("Enter the IP address of the user you wish to ban:\n");
    char ip[16];
    scanf("%s", ip);
    printf("How long do you want to ban this user? (in seconds)\n");
    int ban_time;
    scanf("%d", &ban_time);
    printf("Banning IP address %s for %d seconds...\n", ip, ban_time);
    char cmd[100];
    sprintf(cmd, "iptables -A INPUT -s %s -j DROP && sleep %d && iptables -D INPUT -s %s -j DROP", ip, ban_time, ip);
    system(cmd);
}

void optimize_disk_space() {
    printf("Warning: running this operation will delete all temporary files. Are you sure you want to proceed? (y/n)\n");
    char c = getchar();
    if (c == 'y') {
        printf("Compressing all log files...\n");
        system("cd /var/log && tar -czf logs.tar.gz *.log && rm *.log");
        printf("Deleting all temporary files...\n");
        system("rm -rf /tmp/*");
        printf("Optimization complete! Enjoy all that extra disk space.\n");
    } else {
        printf("Optimization aborted. Safety first!\n");
    }
}

int main() {
    welcome_banner();
    printf("What would you like to do today?\n");
    printf("1. Restart server\n");
    printf("2. Ban users\n");
    printf("3. Optimize disk space\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            restart_server();
            break;
        case 2:
            ban_users();
            break;
        case 3:
            optimize_disk_space();
            break;
        default:
            printf("Invalid choice. Please try again later.\n");
            break;
    }
    return 0;
}