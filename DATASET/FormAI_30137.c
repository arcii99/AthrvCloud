//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void check_for_intruder() {
    char *current_user = getlogin();
    char buffer[1024];
    system("who > current_users.txt"); // write current user list to file
    FILE *file_ptr = fopen("current_users.txt", "r");
    while (fgets(buffer, 1024, file_ptr)) {
        if (strstr(buffer, current_user) == NULL) { // if user not found in list
            printf("INTRUDER ALERT! Intruder's information:\n%s", buffer);
            exit(1); // exit program with error code 1
        }
    }
    fclose(file_ptr);
    remove("current_users.txt"); // remove temporary file
}

int main() {
    printf("INTRUSION DETECTION SYSTEM INITIATED...");
    while (1) { // run forever
        check_for_intruder();
        sleep(5); // wait 5 seconds before checking again
    }
    return 0; // program should never reach this point
}