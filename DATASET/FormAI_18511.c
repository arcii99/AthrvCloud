//FormAI DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[100];
    char artist[50];
    int year;
    int rating;
} Song;

Song songs[100];
int num_songs = 0;
char password[] = "password123";
int apocalypse = 1;

int main() {
    printf("Welcome to the Music Library Management System!\n");
    login();

    while (apocalypse) {
        int choice = menu();
        switch(choice) {
            case 1: add_song(); break;
            case 2: remove_song(); break;
            case 3: display_library(); break;
            case 4: search(); break;
            case 5: rate_song(); break;
            case 6: change_password(); break;
            case 7: apocalypse = 0;
                    printf("Goodbye. Stay safe out there!\n");
                    break;
            default: printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

void login() {
    char input[50];
    int attempts = 0;
    while (attempts < 3) {
        printf("Enter password: ");
        scanf("%s", input);
        if (strcmp(input, password) == 0) {
            printf("Login successful.\n");
            return;
        } else {
            printf("Incorrect password. %d attempts left.\n", 2 - attempts);
            attempts++;
        }
    }
    printf("Too many attempts. Program terminating.\n");
    exit(0);
}

int menu() {
    printf("\nMenu:\n");
    printf("1. Add Song\n");
    printf("2. Remove Song\n");
    printf("3. Display Library\n");
    printf("4. Search\n");
    printf("5. Rate Song\n");
    printf("6. Change Password\n");
    printf("7. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void add_song() {
    if (num_songs >= 100) {
        printf("Library is full. Cannot add more songs.\n");
        return;
    }
    Song new_song;
    printf("Enter song title: ");
    scanf("%s", new_song.title);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter year: ");
    scanf("%d", &new_song.year);
    printf("Enter rating (out of 10): ");
    scanf("%d", &new_song.rating);

    songs[num_songs++] = new_song;
    printf("Song added successfully.\n");
}

void remove_song() {
    char title[100];
    printf("Enter song title to remove: ");
    scanf("%s", title);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].title, title) == 0) {
            printf("Song removed successfully.\n");
            found = 1;
            for (int j = i; j < num_songs - 1; j++) {
                songs[j] = songs[j+1];
            }
            num_songs--;
            break;
        }
    }
    if (!found) {
        printf("Song not found.\n");
    }
}

void display_library() {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }
    printf("Library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%s by %s, released in %d, rated %d/10.\n", songs[i].title, songs[i].artist, songs[i].year, songs[i].rating);
    }
}

void search() {
    char input[50];
    printf("Enter search query: ");
    scanf("%s", input);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strstr(songs[i].title, input) || strstr(songs[i].artist, input)) {
            found++;
            printf("%d. %s by %s, released in %d, rated %d/10.\n", found, songs[i].title, songs[i].artist, songs[i].year, songs[i].rating);
        }
    }
    if (!found) {
        printf("No matches found.\n");
    }
}

void rate_song() {
    char title[100];
    printf("Enter song title to rate: ");
    scanf("%s", title);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].title, title) == 0) {
            printf("Enter new rating (out of 10): ");
            scanf("%d", &songs[i].rating);
            printf("Rating updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found.\n");
    }
}

void change_password() {
    printf("Enter current password: ");
    char current[50], new_password[50];
    scanf("%s", current);
    if (strcmp(current, password) != 0) {
        printf("Incorrect password.\n");
        return;
    }
    printf("Enter new password: ");
    scanf("%s", new_password);
    strcpy(password, new_password);
    printf("Password updated successfully.\n");
}