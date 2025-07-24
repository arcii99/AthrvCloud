//FormAI DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_LINE 4096
#define MAX_RULES 1000

typedef struct {
    struct in_addr ip;
    int prefix;
} rule_t;

typedef struct {
    rule_t rules[MAX_RULES];
    int count;
} ruleset_t;

int main() {
    char line[MAX_LINE];
    ruleset_t ruleset;
    ruleset.count = 0;

    printf("Enter the rules one per line (IP/prefix):\n");
    while (fgets(line, MAX_LINE, stdin)) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove trailing newline
        char *slash = strchr(line, '/');
        if (!slash) {
            fprintf(stderr, "Invalid rule: %s\n", line);
            continue;
        }
        *slash = '\0'; // Split IP and prefix
        struct in_addr ip = {0};
        if (!inet_pton(AF_INET, line, &ip)) {
            fprintf(stderr, "Invalid IP address: %s\n", line);
            continue;
        }
        int prefix = atoi(slash + 1);
        if (prefix < 0 || prefix > 32) {
            fprintf(stderr, "Invalid prefix: %d\n", prefix);
            continue;
        }
        rule_t rule = {ip, prefix};
        ruleset.rules[ruleset.count++] = rule;
        if (ruleset.count == MAX_RULES) {
            fprintf(stderr, "Rule limit reached, ignoring further rules.\n");
            break;
        }
    }

    printf("Enter the IP addresses one per line that need to be checked:\n");
    while (fgets(line, MAX_LINE, stdin)) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove trailing newline
        struct in_addr ip = {0};
        if (!inet_pton(AF_INET, line, &ip)) {
            fprintf(stderr, "Invalid IP address: %s\n", line);
            continue;
        }
        int i;
        for (i = 0; i < ruleset.count; i++) {
            if ((ip.s_addr >> (32 - ruleset.rules[i].prefix)) == (ruleset.rules[i].ip.s_addr >> (32 - ruleset.rules[i].prefix))) {
                printf("%s is allowed by rule %d\n", line, i + 1);
                break;
            }
        }
        if (i == ruleset.count) {
            printf("%s is NOT allowed\n", line);
        }
    }

    return 0;
}