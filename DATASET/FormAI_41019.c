//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 500

typedef struct Device {
    char name[10];
    char ip_addr[20];
    char mac_addr[20];
    int conn_count;
    struct Connection* connections[MAX_CONNECTIONS];
} Device;

typedef struct Connection {
    char protocol[10];
    char src_ip[20];
    char dst_ip[20];
    int src_port;
    int dst_port;
    bool active;
} Connection;

int num_devices;
Device devices[MAX_DEVICES];

void add_device(char* name, char* ip_addr, char* mac_addr) {
    num_devices++;
    Device device;
    strcpy(device.name, name);
    strcpy(device.ip_addr, ip_addr);
    strcpy(device.mac_addr, mac_addr);
    device.conn_count = 0;
    devices[num_devices-1] = device;
}

void add_connection(char* device_name, char* protocol, char* src_ip, char* dst_ip, int src_port, int dst_port, bool active) {
    for (int i=0; i<num_devices; i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            Device* device = &devices[i];
            int conn_count = device->conn_count;
            Connection connection;
            strcpy(connection.protocol, protocol);
            strcpy(connection.src_ip, src_ip);
            strcpy(connection.dst_ip, dst_ip);
            connection.src_port = src_port;
            connection.dst_port = dst_port;
            connection.active = active;
            device->connections[conn_count] = &connection;
            device->conn_count++;
            break;
        }
    }
}

void print_device(Device device) {
    printf("Device Name: %s\n", device.name);
    printf("IP Address: %s\n", device.ip_addr);
    printf("MAC Address: %s\n", device.mac_addr);
    printf("Number of Connections: %d\n", device.conn_count);

    for (int i=0; i<device.conn_count; i++) {
        Connection conn = *(device.connections[i]);
        printf("\tConnection #%d\n", i+1);
        printf("\tProtocol: %s\n", conn.protocol);
        printf("\tSource IP: %s\n", conn.src_ip);
        printf("\tDestination IP: %s\n", conn.dst_ip);
        printf("\tSource Port: %d\n", conn.src_port);
        printf("\tDestination Port: %d\n", conn.dst_port);
        printf("\tActive?: %s\n\n", (conn.active) ? "yes" : "no");
    }
}

void print_all_devices() {
    for (int i=0; i<num_devices; i++) {
        printf("===============================\n");
        printf("Device #%d\n", i+1);
        print_device(devices[i]);
    }
}

int main() {
    add_device("Router A", "192.168.1.1", "F0:0C:04:A1:B9:72");
    add_device("Switch 1", "192.168.1.10", "E8:9A:8F:0A:B8:F1");
    add_device("Desktop A", "192.168.1.11", "F4:8F:C2:9E:CE:31");
    add_device("Laptop A", "192.168.1.12", "D0:2C:45:4B:E2:84");
    add_device("Server A", "192.168.1.13", "E0:DB:55:96:C2:3B");

    add_connection("Router A", "TCP", "192.168.1.1", "192.168.1.10", 22, 22, true);
    add_connection("Router A", "TCP", "192.168.1.1", "192.168.1.11", 80, 42069, true);
    add_connection("Switch 1", "UDP", "192.168.1.10", "192.168.1.12", 9000, 9000, false);
    add_connection("Switch 1", "TCP", "192.168.1.10", "192.168.1.13", 443, 443, true);
    add_connection("Desktop A", "TCP", "192.168.1.11", "192.168.1.1", 5000, 5000, true);
    add_connection("Desktop A", "TCP", "192.168.1.11", "192.168.1.10", 3269, 3269, true);
    add_connection("Laptop A", "UDP", "192.168.1.12", "192.168.1.13", 1234, 1234, false);
    add_connection("Server A", "UDP", "192.168.1.13", "192.168.1.1", 5678, 5678, true);

    print_all_devices();
    
    return 0;
}