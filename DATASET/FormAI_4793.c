//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
// C Network Topology Mapper Example Program

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// a function to print an error message and exit
void error(char *msg){
    printf("Error: %s\n", msg);
    exit(1);
}

// a function to read addresses from a file
void read_file(char *fname, char **addresses){
    FILE *f = fopen(fname, "r");
    if (f == NULL)
        error("Could not open file");

    int i = 0;
    char line[100];
    while (fgets(line, sizeof(line), f) != NULL){
        strtok(line, "\n");
        addresses[i] = (char*)malloc(strlen(line)*sizeof(char));
        strcpy(addresses[i], line);
        i++;
    }

    fclose(f);
}

// a function to find the IP address of a host
void find_ip_addr(char *host, char *ip_addr){
    char command[100];
    sprintf(command, "nslookup %s | grep 'Address:' | tail -1 | awk '{print $2}'", host);
    FILE *f = popen(command, "r");
    if (f == NULL)
        error("Could not execute command");

    fgets(ip_addr, 20, f);
    strtok(ip_addr, "\n");
    pclose(f);
}

// a function to ping a host and determine if it is reachable
int ping_host(char *ip_addr){
    char command[100];
    sprintf(command, "ping -c 1 %s >/dev/null", ip_addr);
    return !system(command);
}

// a function to map the network topology
void map_topology(char **addresses, int num_addresses){
    int i, j;
    char ip_addr[20];

    printf("Starting Network Topology Mapping...\n\n");

    for (i = 0; i < num_addresses; i++){
        find_ip_addr(addresses[i], ip_addr);
        printf("Mapping connections for host %s (%s):\n", addresses[i], ip_addr);
        for (j = 0; j < num_addresses; j++){
            if (i != j){
                char tested_ip_addr[20];
                find_ip_addr(addresses[j], tested_ip_addr);
                if (ping_host(tested_ip_addr)){
                    printf("    %s is connected to %s\n", ip_addr, tested_ip_addr);
                }
            }
        }
        printf("\n");
    }
}

int main(){
    char *addresses[5] = {"google.com", "facebook.com", "apple.com", "microsoft.com", "amazon.com"};

    map_topology(addresses, 5);

    return 0;
}