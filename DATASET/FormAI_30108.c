//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_PASSWORDS 100

void generate_hash(char *password, char *hash)
{
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    char message[1024];
    unsigned int md_len;

    md = EVP_sha256();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, password, strlen(password));
    EVP_DigestFinal_ex(mdctx, message, &md_len);
    EVP_MD_CTX_free(mdctx);

    int i;
    for(i = 0; i < md_len; i++)
        sprintf(&hash[i * 2], "%02x", message[i]);
}

typedef struct {
    char name[30];
    char hash[65];
} password;

int main()
{
    password passwords[MAX_PASSWORDS];
    int password_count = 0;
    char input[50];
    printf("Welcome to Password Manager!\n");

    while(1) {
        printf("What would you like to do? (add/view/exit): ");
        fgets(input, 50, stdin);
        strtok(input, "\n");

        if(!strcmp(input, "add")) {
            char name[30];
            char password[30];
            char hash[65];

            printf("Enter name: ");
            fgets(name, 30, stdin);
            strtok(name, "\n");

            printf("Enter password: ");
            fgets(password, 30, stdin);
            strtok(password, "\n");

            generate_hash(password, hash);

            strcpy(passwords[password_count].name, name);
            strcpy(passwords[password_count].hash, hash);
            password_count++;

            printf("Password added.\n");

        } else if(!strcmp(input, "view")) {
            int i;
            for(i = 0; i < password_count; i++) {
                printf("Name: %s\n", passwords[i].name);
                printf("Hash: %s\n", passwords[i].hash);
            }

        } else if(!strcmp(input, "exit")) {
            printf("Goodbye.\n");
            break;

        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}