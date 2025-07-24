//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<ifaddrs.h>
#include<netinet/in.h>
#include<math.h>

void getWifiStrength(char* interface) {
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        if ((strcmp(ifa->ifa_name, interface) == 0) && (ifa->ifa_addr->sa_family == AF_INET)) {
            s = getnameinfo(ifa->ifa_addr,
                    sizeof(struct sockaddr_in),
                    host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
        }
    }
    freeifaddrs(ifaddr);
    int signal_strength;
    char sys_command[256];
    sprintf(sys_command, "iwconfig %s | grep Signal | cut -d'=' -f3 | cut -d' ' -f1", interface);
    FILE* fp = popen(sys_command, "r");
    fscanf(fp, "%d", &signal_strength);
    pclose(fp);

    double signal_dbm = signal_strength - 100;
    double signal_mw = pow(10, signal_dbm / 10);
    printf("\n Signal Strength: %.2f mW\n", signal_mw);
}

int main() {
    char wifi_device[256];

    printf("Enter Wifi device name (e.g. wlan0) : ");
    scanf("%s", wifi_device);

    getWifiStrength(wifi_device);
    return 0;
}