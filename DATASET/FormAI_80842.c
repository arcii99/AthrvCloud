//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Ken Thompson
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void print_password(char* password) {
    printf("Your secure password is: %s", password);
}

char* generate_password(int length) {
    char* password = malloc((length+1)*sizeof(char));
    int i;

    for (i = 0; i < length; ++i) {
        int option = rand()%3;

        if (option == 0) {
            password[i] = 'A' + rand()%26;
        }
        else if (option == 1) {
            password[i] = 'a' + rand()%26;
        }
        else {
            password[i] = '0' + rand()%10;
        }
    }

    password[length] = '\0';

    return password;
}

int main(int argc, char const *argv[]) {
    int length;

    printf("Enter the desired length of your secure password: ");
    scanf("%d", &length);

    srand(time(NULL));

    char* password = generate_password(length);

    print_password(password);

    free(password);

    return 0;
}