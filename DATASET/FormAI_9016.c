//FormAI DATASET v1.0 Category: Firewall ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <signal.h>
#include <unistd.h>

#define BUFLEN 65536

#define ALLOW "ALLOW"
#define BLOCK "BLOCK"

/* Function prototypes */
void sig_handler(int);

/* Global variables */
volatile sig_atomic_t interrupted;
char *file_path;

/* Signal handler function */
void sig_handler(int signum) {
    if (signum == SIGINT) {
        interrupted = 1;
        unlink(file_path);
    }
}

/* Main function */
int main(int argc, char **argv) {
    FILE *fp;
    char *rule;
    char buf[BUFLEN];
    struct sockaddr_in saddr;
    int sockfd, recv_len;
    socklen_t saddr_len = sizeof(saddr);
    struct iphdr *iph;
    struct udphdr *udph;
    struct tcphdr *tcph;
    char *data;
    char *dst_ip;
    uint16_t dst_port;
    int i;

    /* Check command-line arguments */
    if (argc != 2) {
        printf("Usage: %s <rules-file>\n", argv[0]);
        return 1;
    }

    /* Set up signal handler */
    interrupted = 0;
    file_path = strdup("tmp.XXXXXX");
    signal(SIGINT, sig_handler);

    /* Open rules file */
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open rules file '%s'\n", argv[1]);
        return 1;
    }

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP | IPPROTO_TCP);
    if (sockfd == -1) {
        printf("Error: could not open socket\n");
        fclose(fp);
        return 1;
    }

    /* Set socket options */
    int on = 1;
    if ((setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on))) == -1) {
        printf("Error: could not set socket options\n");
        close(sockfd);
        fclose(fp);
        return 1;
    }

    /* Read rules from file */
    while ((rule = fgets(buf, BUFLEN, fp)) != NULL) {
        printf("Adding rule: %s", rule);
        if (strncmp(rule, ALLOW, strlen(ALLOW)) == 0) {
            printf("Allowed IP addresses:\n");
            for (i = strlen(ALLOW) + 1; i < strlen(rule) - 1; i++) {
                printf("%c", rule[i]);
            }
        } else if (strncmp(rule, BLOCK, strlen(BLOCK)) == 0) {
            printf("Blocked IP addresses:\n");
            for (i = strlen(BLOCK) + 1; i < strlen(rule) - 1; i++) {
                printf("%c", rule[i]);
            }
        }
    }
    fclose(fp);

    /* Start listening for packets */
    printf("Listening for incoming packets...\n");
    while (!interrupted) {
        recv_len = recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr *)&saddr, &saddr_len);
        if (recv_len < 0)
            continue;

        /* Parse and process packet */
        iph = (struct iphdr *)buf;
        if (iph->protocol == IPPROTO_UDP) {
            udph = (struct udphdr *)(buf + iph->ihl * 4);
            data = (char *)(buf + iph->ihl * 4 + sizeof(struct udphdr));
            dst_ip = inet_ntoa((struct in_addr){iph->daddr});
            dst_port = ntohs(udph->dest);
            printf("Received UDP packet to %s:%d\n", dst_ip, dst_port);
        } else if (iph->protocol == IPPROTO_TCP) {
            tcph = (struct tcphdr *)(buf + iph->ihl * 4);
            data = (char *)(buf + iph->ihl * 4 + tcph->doff * 4);
            dst_ip = inet_ntoa((struct in_addr){iph->daddr});
            dst_port = ntohs(tcph->dest);
            printf("Received TCP packet to %s:%d\n", dst_ip, dst_port);
        } else {
            continue;
        }

        /* Check packet against rules */
        fp = fopen(argv[1], "r");
        while ((rule = fgets(buf, BUFLEN, fp)) != NULL) {
            if (strncmp(rule, ALLOW, strlen(ALLOW)) == 0) {
                if (strstr(rule, dst_ip) != NULL) {
                    printf("IP address %s allowed!\n", dst_ip);
                    break;
                }
            } else if (strncmp(rule, BLOCK, strlen(BLOCK)) == 0) {
                if (strstr(rule, dst_ip) != NULL) {
                    printf("IP address %s blocked!\n", dst_ip);
                    break;
                }
            }
        }
        fclose(fp);
    }

    /* Clean up */
    close(sockfd);
    free(file_path);
    printf("Exiting...\n");
    return 0;
}