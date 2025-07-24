//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Define constants
#define MAX_PORTS 100
#define MAX_DEVICES 100
#define MAX_NEIGHBORS 10
#define BUFFER_SIZE 1024

// Define data structures
typedef struct Port {
    int port_number;
    char ip_address[INET_ADDRSTRLEN];
} Port;

typedef struct Device {
    char name[IF_NAMESIZE];
    Port ports[MAX_PORTS];
    int num_ports;
} Device;

typedef struct Neighbor {
    char device_name[IF_NAMESIZE];
    int port_number;
    int distance;
} Neighbor;

typedef struct Graph {
    Device devices[MAX_DEVICES];
    int num_devices;
    Neighbor neighbors[MAX_DEVICES][MAX_NEIGHBORS];
    int num_neighbors[MAX_DEVICES];
} Graph;

// Function prototypes
void get_devices(Graph *g);
void get_neighbors(Graph *g);
void print_topology(Graph *g);

int main() {
    Graph g;
    
    // Get devices and neighbors in the network
    get_devices(&g);
    get_neighbors(&g);
    
    // Print the network topology
    print_topology(&g);
    
    return 0;
}

/* get_devices: populates the Device array in the given Graph with all the devices in the network */
void get_devices(Graph *g) {
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];
    Device d;
    
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    
    // Loop through all network interfaces
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }
        
        family = ifa->ifa_addr->sa_family;
        
        // Only consider interfaces of type AF_INET (IPv4)
        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), 
                            host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
            
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }
            
            // Add new device to the Graph
            strcpy(d.name, ifa->ifa_name);
            strcpy(d.ports[0].ip_address, host);
            d.ports[0].port_number = if_nametoindex(ifa->ifa_name);
            d.num_ports = 1;
            
            g->devices[g->num_devices] = d;
            g->num_devices++;
        }
    }
    
    freeifaddrs(ifaddr);
}

/* get_neighbors: populates the Neighbor array in the given Graph with all the neighbors of each device in the network */
void get_neighbors(Graph *g) {
    char buf[BUFFER_SIZE];
    char cmd[BUFFER_SIZE];
    FILE *fp;
    int i, j, k, num_lines;
    char device_name[IF_NAMESIZE], neighbor_name[IF_NAMESIZE], neighbor_ip[INET_ADDRSTRLEN];
    int distance;
    
    for (i = 0; i < g->num_devices; i++) {
        // Find neighbors for each device
        
        // First, get the IP address of each of the device's ports
        for (j = 0; j < g->devices[i].num_ports; j++) {
            strcpy(cmd, "ip addr show dev ");
            strcat(cmd, g->devices[i].name);
            strcat(cmd, " | grep -w \"inet\" | awk '{print $2}' | cut -d'/' -f1");
            
            fp = popen(cmd, "r");
            fgets(buf, BUFFER_SIZE, fp);
            strtok(buf, "\n");
            strcpy(g->devices[i].ports[j].ip_address, buf);
            pclose(fp);
        }
        
        // Then, ping all possible IPs in the subnet to find neighbors
        for (j = 0; j < g->devices[i].num_ports; j++) {
            strcpy(device_name, g->devices[i].name);
            
            // Extract the device's IP address and subnet mask
            char *ip_addr = strtok(g->devices[i].ports[j].ip_address, ".");
            char subnet_mask[INET_ADDRSTRLEN];
            sprintf(subnet_mask, "%s.%s.%s.255", ip_addr, strtok(NULL, "."), strtok(NULL, "."));
            
            k = 0;
            strcpy(cmd, "nmap -sn ");
            strcat(cmd, subnet_mask);
            strcat(cmd, " | grep -B1 \"is up\" | awk '/[0-9]\\./ {print $NF}'");

            fp = popen(cmd, "r");
            
            // Parse the output of the nmap command to get neighboring devices
            while (fgets(buf, BUFFER_SIZE, fp) != NULL) {
                strtok(buf, "\n");
                
                // Ignore the device's own IP address
                if (strcmp(buf, g->devices[i].ports[j].ip_address) == 0) {
                    continue;
                }
                
                // Check if the IP address belongs to a neighbor
                for (num_lines = 0; num_lines < k; num_lines++) {
                    if (strcmp(g->neighbors[i][num_lines].device_name, device_name) == 0 &&
                        strcmp(g->neighbors[i][num_lines].device_name, buf) != 0) {
                        continue;
                    }
                }
                
                // Get the device name and distance to neighbor
                strcpy(cmd, "traceroute -I ");
                strcat(cmd, buf);
                strcat(cmd, " | awk '/^ 2 / {print $2}'");
                fp = popen(cmd, "r");
                fgets(neighbor_ip, INET_ADDRSTRLEN, fp);
                strtok(neighbor_ip, "\n");
                pclose(fp);
                
                strcpy(cmd, "traceroute -I ");
                strcat(cmd, neighbor_ip);
                strcat(cmd, " | awk '/^ 3 / {for(i=2;i<=NF;i++){if(match($i,/[a-zA-Z0-9\\-]+\\.[a-zA-Z]{2,}/)){print $i}}}'");
                fp = popen(cmd, "r");
                fgets(neighbor_name, IF_NAMESIZE, fp);
                strtok(neighbor_name, "\n");
                pclose(fp);
                distance = 1;
                
                // Add neighbor to the Graph
                strcpy(g->neighbors[i][k].device_name, neighbor_name);
                g->neighbors[i][k].distance = distance;
                g->neighbors[i][k].port_number = j + 1;
                k++;
            }
            
            pclose(fp);
        }
        
        g->num_neighbors[i] = k;
    }
}

/* print_topology: prints the topology of the network using the information in the given Graph */
void print_topology(Graph *g) {
    int i, j, k, device_index, neighbor_index;
    char device_name[IF_NAMESIZE];
    
    printf("Network Topology:\n");
    for (i = 0; i < g->num_devices; i++) {
        strcpy(device_name, g->devices[i].name);
        device_index = -1;
        
        // Find the index of the device in the Graph
        for (j = 0; j < g->num_devices; j++) {
            if (strcmp(g->devices[j].name, device_name) == 0) {
                device_index = j;
                break;
            }
        }
        
        // Print the device and its neighbors
        printf("%s:", device_name);
        for (k = 0; k < g->num_neighbors[device_index]; k++) {
            neighbor_index = -1;
            
            // Find the index of the neighbor device in the Graph
            for (j = 0; j < g->num_devices; j++) {
                if (strcmp(g->devices[j].name, g->neighbors[device_index][k].device_name) == 0) {
                    neighbor_index = j;
                    break;
                }
            }
            
            printf(" %s(%d)", g->neighbors[device_index][k].device_name, g->neighbors[device_index][k].distance);
        }
        printf("\n");
    }
}