//FormAI DATASET v1.0 Category: Browser Plugin ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypted strings
char *encrypted_url = "1$mc-nfp14d8#";
char *encrypted_username = "8$gc-dsp16a5#";
char *encrypted_password = "9$gf-lmp12c3#";

// Function to decrypt a string
char *decrypt(char *encrypted, int key) {
    int length = strlen(encrypted);
    char *decrypted = (char*) malloc(length+1);
    for (int i = 0; i < length; i++) {
        decrypted[i] = encrypted[i] - key;
    }
    decrypted[length] = '\0';
    return decrypted;
}
// Function to show login form
void show_login_form(char *url) {
    char *username = decrypt(encrypted_username, 2);
    char *password = decrypt(encrypted_password, 3);
    printf("Please login to %s\n", url);
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    printf("Login successful!\n");
}

int main() {
    char *url = decrypt(encrypted_url, 1);
    show_login_form(url);
    return 0;
}