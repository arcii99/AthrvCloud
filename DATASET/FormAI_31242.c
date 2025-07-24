//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to scan for wireless networks
void scanWiFi() {
    char cmd[100];
    printf("Scanning for available wireless networks, Please wait...\n");
    // scan the networks and store the output in output file
    sprintf(cmd, "nmcli -f SSID,CHAN,BARS,RATE,SECURITY device wifi list > network_list.txt");
    system(cmd);
    // read the file and print the networks
    FILE* file = fopen("network_list.txt", "r");
    char line[256];
    int i = 1;
    while(fgets(line, sizeof(line), file)) {
        if(i == 1) {
            // print the table header
            printf("| %-30s | %-5s | %-5s | %-5s | %-15s |\n", "SSID", "CHAN", "BARS", "RATE", "SECURITY");
            printf("|------------------------------|-------|-------|-------|-----------------|\n");
        }else{
            // parse the line and print the details
            char* ssid = strtok(line, " ");
            char* chan = strtok(NULL, " ");
            char* bars = strtok(NULL, " ");
            char* rate = strtok(NULL, " ");
            char* security = strtok(NULL, " ");
            printf("| %-30s | %-5s | %-5s | %-5s | %-15s |\n", ssid, chan, bars, rate, security);
        }
        i++;
    }
    printf("\nTotal %d wireless networks found.\n", i-2);
    fclose(file);
}

int main() {
    char yes_no;
    printf("This program scans for available wireless networks. Do you want to continue? (y/n): ");
    scanf("%c", &yes_no);
    if(yes_no == 'y') {
        scanWiFi();
    }else{
        printf("Exiting...\n");
    }
    return 0;
}