//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Function to convert MAC address from binary to human readable format
void MacFormat(unsigned char *macAddr, char *macAddrStr)
{
    sprintf(macAddrStr, "%02X:%02X:%02X:%02X:%02X:%02X",
            macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
}

// Function to print the wireless network list
void PrintWirelessNetworks()
{
    FILE *pipe;
    char buffer[128];
    memset(buffer, 0, sizeof(buffer));

    // Run the system command to scan for wireless networks
    pipe = popen("sudo iw dev wlan0 scan | grep 'SSID\\|signal\\|Address'", "r");

    // Store the scanned networks in an array of structures
    struct Network {
        char ssid[32];
        unsigned char bssid[6];
        int signal;
    } networks[20];

    int networkCount = 0;
    int lastNetworkIndex = -1;

    while(fgets(buffer, sizeof(buffer), pipe))
    {
        char *token = strtok(buffer, "\n");
        if(strncmp(token, "Address: ", 9) == 0)
        {
            token += 9;
            unsigned char macAddr[6];
            sscanf(token, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &macAddr[0], &macAddr[1], &macAddr[2], &macAddr[3], &macAddr[4], &macAddr[5]);
            for(int i = 0; i <= lastNetworkIndex; i++)
            {
                if(memcmp(macAddr, networks[i].bssid, 6) == 0)
                {
                    networkCount--;
                    break;
                }
            }
            if(networkCount == 20)
            {
                break;
            }
            lastNetworkIndex++;
            memcpy(networks[lastNetworkIndex].bssid, macAddr, 6);
        }
        else if(strncmp(token, "SSID: ", 6) == 0)
        {
            token += 6;
            snprintf(networks[lastNetworkIndex].ssid, sizeof(networks[lastNetworkIndex].ssid), "%s", token);
        }
        else if(strncmp(token, "signal: ", 8) == 0)
        {
            token += 8;
            networks[lastNetworkIndex].signal = atoi(token);
            networkCount++;
        }
    }

    // Print the scanned networks with their properties
    printf("+-------+--------------------------------------+---------+\n");
    printf("| Index | SSID                                 | Signal  |\n");
    printf("+-------+--------------------------------------+---------+\n");
    for(int i = 0; i <= lastNetworkIndex; i++)
    {
        char macStr[18];
        MacFormat(networks[i].bssid, macStr);
        printf("| %2d    | %-36.36s  | %-7d |\n", i+1, networks[i].ssid, networks[i].signal);
    }
    printf("+-------+--------------------------------------+---------+\n");
}

int main()
{
    // Create a socket to obtain the MAC address of the wireless interface
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct ifreq ifr;
    strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ - 1);
    ioctl(sock, SIOCGIFHWADDR, &ifr);
    close(sock);
    
    // Print the MAC address of the wireless interface
    char macAddrStr[18];
    MacFormat((unsigned char *)ifr.ifr_hwaddr.sa_data, macAddrStr);
    printf("Wireless Interface MAC Address: %s\n", macAddrStr);

    // Scan for wireless networks and print the list
    printf("\nScanning for wireless networks...\n");
    PrintWirelessNetworks();

    return 0;
}