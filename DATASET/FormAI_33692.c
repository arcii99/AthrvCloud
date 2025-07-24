//FormAI DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_PORTS 65535           // the maximum number of ports

// Print usage information
void usage(char *program) {
	printf("Usage: %s [options] <host>\n\n", program);
	printf("Options:\n");
	printf("  -h, --help\t\t\tDisplay this help message\n");
	printf("  -p, --ports <port number(s)>\tSpecify port number(s) to scan (comma-separated)\n");
	printf("  -s, --start <port number>\tSpecify the starting port number to scan\n");
	printf("  -e, --end <port number>\tSpecify the ending port number to scan\n\n");
}

// Get command line arguments
void get_args(int argc, char **argv, char *host, int *start_port, int *end_port) {
	int i, c;

	// Set default values
	*start_port = 1;
	*end_port = MAX_PORTS;

	// Parse command line arguments
	while ((c = getopt(argc, argv, "hp:s:e:")) != -1) {
		switch (c) {
			case 'h':
				usage(argv[0]);
				exit(EXIT_SUCCESS);
			case 'p':
				*start_port = strtol(optarg, &optarg, 10);
				if (*optarg == ',') {
					*end_port = strtol(optarg + 1, NULL, 10);
				} else {
					fprintf(stderr, "Error: invalid port range specified\n");
					usage(argv[0]);
					exit(EXIT_FAILURE);
				}
				break;
			case 's':
				*start_port = strtol(optarg, NULL, 10);
				break;
			case 'e':
				*end_port = strtol(optarg, NULL, 10);
				break;
			default:
				fprintf(stderr, "Error: invalid option specified\n");
				usage(argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	// Get host argument
	if (optind < argc) {
		strncpy(host, argv[optind], INET_ADDRSTRLEN);
	} else {
		fprintf(stderr, "Error: no host specified\n");
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}
}

// Scan a single port
void scan_port(int port, char *host) {
	// Create a TCP socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		perror("Error creating socket");
		exit(EXIT_FAILURE);
	}

	// Set socket options
	struct timeval timeout;
	timeout.tv_sec = 3;
	timeout.tv_usec = 0;

	int optval = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
		perror("Error setting socket options");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
		perror("Error setting socket options");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) == -1) {
		perror("Error setting socket options");
		exit(EXIT_FAILURE);
	}

	// Set up sockaddr_in structure
	struct sockaddr_in target;
	target.sin_family = AF_INET;
	target.sin_addr.s_addr = inet_addr(host);
	target.sin_port = htons(port);

	// Connect to target
	if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == -1) {
		if (errno == ECONNREFUSED) {
			printf("%d: Closed\n", port);
		} else {
			printf("%d: Filtered\n", port);
		}
	} else {
		printf("%d: Open\n", port);
	}

	// Close socket
	close(sock);
}

// Main function
int main(int argc, char **argv) {
	char host[INET_ADDRSTRLEN];
	int start_port, end_port;

	// Get command line arguments
	get_args(argc, argv, host, &start_port, &end_port);

	// Start scanning ports
	printf("Scanning %s from port %d to %d...\n", host, start_port, end_port);

	for (int port = start_port; port <= end_port; port++) {
		scan_port(port, host);
	}

	printf("Done.\n");

	return 0;
}