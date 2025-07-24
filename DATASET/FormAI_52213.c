//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>

#define MAX_SSID_LEN 32

// Function declarations
int scan_wireless_networks(int sockfd);
int parse_scan_results(char* scan_results_buffer, int buffer_len);

// Main function
int main(int argc, char **argv) {
    int sockfd;

    // Create a raw socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        return -1;
    }

    // Set the wireless interface name to scan
    char interface_name[] = "wlan0";

    // Configure the wireless scan request
    struct iwreq scan_request;
    memset(&scan_request, 0, sizeof(scan_request));
    strncpy(scan_request.ifr_name, interface_name, IFNAMSIZ);
    scan_request.u.data.pointer = NULL;
    scan_request.u.data.length = 0;
    scan_request.u.data.flags = 0;

    // Send the wireless scan request
    if (ioctl(sockfd, SIOCSIWSCAN, &scan_request) < 0) {
        perror("ioctl(SIOCSIWSCAN) failed");
        return -1;
    }

    // Wait for the scan to complete
    sleep(5);

    // Retrieve the scan results
    if (scan_wireless_networks(sockfd) < 0) {
        perror("failed to scan wireless networks");
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Function to scan for wireless networks
int scan_wireless_networks(int sockfd) {
    // Configure the scan results request
    struct iwreq scan_results_request;
    memset(&scan_results_request, 0, sizeof(scan_results_request));
    strncpy(scan_results_request.ifr_name, "wlan0", IFNAMSIZ);

    // Retrieve the scan results
    char scan_results_buffer[2048];
    scan_results_request.u.data.pointer = scan_results_buffer;
    scan_results_request.u.data.length = sizeof(scan_results_buffer);
    scan_results_request.u.data.flags = 0;
    if (ioctl(sockfd, SIOCGIWSCAN, &scan_results_request) < 0) {
        perror("ioctl(SIOCGIWSCAN) failed");
        return -1;
    }

    // Parse the scan results
    if (parse_scan_results(scan_results_buffer, scan_results_request.u.data.length) < 0) {
        perror("failed to parse scan results");
        return -1;
    }

    return 0;
}

// Function to parse the scan results
int parse_scan_results(char* scan_results_buffer, int buffer_len) {
    int count = 0;
    int i;
    char ssid[MAX_SSID_LEN + 1];

    // Loop through the scan results
    while (count < buffer_len) {
        // Retrieve the wireless network information
        struct iw_event* event = (struct iw_event*) &scan_results_buffer[count];
        if (event->cmd != SIOCGIWAP) {
            break;
        }

        struct iw_quality quality;
        memset(&quality, 0, sizeof(quality));
        struct sockaddr_in* addr;
        addr = (struct sockaddr_in*) event->u.ap_addr.sa_data;

        int ap_addr = ntohl(addr->sin_addr.s_addr);
        memcpy(&quality, event + 2, sizeof(quality));
        memcpy(ssid, event + sizeof(*event), event->len);
        ssid[event->len] = '\0';

        // Print the wireless network information
        printf("Wireless Network:\n");
        printf(" SSID: %s\n", ssid);
        printf(" BSSID: %02X:%02X:%02X:%02X:%02X:%02X\n",
                (ap_addr >> 24) & 0xFF, (ap_addr >> 16) & 0xFF, (ap_addr >> 8) & 0xFF,
                ap_addr & 0xFF, quality.qual, quality.level - 256);

        // Increment the count
        count += event->len + sizeof(struct iw_event);
    }

    return 0;
}