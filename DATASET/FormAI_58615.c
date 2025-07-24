//FormAI DATASET v1.0 Category: Port Scanner ; Style: Alan Touring
// This is a simple port scanner written in C
// It will scan a range of ports and report which are open

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	const char *host = "127.0.0.1";
	int start_port = 1;
	int end_port = 1024;
	struct sockaddr_in target;
	int sock, ret_code, i;

	if (argc > 1) {
		host = argv[1];
		if (argc > 2) {
			start_port = atoi(argv[2]);
			if (argc > 3) {
				end_port = atoi(argv[3]);
			}
		}
	}

	memset(&target, 0, sizeof(target));
	target.sin_family = AF_INET;
	target.sin_addr.s_addr = inet_addr(host);

	for (i = start_port; i <= end_port; i++) {
		target.sin_port = htons(i);
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0) {
			continue;
		}
		ret_code = connect(sock, (struct sockaddr *)&target, sizeof(target));
		if (ret_code == 0) {
			printf("Port %d is open!\n", i);
		}
		close(sock);
	}

	return 0;
}