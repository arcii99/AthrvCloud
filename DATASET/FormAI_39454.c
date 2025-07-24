//FormAI DATASET v1.0 Category: QR code reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 500

int main()
{
    char input_string[MAX_INPUT_SIZE];
    printf("Welcome to the Cyberpunk QR code reader!\n\n");
    printf("Please enter the QR code below:\n");
    scanf("%[^\n]%*c", input_string);

    // Check if input string starts with a valid QR code prefix
    if (strncmp(input_string, "CP-QR:", 6) != 0)
    {
        printf("\nInvalid input string!\n");
        return 0;
    }

    // Extract the payload from the input string
    char* payload = strchr(input_string, ':') + 1;

    // Decode the payload
    char* decoded_payload = (char*) malloc(sizeof(char) * (strlen(payload) + 1));

    int i;
    for (i = 0; i < strlen(payload); i++)
    {
        decoded_payload[i] = payload[i] - i;
    }
    decoded_payload[i] = '\0';

    // Print the decoded payload
    printf("\n\nDECODED PAYLOAD:\n%s\n", decoded_payload);

    free(decoded_payload);
    
    return 0;
}