//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Below are the various character arrays used to generate the password
char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
char numbers[] = "0123456789";
char special_characters[] = "!@#$%^&*()-_=+[{]}|;:',<.>/";

int main() {
    // Get the required attributes for password generation
    int password_length;
	char has_numbers, has_special_characters;
    printf("Enter the length of your password: ");
    scanf("%d", &password_length);
    printf("Should your password contain numbers? (1 for Yes, 0 for No)");
    scanf("%d", &has_numbers);
    printf("Should your password contain special characters? (1 for Yes, 0 for No)");
    scanf("%d", &has_special_characters);
    // Create the base string for password generation
    char password_base[100] = "";
    strcat(password_base, alphabet);
    if (has_numbers == 1) {
        strcat(password_base, numbers);
    }
    if (has_special_characters == 1) {
        strcat(password_base, special_characters);
    }
    // Generate the password
    srand(time(NULL));
    char password[100] = "";
    for(int i = 0; i < password_length; i++) {
        int random_index = rand() % strlen(password_base);
        password[i] = password_base[random_index];
    }
    // Display the generated password
    printf("Your secure password is: %s", password);
    return 0;
}