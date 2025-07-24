//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

typedef struct {
    char ssid[32];
    char bssid[18];
} network_t;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int scan_networks(network_t *networks, int max_networks) {

    /* This function will scan for available
     * wireless networks and return their details
     * in the 'networks' array. The maximum number
     * of networks that can be returned is
     * 'max_networks'.
     */

    int num_networks = 0;
    FILE *fp;

    /* Scan for networks using the 'iwlist' command */
    fp = popen("iwlist wlan0 scan | grep -E 'ESSID|Address'", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute iwlist command.\n");
        return -1;
    }

    char line[512];
    char *token;
    while (fgets(line, sizeof(line), fp)) {
        /* Parse SSID */
        if (strstr(line, "ESSID:\"")) {
            token = strtok(line, "\"");
            token = strtok(NULL, "\"");
            if (strlen(token) > 32) {
                /* SSID is too long, ignore this network */
                continue;
            }
            strcpy(networks[num_networks].ssid, token);
            num_networks++;
        }
        /* Parse BSSID */
        if (strstr(line, "Address:")) {
            token = strtok(line, " ");
            token = strtok(NULL, " ");
            if (strlen(token) != 17) {
                /* Invalid BSSID, ignore this network */
                continue;
            }
            strcpy(networks[num_networks-1].bssid, token);
        }
        if (num_networks >= max_networks) {
            /* Maximum number of networks has been reached */
            break;
        }
    }

    pclose(fp);
    return num_networks;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int main() {

    printf("The Adventure of the C Wireless Network Scanner\n");

    network_t networks[10];
    int num_networks = scan_networks(networks, 10);

    if (num_networks < 0) {
        printf("Our investigation into the wireless networks has failed.\n");
        printf("Please check your wireless adapter settings and try again.\n");
        return -1;
    }

    printf("We have found %d wireless networks in the area:\n\n", num_networks);

    for (int i = 0; i < num_networks; i++) {
        printf("Network Name (SSID): %s\n", networks[i].ssid);
        printf("MAC Address (BSSID): %s\n\n", networks[i].bssid);
    }

    printf("Our investigation of the local wireless networks is complete.\n");

    return 0;

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/