//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <netdb.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_AP_COUNT 10
#define SIGNAL_THRESHOLD 70

struct AccessPoint {
    char ssid[20];
    int signal_strength;
};

struct AccessPoint ap_list[MAX_AP_COUNT];
int ap_count = 0;

void *analyze_signal_strength(void *arg) {
    int ap_index = *((int *) arg);
    struct AccessPoint *ap = &ap_list[ap_index];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct hostent *server = gethostbyname(ap->ssid);
    if (server == NULL) {
        perror("Error resolving host");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    int signal_strength = 0;
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", ap->ssid);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending request");
        exit(1);
    }

    while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
        // count number of bytes received as signal strength
        signal_strength += strlen(buffer);
    }

    close(sock);

    ap->signal_strength = signal_strength;
    printf("%s signal strength: %d\n", ap->ssid, ap->signal_strength);

    pthread_exit(NULL);
}

int main() {
    printf("Scanning for access points...\n");

    // simulate scanning for access points
    sleep(1);

    // populate access point list with random data
    ap_count = 5;
    strcpy(ap_list[0].ssid, "Wifi1");
    ap_list[0].signal_strength = 50;
    strcpy(ap_list[1].ssid, "Wifi2");
    ap_list[1].signal_strength = 85;
    strcpy(ap_list[2].ssid, "Wifi3");
    ap_list[2].signal_strength = 60;
    strcpy(ap_list[3].ssid, "Wifi4");
    ap_list[3].signal_strength = 70;
    strcpy(ap_list[4].ssid, "Wifi5");
    ap_list[4].signal_strength = 75;

    // print access point list
    printf("Available access points:\n");
    for (int i = 0; i < ap_count; i++) {
        printf("%s\n", ap_list[i].ssid);
    }
    printf("\n");

    // create threads to analyze signal strengths
    pthread_t threads[MAX_AP_COUNT];
    int thread_args[MAX_AP_COUNT];
    for (int i = 0; i < ap_count; i++) {
        thread_args[i] = i;
        int rc = pthread_create(&threads[i], NULL, analyze_signal_strength, (void *) &thread_args[i]);
        if (rc) {
            perror("Error creating thread");
            exit(1);
        }
    }

    // wait for threads to finish
    for (int i = 0; i < ap_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // print signal strengths of access points that exceed threshold
    printf("Access points with signal strength above %d:\n", SIGNAL_THRESHOLD);
    for (int i = 0; i < ap_count; i++) {
        if (ap_list[i].signal_strength > SIGNAL_THRESHOLD) {
            printf("%s: %d\n", ap_list[i].ssid, ap_list[i].signal_strength);
        }
    }

    return 0;
}