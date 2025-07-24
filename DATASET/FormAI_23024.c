//FormAI DATASET v1.0 Category: Phone Book ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX 50
#define PORT 8888
#define SA struct sockaddr

//Structure for storing contact data
struct contact{
    char name[MAX];
    char number[MAX];
};

//Function prototypes
void add_contact(int sockfd, struct sockaddr_in servaddr);
void search_contact(int sockfd, struct sockaddr_in servaddr);
void delete_contact(int sockfd, struct sockaddr_in servaddr);
void display_contacts(int sockfd, struct sockaddr_in servaddr);

//Driver function
int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    //Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    //Clear the server address structure
    bzero(&servaddr, sizeof(servaddr));

    //Set the server address details
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    //Bind the socket with the server address
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    //Start listening for client requests
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");

    //Accept client requests and serve them
    while(1){
        int len = sizeof(cli);

        connfd = accept(sockfd, (SA*)&cli, &len);
        if (connfd < 0) {
            printf("Server accept failed...\n");
            exit(0);
        }
        else
            printf("Server accepted the client request...\n");

        //Display menu to the client
        char menu[MAX] = "Menu:\n1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. Display Contacts\n5. Exit";
        write(connfd, menu, sizeof(menu));

        //Handle the selected menu option
        int choice;
        read(connfd, &choice, sizeof(int));
        switch(choice){
            case 1: add_contact(connfd, servaddr); break;
            case 2: search_contact(connfd, servaddr); break;
            case 3: delete_contact(connfd, servaddr); break;
            case 4: display_contacts(connfd, servaddr); break;
            default: exit(0);
        }
    }

    //Close the socket
    close(sockfd);
    return 0;
}

//Function to add a contact
void add_contact(int sockfd, struct sockaddr_in servaddr){
    struct contact c;
    read(sockfd, &c, sizeof(struct contact));

    //Open the phone book file
    FILE* fp;
    fp = fopen("phonebook.txt", "a");

    //Add the new contact to the file
    fprintf(fp, "%s %s\n", c.name, c.number);
    printf("Contact added successfully..\n");

    //Close the file and send success message to client
    fclose(fp);
    char success[MAX] = "Contact added successfully..";
    write(sockfd, success, sizeof(success));
}

//Function to search for a contact
void search_contact(int sockfd, struct sockaddr_in servaddr){
    char name[MAX];
    read(sockfd, name, sizeof(name));

    //Open the phone book file for reading
    FILE* fp;
    fp = fopen("phonebook.txt", "r");
    if(fp == NULL){
        char error[MAX] = "Phone book file not found..";
        write(sockfd, error, sizeof(error));
        return;
    }

    //Search for the contact in the file
    int found = 0;
    char line[MAX];
    while(fgets(line, MAX, fp) != NULL){
        char* token = strtok(line, " ");
        if(strcmp(token, name) == 0){
            found = 1;
            break;
        }
    }

    //Close the file and send result to client
    fclose(fp);
    if(found){
        char number[MAX];
        strcpy(number, strtok(NULL, " "));

        char success[MAX] = "Contact found - ";
        strcat(success, number);
        write(sockfd, success, sizeof(success));
    }
    else{
        char error[MAX] = "Contact not found..";
        write(sockfd, error, sizeof(error));
    }
}

//Function to delete a contact
void delete_contact(int sockfd, struct sockaddr_in servaddr){
    char name[MAX];
    read(sockfd, name, sizeof(name));

    //Open the phone book file for reading
    FILE* fp;
    fp = fopen("phonebook.txt", "r+");
    if(fp == NULL){
        char error[MAX] = "Phone book file not found..";
        write(sockfd, error, sizeof(error));
        return;
    }

    //Search for the contact in the file
    int found = 0;
    char line[MAX];
    int len;
    long current_pos;
    while(fgets(line, MAX, fp) != NULL){
        current_pos = ftell(fp);
        len = strlen(line) - 1;
        if(line[len] == '\n') line[len] = '\0';
        char* token = strtok(line, " ");
        if(strcmp(token, name) == 0){
            found = 1;
            break;
        }
    }

    //Delete the contact from the file
    if(found){
        fseek(fp, current_pos - (strlen(line) + 1), SEEK_SET);
        fprintf(fp, "%*s", (int)strlen(line), "");
        printf("Contact deleted successfully..\n");

        //Close the file and send success message
        fclose(fp);
        char success[MAX] = "Contact deleted successfully..";
        write(sockfd, success, sizeof(success));
    }
    else{
        //Close the file and send error message
        fclose(fp);
        char error[MAX] = "Contact not found..";
        write(sockfd, error, sizeof(error));
    }
}

//Function to display all contacts
void display_contacts(int sockfd, struct sockaddr_in servaddr){
    //Open the phone book file for reading
    FILE* fp;
    fp = fopen("phonebook.txt", "r");
    if(fp == NULL){
        char error[MAX] = "Phone book file not found..";
        write(sockfd, error, sizeof(error));
        return;
    }

    //Extract all contact data from the file
    char contacts[MAX*MAX];
    char line[MAX];
    while(fgets(line, MAX, fp) != NULL){
        strcat(contacts, line);
    }

    //Close the file and send the contact data to client
    fclose(fp);
    write(sockfd, contacts, sizeof(contacts));
}