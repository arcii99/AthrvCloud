//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 1024

struct imap_message {
    int seq_num;
    char* command;
    char* response;
};

char* recv_msg(FILE* stream) {
    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);

    char* msg = NULL;
    while (fgets(buf, BUF_SIZE, stream)) {
        if (msg) {
            char* tmp = msg;
            msg = (char*)realloc(msg, strlen(msg) + strlen(buf) + 1);
            if (!msg) {
                free(tmp);
                return NULL;
            }
            strcat(msg, buf);
            if (buf[strlen(buf) - 1] == '\n') {
                break;
            }
        } else {
            msg = (char*)malloc(strlen(buf) + 1);
            if (!msg) {
                return NULL;
            }
            strcpy(msg, buf);
        }
    }
    return msg;
}

void free_imap_message(struct imap_message* msg) {
    free(msg->command);
    free(msg->response);
    free(msg);
}

struct imap_message* new_imap_message(char* command) {
    struct imap_message* msg = (struct imap_message*)malloc(sizeof(struct imap_message));
    if (!msg) return NULL;

    msg->seq_num = -1;
    msg->command = (char*)malloc(strlen(command) + 1);
    if (!msg->command) {
        free_imap_message(msg);
        return NULL;
    }
    strcpy(msg->command, command);

    msg->response = NULL;
    return msg;
}

int main(int argc, char* argv[]) {
    // Connect to the IMAP server
    FILE* server = fopen("imap.example.com", "r+");
    if (!server) {
        fprintf(stderr, "Could not connect to IMAP server\n");
        return 1;
    }

    // Authenticate with the server
    char* credentials = "LOGIN username password\n";
    struct imap_message* auth_msg = new_imap_message(credentials);
    if (!auth_msg) {
        fprintf(stderr, "Could not allocate memory\n");
        fclose(server);
        return 1;
    }

    // Send the authentication message to the server
    fprintf(server, "%s", auth_msg->command);
    fflush(server);

    // Wait for and parse the response from the server
    char* resp_str = recv_msg(server);
    if (!resp_str) {
        fprintf(stderr, "Could not receive response from server\n");
        free_imap_message(auth_msg);
        fclose(server);
        return 1;
    }

    // Parse the response sequence number and update the authentication message
    int seq_num;
    if (sscanf(resp_str, "%d %s", &seq_num, auth_msg->response) != 2) {
        fprintf(stderr, "Invalid response from server: %s", resp_str);
        free(resp_str);
        free_imap_message(auth_msg);
        fclose(server);
        return 1;
    }
    auth_msg->seq_num = seq_num;

    // Free the temporary response buffer
    free(resp_str);

    // Check if authentication was successful
    if (strcmp(auth_msg->response, "OK") != 0) {
        fprintf(stderr, "Authentication failed: %s", auth_msg->response);
        free_imap_message(auth_msg);
        fclose(server);
        return 1;
    }

    printf("Authenticated with IMAP server\n");

    // Clean up
    free_imap_message(auth_msg);
    fclose(server);

    return 0;
}