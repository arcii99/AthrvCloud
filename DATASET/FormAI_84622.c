//FormAI DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <string.h>

int main() {

    /* Initializing necessary variables */
    char input[100];
    char allowed_ip[10][20] = {"192.168.0.1", "192.168.0.2"}; // Sample allowed IPs
    int i, flag = 0;

    /* Taking input from user */
    printf("Enter the IP address to check: ");
    fgets(input, 100, stdin);

    /* Removing the trailing newline character */
    input[strcspn(input, "\n")] = 0;

    /* Checking if the entered IP belongs to the allowed IPs */
    for(i=0; i<2; i++) {
        if(strcmp(input, allowed_ip[i]) == 0) {
            flag = 1;
            break;
        }
    }

    /* Blocking the IP if not allowed */
    if(flag == 0) {
        printf("Access Denied!");
        return 0;
    }

    /* Else, allowing access */
    printf("Access Granted!");

    return 0;
}