//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <string.h>

int firewall(char *ip, int port);

int main() {
    char ip[16];
    int port;
    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter Port Number: ");
    scanf("%d", &port);
    if(firewall(ip, port)) {
        printf("Access Granted.\n");
    } else {
        printf("Access Denied.\n");
    }
    return 0;
}

int firewall(char *ip, int port) {
    if(strcmp(ip, "127.0.0.1") == 0) {
        if(port == 80 || port == 443) {
            return 1;
        }
    } else if(strcmp(ip, "192.168.0.1") == 0) {
        if(port == 22 || port == 5900) {
            return 1;
        }
    } else if(strcmp(ip, "10.0.0.1") == 0) {
        if(port == 3389 || port == 5901) {
            return 1;
        }
    }
    char answer;
    printf("Do you want to allow access to %s:%d? (y/n):", ip, port);
    scanf(" %c", &answer);
    if(answer == 'y' || answer == 'Y') {
        firewall(ip, port);
        return 1;
    }
    return 0;
}