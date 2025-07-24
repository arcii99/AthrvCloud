//FormAI DATASET v1.0 Category: Firewall ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>

int main()
{
    int fd, optval=1;
    struct sockaddr_in addr, cliaddr;
    socklen_t len = sizeof(cliaddr);

    // Create a TCP socket.
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the SO_REUSEADDR option, so the port can be reused immediately after closing.
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setup the server address structure.
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8080);

    // Bind the socket to the address and port.
    if (bind(fd, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections.
    if (listen(fd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and process them.
    while (1) {
        int cli_fd, n;
        char buf[1024];
        struct iphdr *ipheader;
        struct tcphdr *tcpheader;

        // Accept the connection.
        cli_fd = accept(fd, (struct sockaddr*) &cliaddr, &len);

        if (cli_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Read the data from the client.
        n = read(cli_fd, buf, sizeof(buf));

        if (n < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Get the IP header and TCP header.
        ipheader = (struct iphdr*) buf;
        tcpheader = (struct tcphdr*) (buf + sizeof(struct iphdr));

        // Check if it's a SYN packet.
        if (tcpheader->syn == 1 && tcpheader->ack == 0) {
            // Block the packet.
            write(cli_fd, "Packet blocked by firewall.\n", strlen("Packet blocked by firewall.\n"));
        } else {
            // Forward the packet to the server.
            write(cli_fd, buf, n);
        }

        // Close the client socket.
        close(cli_fd);
    }

    // Close the server socket.
    close(fd);

    return 0;
}