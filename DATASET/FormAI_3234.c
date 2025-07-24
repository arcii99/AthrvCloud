//FormAI DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char* email = (char*) malloc(100 * sizeof(char));
    char* password = (char*) malloc(50 * sizeof(char));
    char* server = (char*) malloc(50 * sizeof(char));
    char* message = (char*) malloc(1000 * sizeof(char));
    int port = rand() % 100 + 2000;
    
    printf("Enter your email address: ");
    scanf("%s", email);
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    printf("Enter your email server: ");
    scanf("%s", server);
    
    sprintf(server + strlen(server), ".%c%c", rand() % 26 + 'a', rand() % 26 + 'a');
    
    printf("Enter port number (default: %d): ", port);
    scanf("%d", &port);
    
    printf("Enter your message: ");
    scanf("%s", message);
    
    printf("\nSending email to %s...\n", email);
    printf("Server: %s\n", server);
    printf("Port: %d\n", port);
    printf("Message: %s\n\n", message);
    
    printf("Email sent successfully!\n");
    
    free(email);
    free(password);
    free(server);
    free(message);
    
    return 0;
}