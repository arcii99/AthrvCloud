//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <linux/wireless.h>

#define MAX_SSID_LEN 32  /* Maximum length of an SSID string */
#define MAX_SCAN_RESULT_LEN 256 /* Maximum number of scan results to store */

/* Struct to hold information about a single Wi-Fi access point */
typedef struct ap_info {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} ap_info;

/* Global array to hold scan results */
ap_info scan_results[MAX_SCAN_RESULT_LEN];
int scan_result_count = 0;

/* Handler function for SIGINT signal, called on program termination */
void sigint_handler(int sig) {
    printf("\nWi-Fi analyzer stopping...\n");
    exit(0);
}

/* Function to scan for available Wi-Fi networks */
void scan_wifi() {
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0); /* Create UDP socket */
    struct ifreq ifr; /* Structure to specify wireless interface */
    struct iwreq iw; /* Structure to send wireless commands to interface */
    char *interface_name = "wlp2s0"; /* Name of wireless interface */
    int max_scan_results = MAX_SCAN_RESULT_LEN * sizeof(struct iw_event); /* Maximum size of scan results buffer */
    int scan_result_size; /* Actual size of scan results buffer */
    char scan_result_buffer[max_scan_results]; /* Buffer to hold scan results */
    int scan_result_index = 0; /* Starting index in scan result buffer */
    int i; /* Iterator variable */
    struct iw_event *event; /* Pointer to current event in scan result buffer */
    ap_info *ap; /* Pointer to current access point in global scan_results array */

    if (sock_fd == -1) {
        perror("socket error");
        exit(1);
    }

    /* Specify the wireless interface */
    strncpy(ifr.ifr_name, interface_name, IFNAMSIZ);

    /* Send SIOCSIWSCAN ioctl to wireless interface to trigger scan */
    memset(&iw, 0, sizeof(iw));
    iw.u.data.pointer = NULL;
    iw.u.data.flags = 0;
    ioctl(sock_fd, SIOCSIWSCAN, &iw);

    /* Receive scan results into buffer */
    memset(scan_result_buffer, 0, max_scan_results);
    scan_result_size = recv(sock_fd, scan_result_buffer, max_scan_results, 0);

    /* Loop through scan result buffer and extract access point information */
    event = (struct iw_event *)scan_result_buffer;
    while ((char *)event < scan_result_buffer + scan_result_size) {
        /* Check for scan result event */
        if (event->cmd == SIOCGIWSCAN) {
            /* Loop through scan result data and extract access point information */
            for (i = 0; i < event->u.data.length; ) {
                struct iw_event *evt = (struct iw_event *)((char *)event + i);
                if (evt->cmd == IWEVQUAL) {
                    if (evt->u.qual.level > -100 && evt->u.qual.level < 0) {
                        /* Add access point information to global array */
                        ap = &scan_results[scan_result_count++];
                        strncpy(ap->ssid, iw.u.essid.pointer, iw.u.essid.length);
                        ap->ssid[iw.u.essid.length] = '\0';
                        ap->signal_strength = evt->u.qual.level;
                    }
                }
                i += evt->len;
            }
        }
        event = (struct iw_event *)((char *)event + event->len);
    }

    /* Close socket */
    close(sock_fd);
}

/* Function to display available Wi-Fi networks and their signal strengths */
void display_results() {
    int i; /* Iterator variable */
    ap_info *ap; /* Pointer to current access point in global scan_results array */

    if (scan_result_count == 0) {
        printf("No Wi-Fi networks found.\n");
        return;
    }

    printf("Found %d Wi-Fi networks:\n", scan_result_count);
    printf("%-32s %-6s\n", "SSID", "Signal");
    printf("-------------------------------- ------------\n");
    for (i = 0; i < scan_result_count; i++) {
        ap = &scan_results[i];
        printf("%-32s %-6d\n", ap->ssid, ap->signal_strength);
    }
}

int main() {
    struct sigaction sa; /* Struct to specify signal handler */
    struct timeval tv; /* Struct to specify wait time for scan interval */
    int scan_interval = 5; /* Time between scans in seconds */

    /* Specify signal handler for SIGINT (Ctrl+C) signal */
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        /* Scan for Wi-Fi networks */
        scan_wifi();

        /* Display results of scan */
        display_results();

        /* Wait for scan interval */
        tv.tv_sec = scan_interval;
        tv.tv_usec = 0;
        select(0, NULL, NULL, NULL, &tv);
    }

    return 0;
}