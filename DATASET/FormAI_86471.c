//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: happy
#include <stdio.h>

// Watermarking function
void watermark(char* data, int key) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] = data[i] ^ key; // XOR operation
    }
}

// Function to check if watermark is present
int check_watermark(char* data, int key) {
    for (int i = 0; i < strlen(data); i++) {
        if ((data[i] ^ key) < 32 || (data[i] ^ key) > 126) {
            return 0; // watermark not found
        }
    }
    return 1; // watermark found
}

int main() {

    char message[100];
    int key;
    printf("Enter message: ");
    scanf("%[^\n]s", message);
    printf("Enter key: ");
    scanf("%d", &key);

    watermark(message, key);

    printf("Watermarked message: %s\n", message);

    int check = check_watermark(message, key);

    if (check == 1) {
        printf("Watermark found!\n");
    }
    else {
        printf("Watermark not found!\n");
    }

    return 0;
}