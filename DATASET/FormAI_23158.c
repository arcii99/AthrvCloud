//FormAI DATASET v1.0 Category: Firewall ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RULES 50
#define MAX_IP_LEN 15

struct Rule {
    char ip[MAX_IP_LEN + 1];
    bool allow;
};

struct RuleSet {
    struct Rule rules[MAX_RULES];
    int len;
};

int parseIP(char *ip_str, int *ip) {
    int count = sscanf(ip_str, "%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3);
    if (count != 4) {
        return -1;
    }
    for (int i = 0; i < 4; i++) {
        if (ip[i] < 0 || ip[i] > 255) {
            return -1;
        }
    }
    return 0;
}

void listRules(struct RuleSet *ruleset) {
    printf("Rules:\n");
    for (int i = 0; i < ruleset->len; i++) {
        printf("%s %s\n", ruleset->rules[i].ip, ruleset->rules[i].allow ? "allow" : "deny");
    }
}

bool isAllowed(struct RuleSet *ruleset, char *ip_str) {
    int ip[4];
    if (parseIP(ip_str, ip) < 0) {
        printf("Invalid IP address: %s\n", ip_str);
        return false;
    }

    for (int i = 0; i < ruleset->len; i++) {
        int rule_ip[4];
        if (parseIP(ruleset->rules[i].ip, rule_ip) < 0) {
            printf("Invalid rule IP: %s\n", ruleset->rules[i].ip);
            continue;
        }
        bool match = true;
        for (int j = 0; j < 4; j++) {
            if (rule_ip[j] != ip[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return ruleset->rules[i].allow;
        }
    }
    return true;
}

void showPrompt() {
    printf("Enter IP address or 'q' to quit: ");
}

int main() {
    struct RuleSet ruleset = {0};

    printf("Enter rules:\n");
    char line[256];
    while (ruleset.len < MAX_RULES && fgets(line, sizeof(line), stdin)) {
        char *ip_str = strtok(line, " \t\r\n");
        if (!ip_str) {
            continue;
        }
        bool allow = true;
        char *action_str = strtok(NULL, " \t\r\n");
        if (action_str && strcmp(action_str, "deny") == 0) {
            allow = false;
        }

        if (parseIP(ip_str, NULL) < 0) {
            printf("Invalid IP address: %s\n", ip_str);
            continue;
        }

        strncpy(ruleset.rules[ruleset.len].ip, ip_str, MAX_IP_LEN);
        ruleset.rules[ruleset.len].ip[MAX_IP_LEN] = '\0';
        ruleset.rules[ruleset.len].allow = allow;
        ruleset.len++;
    }

    listRules(&ruleset);

    char ip_str[MAX_IP_LEN + 1];
    while (true) {
        showPrompt();
        if (!fgets(ip_str, sizeof(ip_str), stdin) || ip_str[0] == 'q') {
            break;
        }

        ip_str[strcspn(ip_str, "\r\n")] = '\0'; // remove trailing newline

        bool allowed = isAllowed(&ruleset, ip_str);
        printf("%s is %s\n", ip_str, allowed ? "allowed" : "denied");
    }

    return 0;
}