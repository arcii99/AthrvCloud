//FormAI DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512
#define PORT 8888

void die(char *s)
{
    perror(s);
    exit(1);
}

int main(void)
{
    struct sockaddr_in si_me, si_other;

    int sock, i, slen = sizeof(si_other), recv_len;
    char buf[BUFLEN];

    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        die("socket");
    }

    memset((char *)&si_me, 0, sizeof(si_me));

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&si_me, sizeof(si_me)) == -1)
    {
        die("bind");
    }

    while (1)
    {
        printf("Waiting for data...\n");
        fflush(stdout);

        if ((recv_len = recvfrom(sock, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen)) == -1)
        {
            die("recvfrom");
        }

        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Received message: %s\n", buf);

        for (i = 0; i < recv_len; i++)
        {
            buf[i] = tolower(buf[i]);
        }

        if (sendto(sock, buf, recv_len, 0, (struct sockaddr *)&si_other, slen) == -1)
        {
            die("sendto");
        }
    }

    close(sock);
    return 0;
}