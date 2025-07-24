//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100
#define MAX_SUSPICIOUS_WORDS 10

int main() {
    char input[MAX_INPUT_LEN];
    char suspicious_words[MAX_SUSPICIOUS_WORDS][25] = {"hack", "password", "root", "admin", "sudo", "virus", "malware", "trojan", "backdoor", "shell"};

    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter your command:\n");

    while (1) {
        fgets(input, MAX_INPUT_LEN, stdin);
        input[strcspn(input, "\n")] = 0;

        for (int i = 0; i < MAX_SUSPICIOUS_WORDS; i++) {
            if (strstr(input, suspicious_words[i])) {
                printf("INTRUSION ALERT: Suspicious word '%s' found in input!\n", suspicious_words[i]);
                break;
            }
        }
        printf("Please enter your next command:\n");
    }
    return 0;
}