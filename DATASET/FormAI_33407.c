//FormAI DATASET v1.0 Category: Firewall ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello! I am your brave C Firewall.\n");
    printf("I will protect your computer from malicious attacks.\n");
    printf("Enter website URL to allow or block: ");
    
    char input[1000];
    scanf("%s", input);

    if (strcmp(input, "www.example.com") == 0) {
        printf("Allowing access to www.example.com\n");
        // Code to allow access to website
    } else {
        printf("Blocking access to %s\n", input);
        // Code to block access to website
    }

    printf("Firewall settings saved.\n");
    return 0;
}