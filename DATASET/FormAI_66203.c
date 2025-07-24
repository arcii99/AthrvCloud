//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include<stdio.h>
#include<string.h>
//A function to encrypt the message
void encrypt(char message[]){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] += 3; //Moving each letter three steps forward in ASCII 
    }   
}
//A function to decrypt the encrypted message
void decrypt(char message[]){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] -= 3; //Moving each letter three steps backward in ASCII
    }   
}
int main(){
    int choice, i, num_players, sender, receiver;
    char message[100], players[50][20], temp[20];
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    //Code to get player names
    printf("Enter the player names:\n");
    for(i = 0; i < num_players; i++){
        scanf("%s", players[i]);
    }
    printf("Enter the sender ID: ");
    scanf("%d", &sender);
    printf("Enter the receiver ID: ");
    scanf("%d", &receiver);
    printf("Enter the message: ");
    scanf(" %[^\n]s", message);
    encrypt(message); //Encrypting the message
    //Code to send the message to the receiver
    printf("%s sent message '%s' to %s\n", players[sender-1], message, players[receiver-1]);
    decrypt(message); //Decrypting the message
    //Code to receive the message by the receiver
    printf("%s received message '%s' from %s\n", players[receiver-1], message, players[sender-1]);
    return 0;
}