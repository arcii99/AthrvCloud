//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define MAX_PACKET_SIZE 4096
#define PHI 0x9e3779b9
#define PR_SET_NAME 15

unsigned long int Q[4096], c = 362436;
int fd, on = 1;

char *ip;
struct sockaddr_in sin;

void init_rand(unsigned long int x) {
    int i;

    Q[0] = x;
    Q[1] = x + PHI;
    Q[2] = x + PHI + PHI;

    for (i = 3; i < 4096; i++)
        Q[i] = Q[i - 3] ^ Q[i - 2] ^ PHI ^ i;
}

unsigned long int rand_cmwc(void) {
    unsigned long long int t, a = 18782LL;
    static unsigned long int i = 4095;
    unsigned long int x, r = 0xfffffffe;

    i = (i + 1) & 4095;
    t = a * Q[i] + c;
    c = (t >> 32);
    x = t + c;
    if (x < c) {
        x++;
        c++;
    }

    return (Q[i] = r - x);
}

void setup_sockaddr(struct sockaddr_in *address, char *hostname, int port) {
    struct hostent *host;

    host = gethostbyname(hostname);
    address->sin_family = AF_INET;
    address->sin_port = htons(port);
    address->sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *) *host->h_addr_list));
}

void send_packet(unsigned char *packet, unsigned int packet_len) {
    if (sendto(fd, packet, packet_len, 0, (struct sockaddr *) &sin, sizeof(sin)) == -1)
        fprintf(stderr, "error\n");
}

unsigned char *pkt_hex1[] = {
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xff",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xfe",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xfd",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xfc",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xfb",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xfa",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xf9",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xf8"};

unsigned char *pkt_hex2[] = {
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x01",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x02",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x04",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x05",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x06",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x07"};

unsigned char *pkt_hex3[] = {
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xfe",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff\xff",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xe9\x9e\x0d\x46\x98\x45\x3c\x27\xd3\x69\x77\x2c\x56\xc0\xfa\x61\xd5",
        "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x07\x52\x04\x02\xf3\xf6\xf7\x3b\xd6\x75\x78\xaf\x8f\xeb\xad\x89\x1d\xb4}"
};

unsigned char headers[] = "\x08\x00\x45\x00\x00\x3C\xef\xbe\x00\x00\x40\x01\xaf\x27";
unsigned char headers2[] = "\x00\x00\x00\x00\xff\xff";

void send_packet2(unsigned char *packet, unsigned int packet_len) {
    if (sendto(fd, packet, packet_len, 0, (struct sockaddr *) &sin, sizeof(sin)) == -1)
        fprintf(stderr, "error\n");
}

void scan_wifi(char *ip, int port) {
    int i, j, l = 0, k = 0, w = 0, e = 0, r = 0, t = 0, y = 0;

    for (j = 0; j < 4; j++) {
        for (i = 0; i < 8; i++) {
            sin.sin_family = AF_INET;
            sin.sin_port = htons(port);
            sin.sin_addr.s_addr = inet_addr(ip);

            fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
            if (fd < 0) {
                fprintf(stderr, "error\n");
                exit(-1);
            }

            if (setsockopt(fd, IPPROTO_IP, IP_HDRINCL, (char *) &on, sizeof(on)) == -1) {
                fprintf(stderr, "error\n");
                exit(-1);
            }

            if (setsockopt(fd, SOL_SOCKET, SO_BROADCAST, (char *) &on, sizeof(on)) == -1) {
                fprintf(stderr, "error\n");
                exit(-1);
            }

            if (setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, "lo", strlen("lo")) == -1) {
                fprintf(stderr, "error\n");
                exit(-1);
            }

            init_rand(time(NULL) ^ getpid());
            u_char packet[MAX_PACKET_SIZE];

            memset(packet, 0, MAX_PACKET_SIZE);

            for (i = 0; i < sizeof(headers) - 1; i++) {
                packet[i] = headers[i];
            }

            for (w = 0; w < 2; w++) {
                for (e = 0; e < 8; e++) {
                    for (r = 0; r < 4; r++) {
                        packet[sizeof(headers) - 1 + t] = pkt_hex1[w][r];
                        t++;
                    }
                }
            }

            for (k = 0; k < sizeof(headers2) - 1; k++) {
                packet[sizeof(headers) - 1 + t] = headers2[k];
                t++;
            }

            for (l = 0; l < 3; l++) {
                for (y = 0; y < 8; y++) {
                    for (i = 0; i < 4; i++) {
                        packet[sizeof(headers) - 1 + t] = pkt_hex3[l][i];
                        t++;
                    }
                }
            }

            send_packet(packet, sizeof(packet));
        }
        sleep(2);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <target IP>\n", argv[0]);
        exit(-1);
    }

    ip = argv[1];
    setup_sockaddr(&sin, ip, 80);

    printf("Scanning for wireless networks...\n");
    scan_wifi(ip, 80);

    return 0;
}