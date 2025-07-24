//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <net/if.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024
#define MAX_INTERFACE_LEN 64

int main(int argc, char **argv) {
    
    char* interface_name = "wlan0";
    char* ssid = "some_ssid";
    
    if (argc > 1) {
        interface_name = argv[1];
    }
    if (argc > 2) {
        ssid = argv[2];
    }
    
    char command[MAX_BUF_SIZE];
    memset(command, 0, MAX_BUF_SIZE);
    snprintf(command, sizeof(command), "iwlist %s scanning | grep '%s'", interface_name, ssid);
    
    char buffer[MAX_BUF_SIZE];
    FILE* pipe = popen(command, "r");
    if (pipe == NULL) {
        printf("Error while opening pipe\n");
        return -1;
    }

    printf("Scanning for '%s' networks on '%s'\n", ssid, interface_name);
    printf("------------------------------\n");

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s",buffer);
    }
    pclose(pipe);
    
    return 0;
}