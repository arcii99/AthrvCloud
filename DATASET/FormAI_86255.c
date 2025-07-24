//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char ping_command[100];
    char response[100];
    int response_time;

    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sprintf(ping_command, "ping -c 1 %s | awk '/time=/ {print $7}'", argv[1]);
    FILE *ping_pipe = popen(ping_command, "r");

    if (!ping_pipe) {
        printf("Error! Failed to execute ping command.\n");
        exit(EXIT_FAILURE);
    }

    fgets(response, 100, ping_pipe);
    pclose(ping_pipe);

    if (strlen(response) > 0) {
        response_time = atoi(response);
        printf("Ping response time: %d ms\n", response_time);
    } else {
        printf("Error! Host is not responsive.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}