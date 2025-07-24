//FormAI DATASET v1.0 Category: Password management ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_PASS_LEN 20
#define MAX_USERS 5

struct user{
    char username[20];
    char password[MAX_PASS_LEN];
};

int login(struct user*, int);
void change_password(struct user*);
char* password_generator();

int main(){
    struct user users[MAX_USERS] = {{"user1", "pass1"}, {"user2", "pass2"}, {"user3", "pass3"},{"user4", "pass4"}, {"user5", "pass5"}};
    int user_count = 5;
    int choice, index;
    char username[20], password[MAX_PASS_LEN], *new_password;

    printf("Welcome to Password Manager\n");

    while(1){
        printf("\n\n1. Login\n2. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                index = login(users, user_count);
                if(index == -1){
                    printf("\nInvalid Username or Password\n");
                    break;
                }

                printf("\nLogged in as %s\n", users[index].username);

                printf("\nDo you want to change your password? (y/n) ");
                getchar();
                char ans = getchar();
                if(tolower(ans) == 'y'){
                    change_password(&users[index]);
                }
                printf("\nThank you! Logging out...\n");
                break;

            case 2:
                printf("\nExiting Password Manager\n");
                exit(0);

            default:
                printf("\nInvalid Choice\n");
        }
    }

    return 0;
}

int login(struct user* users, int user_count){
    char username[20], password[MAX_PASS_LEN];
    int i;

    printf("\nEnter username: ");
    scanf("%s", username);
    printf("\nEnter password: ");
    scanf("%s", password);

    for(i=0;i<user_count;i++){
        if(strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0){
            return i;
        }
    }

    return -1;
}

void change_password(struct user* user){
    char* new_password;
    new_password = password_generator();
    strcpy(user->password, new_password);
    printf("\nYour new password is %s\n", new_password);
}

char* password_generator(){
    char* password = malloc(sizeof(char)*MAX_PASS_LEN);
    static const char values[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;

    for(i=0;i<MAX_PASS_LEN-1;i++){
        password[i] = values[rand()%62];
    }
    password[MAX_PASS_LEN-1] = '\0';
    return password;
}