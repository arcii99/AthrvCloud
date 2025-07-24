//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    int yearPublished;
} Book;

typedef struct {
    char username[20];
    char password[20];
    Book* library[100];
    int numBooks;
} User;

void displayMenu() {
    printf("\nWelcome to My EBook Reader\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. View Catalogue\n");
    printf("4. Exit\n");
}

void login(User* users[], int numUsers) {
    char username[20];
    char password[20];

    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i]->username) == 0 && strcmp(password, users[i]->password) == 0) {
            printf("\nWelcome %s!\n", username);
            displayUserMenu(users[i]);
            return;
        }
    }

    printf("\nInvalid username or password. Please try again.\n");
}

void registerUser(User* users[], int numUsers) {
    char username[20];
    char password[20];

    printf("\nEnter your desired username: ");
    scanf("%s", username);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i]->username) == 0) {
            printf("\nThis username is already taken. Please try again.\n");
            return;
        }
    }

    printf("Enter your desired password: ");
    scanf("%s", password);

    User* newUser = (User*) malloc(sizeof(User));
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->numBooks = 0;
    users[numUsers] = newUser;

    printf("\nRegistration successful!\n");
    displayUserMenu(newUser);
}

void viewCatalogue(Book* catalogue[], int numBooks) {
    printf("\nCatalogue:\n");

    for (int i = 0; i < numBooks; i++) {
        printf("%d. %s by %s (%d)\n", i+1, catalogue[i]->title, catalogue[i]->author, catalogue[i]->yearPublished);
    }
}

void displayUserMenu(User* user) {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. View Library\n");
        printf("2. Add Book\n");
        printf("3. Remove Book\n");
        printf("4. Logout\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewLibrary(user);
                break;
            case 2:
                addBook(user);
                break;
            case 3:
                removeBook(user);
                break;
            case 4:
                printf("\nLogging out %s...\n", user->username);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void viewLibrary(User* user) {
    printf("\n%s's Library:\n", user->username);

    if (user->numBooks == 0) {
        printf("No books in library.\n");
        return;
    }

    for (int i = 0; i < user->numBooks; i++) {
        printf("%d. %s by %s (%d)\n", i+1, user->library[i]->title, user->library[i]->author, user->library[i]->yearPublished);
    }
}

void addBook(User* user) {
    char title[100];
    char author[50];
    int yearPublished;

    if (user->numBooks == 100) {
        printf("\nLibrary is full. Remove a book to add another.\n");
        return;
    }

    printf("\nEnter book title: ");
    scanf(" %[^\n]s", title);
    printf("Enter author name: ");
    scanf(" %[^\n]s", author);
    printf("Enter year published: ");
    scanf("%d", &yearPublished);

    Book* newBook = (Book*) malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->yearPublished = yearPublished;

    user->library[user->numBooks] = newBook;
    user->numBooks++;

    printf("\nBook added to library.\n");
}

void removeBook(User* user) {
    int bookNum;

    if (user->numBooks == 0) {
        printf("\nNo books in library to remove.\n");
        return;
    }

    printf("\nEnter book number to remove: ");
    scanf("%d", &bookNum);

    if (bookNum < 1 || bookNum > user->numBooks) {
        printf("\nInvalid book number. Please try again.\n");
        return;
    }

    free(user->library[bookNum-1]);

    for (int i = bookNum-1; i < user->numBooks-1; i++) {
        user->library[i] = user->library[i+1];
    }

    user->numBooks--;

    printf("\nBook removed from library.\n");
}

int main() {
    Book** catalogue = (Book**) malloc(3 * sizeof(Book*));
    Book* book1 = (Book*) malloc(sizeof(Book));
    Book* book2 = (Book*) malloc(sizeof(Book));
    Book* book3 = (Book*) malloc(sizeof(Book));
    strcpy(book1->title, "The Catcher in the Rye");
    strcpy(book1->author, "J.D. Salinger");
    book1->yearPublished = 1951;
    strcpy(book2->title, "To Kill a Mockingbird");
    strcpy(book2->author, "Harper Lee");
    book2->yearPublished = 1960;
    strcpy(book3->title, "1984");
    strcpy(book3->author, "George Orwell");
    book3->yearPublished = 1949;
    catalogue[0] = book1;
    catalogue[1] = book2;
    catalogue[2] = book3;

    User** users = (User**) malloc(10 * sizeof(User*));
    int numUsers = 0;

    int choice;

    do {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login(users, numUsers);
                break;
            case 2:
                registerUser(users, numUsers);
                numUsers++;
                break;
            case 3:
                viewCatalogue(catalogue, 3);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    for (int i = 0; i < 3; i++) {
        free(catalogue[i]);
    }

    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < users[i]->numBooks; j++) {
            free(users[i]->library[j]);
        }
        free(users[i]);
    }

    free(catalogue);
    free(users);

    return 0;
}