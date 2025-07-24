//FormAI DATASET v1.0 Category: Networking ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define PORT 8080

void display_board(char board[]);
int check_win(char board[]);
int is_full(char board[]);

int main(){

    int sockfd, new_sockfd, read_value;
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    struct sockaddr_in server_addr, client_addr;
    int addrlen=sizeof(client_addr);
    char buffer[1024] = {0};
    char *board_msg = "Please enter a value between 1 and 9 to make your move: ";
    char *win_msg = "You have won the game!";
    char *lose_msg = "Sorry, you have lost the game. Better luck next time!";
    char *tie_msg = "The game ended in a tie!";

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Socket creation error.\n");
        return -1;
    }
    printf("Socket created.\n");

    memset(&server_addr, 0, sizeof(server_addr));

    // Assign IP, Port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Bind error.\n");
        return -1;
    }
    printf("Bind successful.\n");

    // Listen for incoming connections
    if(listen(sockfd, 1) < 0){
        printf("Listen error.\n");
        return -1;
    }
    printf("Waiting for incoming connection...\n");

    // Accept incoming connection
    new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);
    if(new_sockfd < 0){
        printf("Accept error.\n");
        return -1;
    }
    printf("Connection established.\n\n");

    // Game loop
    int player_turn = 1;
    int move;
    char marker;
    int game_status = -1;
    while(game_status == -1){
        display_board(board);

        // Send board display and move prompt to clients
        if(player_turn == 1){
            send(new_sockfd, board, strlen(board), 0);
            send(new_sockfd, board_msg, strlen(board_msg), 0);
            read_value = read(new_sockfd, &move, sizeof(int));
            move--;  // index starts from 0
            marker = 'X';
        }else{
            recv(new_sockfd, buffer, 1024, 0);
            move = buffer[0] - '0' - 1;  // convert ascii to integer, index starts from 0
            marker = 'O';
        }

        // Update board with player's move
        if(board[move] == move + '1'){
            board[move] = marker;
        }else{
            if(player_turn == 1){
                send(new_sockfd, "Invalid move! Please try again.\n", strlen("Invalid move! Please try again.\n"), 0);
            }
            continue;
        }

        // Check for game status
        game_status = check_win(board);

        // Switch to other player's turn
        player_turn = (player_turn == 1) ? 2 : 1;
    }

    // Send game result message to both clients
    if(game_status == 1){
        send(new_sockfd, win_msg, strlen(win_msg), 0);
        recv(new_sockfd, buffer, 1024, 0);
        printf("Player 1 has won the game!\n");
    }else if(game_status == 2){
        send(new_sockfd, lose_msg, strlen(lose_msg), 0);
        printf("Player 2 has won the game!\n");
    }else{
        send(new_sockfd, tie_msg, strlen(tie_msg), 0);
        recv(new_sockfd, buffer, 1024, 0);
        printf("The game has ended in a tie!\n");
    }

    return 0;
}

void display_board(char board[]){
    printf("Tic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("     |     |     \n\n");
}

int check_win(char board[]){
    if(board[0] == board[1] && board[1] == board[2]){
        return board[0] == 'X' ? 1 : 2;
    }
    if(board[3] == board[4] && board[4] == board[5]){
        return board[3] == 'X' ? 1 : 2;
    }
    if(board[6] == board[7] && board[7] == board[8]){
        return board[6] == 'X' ? 1 : 2;
    }
    if(board[0] == board[3] && board[3] == board[6]){
        return board[0] == 'X' ? 1 : 2;
    }
    if(board[1] == board[4] && board[4] == board[7]){
        return board[1] == 'X' ? 1 : 2;
    }
    if(board[2] == board[5] && board[5] == board[8]){
        return board[2] == 'X' ? 1 : 2;
    }
    if(board[0] == board[4] && board[4] == board[8]){
        return board[0] == 'X' ? 1 : 2;
    }
    if(board[2] == board[4] && board[4] == board[6]){
        return board[2] == 'X' ? 1 : 2;
    }
    if(is_full(board)){
        return 0;
    }
    return -1;
}

int is_full(char board[]){
    for(int i=0; i<9; i++){
        if(board[i] != 'X' && board[i] != 'O'){
            return 0;
        }
    }
    return 1;
}