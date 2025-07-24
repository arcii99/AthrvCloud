//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_MSG_LEN 256

void logMsg(char *msg) {
    printf("%s\n", msg);
}

void detectIntrusion(char *ip, char *msg) {
    char cmd[MAX_MSG_LEN];
    sprintf(cmd, "whois %s | grep -i 'country\\|region\\|city\\|isp\\|abuse\\|mnt-by'", ip);
    FILE *fp = popen(cmd, "r");
    char buf[MAX_MSG_LEN];
    char result[MAX_MSG_LEN] = "";
    while (fgets(buf, MAX_MSG_LEN, fp) != NULL) {
        strcat(result, buf);
    }
    pclose(fp);
    if (strlen(result) > 0) {
        char logMessage[MAX_MSG_LEN];
        sprintf(logMessage, "Detected Intrusion from %s. Details: %s", ip, result);
        logMsg(logMessage);
        exit(1);
    }
}

int main() {
    char ip[MAX_IP_LEN];
    char msg[MAX_MSG_LEN];

    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter Message: ");
    scanf("%s", msg);

    detectIntrusion(ip, msg);

    printf("Successful Message Send\n");
    return 0;
}