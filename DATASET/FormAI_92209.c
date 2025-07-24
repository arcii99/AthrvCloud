//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netinet/in.h>

#define PORT 8080
#define MAX 1024

typedef struct candidate{
    char name[20];
    int votes;
}candidate;

void addCandidate(candidate *candidates, int num);
void listCandidates(candidate *candidates, int num);
void vote(char *name, candidate *candidates, int num);
void getResults(candidate *candidates, int num);

int main(){
    int server_socket, new_socket, read_val, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    candidate candidates[50];
    int numCandidates;

    //initialize all candidates with 0 votes
    memset(candidates, 0, sizeof(candidates));

    //create socket
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //attach socket to port 8080
    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    //bind the socket to port 8080
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //listen for connections
    if(listen(server_socket, 3) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    while(1){
        int client_len = sizeof(client_addr);
        if((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&client_len)) < 0){
            perror("accept");
            exit(EXIT_FAILURE);
        }

        //display connection info
        printf("Client %s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //send menu to client
        char *menu = "1. Add Candidate\n2. List Candidates\n3. Vote\n4. Get Results\n5. Exit\nEnter Choice: ";
        send(new_socket, menu, strlen(menu), 0);

        //receive client choice
        char buffer[MAX] = {0};
        read_val = read(new_socket, buffer, sizeof(buffer));
        int choice = atoi(buffer);

        if(choice == 1){
            //add a candidate
            addCandidate(candidates, numCandidates);
            numCandidates++;
            send(new_socket, "Candidate added\n", strlen("Candidate added\n"), 0);
        }
        else if(choice == 2){
            //list all candidates
            listCandidates(candidates, numCandidates);
            send(new_socket, "", strlen(""), 0);
        }
        else if(choice == 3){
            //vote for a candidate
            char name[20];
            read_val = read(new_socket, name, sizeof(name));
            vote(name, candidates, numCandidates);
            send(new_socket, "Vote recorded\n", strlen("Vote recorded\n"), 0);
        }
        else if(choice == 4){
            //display election results
            getResults(candidates, numCandidates);
            send(new_socket, "", strlen(""), 0);
        }
        else if(choice == 5){
            //exit the program
            break;
        }
        else{
            //invalid choice
            send(new_socket, "Invalid choice\n", strlen("Invalid choice\n"), 0);
        }

        close(new_socket);
    }

    close(server_socket);
    return 0;
}

void addCandidate(candidate *candidates, int num){
    char name[20];
    printf("Enter candidate name: ");
    scanf("%s", name);
    strcpy(candidates[num].name, name);
}

void listCandidates(candidate *candidates, int num){
    printf("Candidates:\n");
    for(int i=0; i<num; i++){
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void vote(char *name, candidate *candidates, int num){
    for(int i=0; i<num; i++){
       if(strcmp(name, candidates[i].name) == 0){
           candidates[i].votes++;
           break;
       }
    }
}

void getResults(candidate *candidates, int num){
    printf("Results:\n");
    for(int i=0; i<num; i++){
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}