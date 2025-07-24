//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // initialize variables
    bool allowed = false;
    char packet[256];

    // check command line parameters
    if (argc < 2) {
        printf("Usage: %s <rule file>\n", argv[0]);
        exit(1);
    }

    // open rule file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open rule file\n");
        exit(1);
    }

    // read rules from file
    char rules[256][256];
    int num_rules = 0;
    while (fgets(rules[num_rules], sizeof(rules[num_rules]), fp)) {
        strtok(rules[num_rules], "\n");
        num_rules++;
    }
    fclose(fp);

    // wait for incoming packets
    while (fgets(packet, sizeof(packet), stdin)) {
        strtok(packet, "\n");
        allowed = false;

        // check packet against rules
        for (int i = 0; i < num_rules; i++) {
            if (strstr(packet, rules[i]) != NULL) {
                allowed = true;
                break;
            }
        }

        // output packet status
        if (allowed) {
            printf("%s: allowed\n", packet);
        } else {
            printf("%s: blocked\n", packet);
        }
    }

    return 0;
}