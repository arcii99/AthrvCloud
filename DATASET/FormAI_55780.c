//FormAI DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define maximum IP address length
#define MAX_IP_LEN 15

/*
 * Structure to hold firewall rule information
 */
typedef struct {
    char ip[MAX_IP_LEN + 1];
    bool allowed;
} FirewallRule;

/*
 * Check if IP address matches firewall rule
 */
bool firewall_match(const char *ip_address, const FirewallRule *rule) {
    int i = 0, j = 0;

    while (ip_address[i] != '\0' && rule->ip[j] != '\0') {
        if (rule->ip[j] == '*') {
            // Check if there are any characters after the wildcard
            if (rule->ip[j+1] == '\0') {
                // Wildcard at end of rule matches anything after this point
                return true;
            }

            // Check if remaining characters in IP address match remaining characters in rule
            char remaining_ip[MAX_IP_LEN + 1];
            strcpy(remaining_ip, &ip_address[i+1]);
            if (strstr(remaining_ip, &rule->ip[j+1]) == NULL) {
                // Wildcard with additional characters did not match
                return false;
            }

            // Remaining characters matched, so this rule matches the IP address
            return true;
        }

        if (ip_address[i] != rule->ip[j]) {
            // Characters did not match, so this rule does not match the IP address
            return false;
        }

        i++;
        j++;
    }

    return (ip_address[i] == '\0' && rule->ip[j] == '\0');
}

/*
 * Check if IP address is allowed by firewall rules
 */
bool firewall_allow(const char *ip_address, const FirewallRule *rules, int num_rules) {
    int i;

    for (i = 0; i < num_rules; i++) {
        if (firewall_match(ip_address, &rules[i])) {
            // IP address matches this firewall rule
            return rules[i].allowed;
        }
    }

    // No firewall rule matched this IP address
    return false;
}

int main() {
    // Create some example firewall rules
    FirewallRule rules[] = {
        {"10.0.0.*", true},
        {"193.168.1.5", true},
        {"123.45.67.89", false},
        {"10.10.10.10", true},
        {"192.168.0.1", false},
    };
    int num_rules = sizeof(rules) / sizeof(rules[0]);

    // Test some IP addresses against the firewall rules
    const char *test_ips[] = {
        "10.0.0.2",
        "10.0.0.5",
        "10.0.0.10",
        "192.168.1.5",
        "193.168.1.5",
        "123.45.67.89",
        "123.45.67.90",
        "10.10.10.10",
        "10.10.10.11",
        "192.168.0.1",
        "192.168.0.2",
        "192.168.1.1",
        "192.168.1.2",
        "8.8.8.8",
        "9.9.9.9",
    };
    int num_test_ips = sizeof(test_ips) / sizeof(test_ips[0]);

    // Check if each IP is allowed by the firewall rules
    for (int i = 0; i < num_test_ips; i++) {
        bool allowed = firewall_allow(test_ips[i], rules, num_rules);
        printf("%s: %s\n", test_ips[i], allowed ? "ALLOWED" : "BLOCKED");
    }

    return 0;
}