//FormAI DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IP_LENGTH 15
#define MAX_WHITELIST_SIZE 100

struct ip_address {
    int octets[4];
};

struct firewall {
    struct ip_address whitelist[MAX_WHITELIST_SIZE];
    int whitelist_size;
};

void init_firewall(struct firewall *fw) {
    fw->whitelist_size = 0;
}

void add_to_whitelist(struct firewall *fw, struct ip_address ip) {
    if (fw->whitelist_size < MAX_WHITELIST_SIZE) {
        fw->whitelist[fw->whitelist_size] = ip;
        fw->whitelist_size++;
    }
}

void print_ip(struct ip_address ip) {
    printf("%d.%d.%d.%d", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);
}

void print_whitelist(struct firewall fw) {
    printf("Whitelist:\n");
    for (int i = 0; i < fw.whitelist_size; i++) {
        printf("\t");
        print_ip(fw.whitelist[i]);
        printf("\n");
    }
}

bool is_ip_in_whitelist(struct firewall fw, struct ip_address ip) {
    for (int i = 0; i < fw.whitelist_size; i++) {
        bool match = true;
        for (int j = 0; j < 4; j++) {
            if (fw.whitelist[i].octets[j] != ip.octets[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }
    return false;
}

bool is_valid_ip(char *ip_str, struct ip_address *ip) {
    char str[MAX_IP_LENGTH + 1];
    strcpy(str, ip_str);
    char *token = strtok(str, "."); 
    int i = 0;
    while (token != NULL) {
        int octet = atoi(token);
        if (octet < 0 || octet > 255) {
            return false;
        }
        ip->octets[i] = octet;
        i++;
        token = strtok(NULL, "."); 
    }
    if (i != 4) {
        return false;
    }
    return true;
}

int main() {
    struct firewall fw;
    init_firewall(&fw);

    // Add some IPs to the whitelist
    struct ip_address ip;
    if (is_valid_ip("192.168.1.1", &ip)) {
        add_to_whitelist(&fw, ip);
    }
    if (is_valid_ip("10.0.0.1", &ip)) {
        add_to_whitelist(&fw, ip);
    }
    if (is_valid_ip("172.16.0.1", &ip)) {
        add_to_whitelist(&fw, ip);
    }

    // Print the current whitelist
    print_whitelist(fw);

    // Check some IPs against the whitelist
    char ip_str[MAX_IP_LENGTH + 1];
    printf("Enter an IP address to check: ");
    scanf("%s", ip_str);
    if (is_valid_ip(ip_str, &ip)) {
        if (is_ip_in_whitelist(fw, ip)) {
            printf("IP address ");
            print_ip(ip);
            printf(" is in the whitelist.\n");
        } else {
            printf("IP address ");
            print_ip(ip);
            printf(" is not in the whitelist.\n");
        }
    } else {
        printf("Invalid IP address.\n");
    }

    return 0;
}