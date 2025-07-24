//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_DATA_SIZE 1024
#define MAX_DEVICES 20

typedef struct {
    char* name;
    char* mac_addr;
    int signal_strength;
} WiFiDevice;

void init_devices(WiFiDevice *devices[]) {
    for (int i = 0; i < MAX_DEVICES; i++) {
        devices[i] = calloc(1, sizeof(WiFiDevice));
        devices[i]->name = "";
        devices[i]->mac_addr = "";
        devices[i]->signal_strength = 0;
    }
}

void add_device(char* data, WiFiDevice *devices[]) {
    char *name = strtok(data, ",");
    char *mac_addr = strtok(NULL, ",");
    int signal_strength = atoi(strtok(NULL, ","));

    int i = 0;
    while (devices[i]->name != "" && i < MAX_DEVICES) i++;
    if (i == MAX_DEVICES) {
        printf("Max devices reached!");
        return;
    }

    devices[i]->name = name;
    devices[i]->mac_addr = mac_addr;
    devices[i]->signal_strength = signal_strength;
    printf("Device added: %s %s %d dBm\n", name, mac_addr, signal_strength);
}

void display_devices(WiFiDevice *devices[]) {
    printf("List of devices:\n");
    printf("| %-20s | %-20s | %-20s |\n", "Name", "MAC Address", "Signal Strength");
    printf("|----------------------|----------------------|----------------------|\n");

    for (int i = 0; i < MAX_DEVICES; i++) {
        if (devices[i]->name != "") {
            printf("| %-20s | %-20s | %-20d |\n", devices[i]->name, devices[i]->mac_addr, devices[i]->signal_strength);
        }
    }
}

void simulate_data(WiFiDevice *devices[]) {
    char* names[] = {"John", "Bob", "Alice", "Emma", "Lucas", "Olivia", "Ryan", "Liam", "Sophia", "Ethan"};
    char* mac_addrs[] = {"AA:BB:CC:DD:EE:FF", "00:11:22:33:44:55", "11:22:33:44:55:66", "22:33:44:55:66:77", "33:44:55:66:77:88", "44:55:66:77:88:99"};
    srand(time(NULL));

    for (int i = 0; i < MAX_DEVICES; i++) {
        int name_index = rand() % (sizeof(names)/sizeof(names[0]));
        int mac_addr_index = rand() % (sizeof(mac_addrs)/sizeof(mac_addrs[0]));
        int signal_strength = rand() % 60 - 100;

        char data[MAX_DATA_SIZE];
        sprintf(data, "%s,%s,%d", names[name_index], mac_addrs[mac_addr_index], signal_strength);
        add_device(data, devices);
    }
}

int main(int argc, char const *argv[]) {
    WiFiDevice *devices[MAX_DEVICES];
    init_devices(devices);

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))< 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Wi-Fi Signal Strength Analyzer is running...\n");

    simulate_data(devices);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[MAX_DATA_SIZE] = {0};
        read(new_socket, buffer, MAX_DATA_SIZE);

        if (buffer[0] == 'A') {
            display_devices(devices);
        } else if (buffer[0] == 'S') {
            add_device(&buffer[1], devices);
        } else if (buffer[0] == 'Q') {
            exit(0);
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}