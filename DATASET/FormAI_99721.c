//FormAI DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK "66.249.64.0/19" // Change IP according to the requirement

int main(int argc, char* argv[]) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int found = 0;
 
    fp = fopen("/var/log/auth.log", "r"); // Reading the authentication log

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "sshd")) {
            if (strstr(line, BLOCK)) {
                found = 1;
                break;
            }
        }
    }

    if (found == 1) {
        printf("Firewall blocked %s due to suspicious activity\n", BLOCK);
        return EXIT_FAILURE;
    } else {
        printf("Authorized login\n");
        return EXIT_SUCCESS;
    }
}