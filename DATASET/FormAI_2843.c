//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h> // For standard input/output functions
#include <stdlib.h> // For exit() function
#include <netdb.h> // For gethostbyname() function
#include <netinet/in.h> // For sockaddr_in structure
#include <sys/socket.h> // For socket() function

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        fprintf(stderr, "Error: Could not resolve host %s\n", hostname);
        exit(1);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr = *((struct in_addr *)host->h_addr);
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Could not connect to host %s\n", hostname);
        exit(1);
    }
    printf("Connected to host %s\n", hostname);
    /* The following code can be used to measure Wi-Fi signal strength */
    char result[256];
    if (system("airport -I | awk '/agrCtlRSSI/{print $NF}' > tmp.txt") == -1) {
        fprintf(stderr, "Error: Could not run airport command\n");
        exit(1);
    }
    FILE *fp;
    fp = fopen("tmp.txt", "r");
    fgets(result, 256, fp);
    fclose(fp);
    system("rm tmp.txt");
    printf("Wi-Fi signal strength: %s dBm\n", result);
    close(socket_fd);
    return 0;
}