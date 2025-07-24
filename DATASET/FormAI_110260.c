//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
// It was a dark and stormy night in the land of C code
// All throughout the system, a programmer unknowingly bestowed
// A weakness, a flaw, a way for hackers to infiltrate
// But little did they know, a detective was on their fate

// His name was Sherlock, a master of C intrusion detection
// He searched through the code with precision and perfection
// He knew that if something was amiss, he would find it
// And stop the hackers from causing any damage

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 256
#define MAX_IP_ADDR_LEN 16
#define MAX_DETECTED_IPS 10

typedef struct {
    char ip_address[MAX_IP_ADDR_LEN];
    int occurrences;
} DetectedIP;

DetectedIP detected_ips[MAX_DETECTED_IPS];
int num_detected_ips = 0;

void add_detected_ip(char* ip_address) {
    for (int i = 0; i < num_detected_ips; i++) {
        if (strcmp(detected_ips[i].ip_address, ip_address) == 0) {
            // Increment number of occurrences for existing IP address
            detected_ips[i].occurrences++;
            return;
        }
    }

    if (num_detected_ips < MAX_DETECTED_IPS) {
        // Add new IP address to list of detected IPs
        strcpy(detected_ips[num_detected_ips].ip_address, ip_address);
        detected_ips[num_detected_ips].occurrences = 1;
        num_detected_ips++;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file]\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file \"%s\"\n", argv[1]);
        return 1;
    }

    char line[MAX_STR_LEN];
    while (fgets(line, MAX_STR_LEN, fp)) {
        // Check if line contains suspicious IP address
        if (strstr(line, "192.168.0.") != NULL) {
            char* ip_address = strtok(line, " ");
            add_detected_ip(ip_address);
        }
    }

    fclose(fp);

    if (num_detected_ips > 0) {
        printf("Detected IP addresses:\n");
        for (int i = 0; i < num_detected_ips; i++) {
            printf("%s - Occurrences: %d\n", detected_ips[i].ip_address, detected_ips[i].occurrences);
        }
    } else {
        printf("No suspicious activity detected.\n");
    }

    return 0;
}