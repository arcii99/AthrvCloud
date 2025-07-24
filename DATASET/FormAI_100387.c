//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct networkTraffic {
    char srcIP[16];
    char destIP[16];
    int srcPort;
    int destPort;
    char protocol[4];
    char message[256];
};

void logAttack(struct networkTraffic traffic) {
    FILE *logFile;

    logFile = fopen("intrusion.log", "a");

    fprintf(logFile, "Intrusion detected:\n");
    fprintf(logFile, "Source IP: %s\n", traffic.srcIP);
    fprintf(logFile, "Destination IP: %s\n", traffic.destIP);
    fprintf(logFile, "Source Port: %d\n", traffic.srcPort);
    fprintf(logFile, "Destination Port: %d\n", traffic.destPort);
    fprintf(logFile, "Protocol: %s\n", traffic.protocol);
    fprintf(logFile, "Message: %s\n", traffic.message);

    fclose(logFile);
}

int main() {
    struct networkTraffic traffic1 = {"192.168.1.101", "52.12.134.55", 54321, 80, "TCP", "GET /index.html HTTP/1.1"};
    struct networkTraffic traffic2 = {"192.168.1.102", "22.33.44.55", 12345, 22, "SSH", "ssh2_msg_kexinit: invalid cookie"};
    struct networkTraffic traffic3 = {"192.168.1.103", "192.168.1.1", 65432, 53, "DNS", "IN A 192.168.1.103"};

    if (strcmp(traffic1.protocol, "TCP") == 0 && traffic1.destPort != 80) {
        logAttack(traffic1);
        printf("Intrusion detected. See 'intrusion.log' for details.\n");
    }

    if ((strcmp(traffic2.protocol, "SSH") == 0 || strcmp(traffic2.protocol, "Telnet") == 0) && strlen(traffic2.message) > 50) {
        logAttack(traffic2);
        printf("Intrusion detected. See 'intrusion.log' for details.\n");
    }

    if (strcmp(traffic3.protocol, "DNS") == 0 && (strstr(traffic3.message, "192.168.1.1") != NULL)) {
        logAttack(traffic3);
        printf("Intrusion detected. See 'intrusion.log' for details.\n");
    }

    return 0;
}