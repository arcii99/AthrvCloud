//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client {
    char name[50];
    float balance;
} Client;

Client createClient(char name[], float balance) {
    Client newClient;
    strcpy(newClient.name, name);
    newClient.balance = balance;
    return newClient;
}

void printClient(Client client) {
    printf("Name: %s\nBalance: $%.2f\n", client.name, client.balance);
}

void deposit(Client* client, float amount) {
    client->balance += amount;
    printf("$%.2f deposited, new balance: $%.2f\n", amount, client->balance);
}

void withdraw(Client* client, float amount) {
    if (client->balance >= amount) {
        client->balance -= amount;
        printf("$%.2f withdrawn, new balance: $%.2f\n", amount, client->balance);
    } else {
        printf("Insufficient funds\n");
    }
}

int main() {
    Client client1 = createClient("John Smith", 500.0);
    Client client2 = createClient("Jane Doe", 1000.0);

    printClient(client1);
    deposit(&client1, 200.0);
    withdraw(&client1, 100.0);

    printClient(client2);
    deposit(&client2, 500.0);
    withdraw(&client2, 1500.0);

    return 0;
}