//FormAI DATASET v1.0 Category: Password management ; Style: innovative
#include<stdio.h>
#include<string.h>

char master_password[] = "password123";

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

// function to get password from user
void get_password(char *password)
{
    char c;
    int i = 0;
    printf("Enter password: ");
    while((c = getchar()) != '\n') {
        if (c == 127) { // handle backspace
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        }
        else {
            password[i] = c;
            i++;
            printf("*");
        }
    }
    password[i] = '\0';
}

int main()
{
    char password[50];
    printf("Welcome to Password Manager!\n");
    printf("============================\n");
    printf("Please enter your master password to proceed\n");

    // Get Master Password
    get_password(password);
    printf("\n");

    // If Master Password is incorrect, exit
    if (strcmp(master_password, password)) {
        printf("Incorrect password. Exiting...\n");
        return 0;
    }

    printf("Password Manager successfully unlocked!\n");

    int choice;
    struct Password p;
    FILE *fptr;
    fptr = fopen("passwords.txt","a+");

    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");

        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Enter website name (without https/http): ");
                scanf("%s", p.website);

                printf("Enter username: ");
                scanf("%s", p.username);

                printf("Enter password: ");
                get_password(p.password);
                printf("\n");

                fprintf(fptr,"%s | %s | %s\n",p.website,p.username,p.password);
                printf("Password saved successfully!\n");
                break;
            case 2:
                printf("Website | Username | Password\n");
                printf("=============================\n");
                rewind(fptr); // move file pointer to start
                char line[100];
                while (fgets(line, 100, fptr)) {
                    printf("%s", line);
                }
                break;
            case 3:
                fclose(fptr);
                return 0;
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}