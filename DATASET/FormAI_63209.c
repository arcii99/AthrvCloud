//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 20

struct wireless_network {
    char name[20];
    int signal_strength;
};

int main() {
    struct wireless_network networks[MAX_NETWORKS]; // array of networks
    int num_networks = 0; // number of networks found
    FILE *fp; // file pointer to read from the output of iwlist
    
    // run iwlist wlan0 scanning command and save its output to a file
    system("iwlist wlan0 scanning > wireless_scan.txt");
    
    // open the file to read from it
    fp = fopen("wireless_scan.txt", "r");
    
    // check if file open was successful
    if (fp == NULL) {
        printf("Error! Unable to open file.");
        exit(1);
    }
    
    char line[100]; // buffer to save each line read from the file
    char network_name[20]; // buffer to save network name from the line
    int signal_strength; // buffer to save signal strength from the line
    
    // read each line from the file
    while (fgets(line, 100, fp) != NULL) {
        // check if this line contains the name of a wireless network
        if (strstr(line, "ESSID:") != NULL) {
            sscanf(line, "          ESSID:\"%[^\"]\"", network_name); // extract network name
        }
        
        // check if this line contains the signal strength of a wireless network
        if (strstr(line, "Quality=") != NULL) {
            signal_strength = atoi(strstr(line, "Quality=") + 8); // extract signal strength
        }
        
        // if both network name and signal strength are extracted, add them to the array
        if (strlen(network_name) > 0 && signal_strength > 0) {
            strcpy(networks[num_networks].name, network_name);
            networks[num_networks].signal_strength = signal_strength;
            num_networks++;
            strcpy(network_name, "");
            signal_strength = -1;
        }
    }
    
    // close the file
    fclose(fp);
    
    // sort the networks array based on signal strength (in descending order)
    struct wireless_network temp;
    for (int i = 0; i < num_networks; i++) {
        for (int j = i+1; j < num_networks; j++) {
            if (networks[i].signal_strength < networks[j].signal_strength) {
                temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
    
    // print the top 10 networks with highest signal strength
    printf("Top 10 wireless networks with highest signal strength:\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < 10 && i < num_networks; i++) {
        printf("%d. %-20s %d/70\n", i+1, networks[i].name, networks[i].signal_strength);
    }
    
    return 0;
}