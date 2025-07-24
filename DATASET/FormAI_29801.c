//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NETWORKS 100

// Structure to hold network info
struct network
{
    char ssid[32];
    char bssid[18];
    int channel;
    int rssi;

};

int main()
{
    struct network networks[MAX_NETWORKS];
    int num_networks = 0;

    // Linux wireless interface to scan networks 
    system("sudo iwlist wlan0 scan > /tmp/wifiscan.txt");

    // Open file containing network scan data 
    FILE *fp;
    fp = fopen("/tmp/wifiscan.txt", "r");

    if(fp == NULL)
    {
        printf("Error opening scan file: /tmp/wifiscan.txt\n");
        return 1;
    }

    // Read file line by line looking for network info
    char line[100];
    while(fgets(line, 100, fp) != NULL)
    {
        // Look for line that starts with "Cell"
        if(strncmp(line, "Cell", 4) == 0)
        {
            struct network net;

            // Ignore the first 5 lines of each network
            for(int i = 0 ; i < 5 ; i++)
            {
                fgets(line, 100, fp);   
            }

            // Get network SSID
            fgets(line, 100, fp);
            char *ptr = strchr(line, ':');
            ptr++;
            strcpy(net.ssid, ptr);
            net.ssid[strlen(net.ssid)-1] = '\0'; // Remove newline

            // Get network BSSID (MAC address)
            fgets(line, 100, fp);
            ptr = strchr(line, ':');
            ptr += 2;
            strcpy(net.bssid, ptr);
            net.bssid[strlen(net.bssid)-1] = '\0'; // Remove newline

            // Ignore next 4 lines
            for(int i = 0 ; i < 4 ; i++)
            {
                fgets(line, 100, fp);   
            }

            // Get network channel
            fgets(line, 100, fp);
            ptr = strchr(line, ':');
            ptr++;
            net.channel = atoi(ptr);

            // Ignore next 2 lines
            for(int i = 0 ; i < 2 ; i++)
            {
                fgets(line, 100, fp);   
            }

            // Get network signal strength (RSSI)
            fgets(line, 100, fp);
            ptr = strstr(line, "level=");
            ptr += 6;
            net.rssi = atoi(ptr);

            // Add network to array of networks
            networks[num_networks] = net;
            num_networks++;

            if(num_networks == MAX_NETWORKS) // Array full, exit loop
            {
                break;
            }
        }
    }

    fclose(fp);

    // Print out all the networks found
    printf("Wireless networks found:\n\n");
    for(int i = 0 ; i < num_networks ; i++)
    {
        printf("SSID:\t%s\n", networks[i].ssid);
        printf("BSSID:\t%s\n", networks[i].bssid);
        printf("Channel:\t%d\n", networks[i].channel);
        printf("RSSI:\t%d dBm\n", networks[i].rssi);
        printf("\n");
    }

    return 0;
}