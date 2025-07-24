//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LEN 4096
#define MAX_SSID_LENGTH 32

typedef struct{
    char essid[MAX_SSID_LENGTH]; // ESSID of the access point
    char bssid[18]; // BSSID of the access point in format "XX:XX:XX:XX:XX:XX"
    int channel; // channel number of the access point
    int rssi; // received signal strength indicator of the access point in dBm
} ScanResult;

int scan(ScanResult *results, int max_results)
{
    int sock;
    struct sockaddr_in sockaddr;
    char response[MAX_LEN];
    int len;
    const char *request = "SCAN";

    // create a UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("Error creating socket");
        return -1;
    }

    // set up the address structure
    memset(&sockaddr, 0, sizeof(struct sockaddr_in));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr("255.255.255.255");
    sockaddr.sin_port = htons(8888);

    // send the scan request
    if (sendto(sock, request, strlen(request), 0, (struct sockaddr *)&sockaddr, sizeof(struct sockaddr_in)) < 0)
    {
        perror("Error sending scan request");
        return -1;
    }

    // receive the scan results
    memset(response, 0, MAX_LEN);
    len = recv(sock, response, MAX_LEN, 0);
    if (len < 0)
    {
        perror("Error receiving scan results");
        return -1;
    }

    // parse the scan results
    int num_results = 0;
    char *line = strtok(response, "\n");
    while (line != NULL && num_results < max_results)
    {
        ScanResult *result = &results[num_results];
        if (sscanf(line, "%32[^,],%17[^,],%d,%d", result->essid, result->bssid, &result->channel, &result->rssi) == 4)
        {
            num_results++;
        }
        line = strtok(NULL, "\n");
    }

    // close the socket
    close(sock);

    return num_results;
}

int main()
{
    // scan for access points
    ScanResult results[10];
    int num_results = scan(results, 10);

    // print the results
    printf("Found %d access point(s):\n", num_results);
    for (int i = 0; i < num_results; i++)
    {
        printf("ESSID: %s\n", results[i].essid);
        printf("BSSID: %s\n", results[i].bssid);
        printf("Channel: %d\n", results[i].channel);
        printf("RSSI: %d dBm\n", results[i].rssi);
        printf("\n");
    }

    return 0;
}