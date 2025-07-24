//FormAI DATASET v1.0 Category: Firewall ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main()
{
    char input[50];
    int allow = 0;

    printf("Enter IP address: ");
    scanf("%s", input);

    if (strcmp(input, "192.168.0.1") == 0 || strcmp(input, "10.0.0.1") == 0) {
        allow = 1;
    }

    if (allow == 1) {
        printf("Access granted to %s\n", input);
    } else {
        printf("Access denied to %s\n", input);
    }

    return 0;
}