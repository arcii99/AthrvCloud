//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_PACKET_SIZE 65535
#define MAX_LOG_ENTRIES 100

struct log_entry {
    int type;
    char timestamp[50];
    char source_ip[20];
    char msg[50];
};

int parse_packet(char *packet, int packet_len) {
    // perform packet analysis here
    return 0; // return 1 if intrusion detected, 0 otherwise
}

int log_entry(struct log_entry *log_entries, int *num_entries, int type, char *source_ip, char *msg) {
    if (*num_entries >= MAX_LOG_ENTRIES) {
        return -1; // log is full
    }
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    sprintf(log_entries[*num_entries].timestamp, "%d-%02d-%02d %02d:%02d:%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    strcpy(log_entries[*num_entries].source_ip, source_ip);
    log_entries[*num_entries].type = type;
    strcpy(log_entries[*num_entries].msg, msg);
    (*num_entries)++;
    return 0;
}

void print_log_entries(struct log_entry *log_entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %d %s\n", log_entries[i].timestamp, log_entries[i].source_ip, log_entries[i].type, log_entries[i].msg);
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("failed to create socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("failed to bind socket");
        return 1;
    }

    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (1) {
        char packet[MAX_PACKET_SIZE];
        int packet_len = recvfrom(sock, packet, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (packet_len < 0) {
            perror("failed to receive packet");
            return 1;
        }

        if (parse_packet(packet, packet_len)) {
            printf("intrusion detected, creating log entry\n");
            if (log_entry(log_entries, &num_entries, 1, "127.0.0.1", "intrusion detected") < 0) {
                printf("failed to create log entry, log is full\n");
            }
        }
    }

    print_log_entries(log_entries, num_entries);

    return 0;
}