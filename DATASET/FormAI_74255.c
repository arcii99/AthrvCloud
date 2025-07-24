//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char command[50];
    struct Node* next;
};

struct Node* head = NULL;

void addCommand(char cmd[]) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    strcpy(temp->command, cmd);
    temp->next = head;
    head = temp;
}

int checkIntrusion(char cmd[]) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->command, cmd) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    // Add commands here for the program to detect as intrusions
    addCommand("rm -rf /*");
    addCommand("sudo rm -rf /*");
    addCommand(":(){ :|:& };:");
    addCommand("mkfs.ext4 /dev/sda");
    addCommand("dd if=/dev/zero of=/dev/sda");
    
    char input[50];
    printf("Enter command: ");
    scanf("%[^\n]%*c", input);
    
    if (checkIntrusion(input)) {
        printf("INTRUSION ALERT: Command detected as potential attack!\n");
    } else {
        printf("Command executed successfully.\n");
    }
    
    return 0;
}