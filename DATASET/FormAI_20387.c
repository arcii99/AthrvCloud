//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} User;

typedef struct {
    int id;
    char message[200];
    char timestamp[20];
    int user_id;
} Post;

void print_user(User u) {
    printf("ID: %d\n", u.id);
    printf("Name: %s\n", u.name);
    printf("Email: %s\n", u.email);
}

void print_post(Post p) {
    printf("ID: %d\n", p.id);
    printf("Message: %s\n", p.message);
    printf("Timestamp: %s\n", p.timestamp);
    printf("User ID: %d\n", p.user_id);
}

void query_posts_by_user_id(Post *posts, int num_posts, int user_id) {
    for (int i = 0; i < num_posts; i++) {
        if (posts[i].user_id == user_id) {
            printf("Post %d:\n", i + 1);
            print_post(posts[i]);
        }
    }
}

void query_users_by_name(User *users, int num_users, char *name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("User %d:\n", i + 1);
            print_user(users[i]);
        }
    }
}

int main() {
    User users[3] = {{1, "John Doe", "johndoe@gmail.com"},
                     {2, "Jane Smith", "janesmith@gmail.com"},
                     {3, "Bob Johnson", "bjohnson@gmail.com"}};
    Post posts[4] = {{1, "Hello world!", "2021-01-01 12:00:00", 1},
                     {2, "My name is Jane.", "2021-01-02 13:00:00", 2},
                     {3, "Today is a good day.", "2021-01-02 14:00:00", 3},
                     {4, "I love pizza!", "2021-01-03 15:00:00", 1}};

    printf("### Querying posts by user ID ###\n");
    query_posts_by_user_id(posts, 4, 2);

    printf("\n### Querying users by name ###\n");
    query_users_by_name(users, 3, "John Doe");

    return 0;
}