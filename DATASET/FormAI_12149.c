//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CLIENTS 10
#define MAX_PRODUCTS 20
#define MAX_NAME_LENGTH 20

typedef struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    int stock;
} Product;

typedef struct Client {
    int id;
    char name[MAX_NAME_LENGTH];
    int balance;
    Product cart[MAX_PRODUCTS];
} Client;

typedef struct Warehouse {
    Product products[MAX_PRODUCTS];
    int products_count;
} Warehouse;

typedef struct GameState {
    Warehouse warehouse;
    Client clients[MAX_CLIENTS];
    int clients_count;
} GameState;

void add_product_to_warehouse(GameState* state, char* name, int stock) {
    int id = state->warehouse.products_count;
    Product new_product = {id, "", stock};
    strcpy(new_product.name, name);
    state->warehouse.products[id] = new_product;
    state->warehouse.products_count++;
}

void add_client(GameState* state, char* name, int balance) {
    int id = state->clients_count;
    Client new_client = {id, "", balance};
    strcpy(new_client.name, name);
    state->clients[id] = new_client;
    state->clients_count++;
}

void print_products(Warehouse* warehouse) {
    printf("Products in warehouse:\n");
    for (int i = 0; i < warehouse->products_count; i++) {
        printf("%d: %s - %d\n", warehouse->products[i].id, warehouse->products[i].name, warehouse->products[i].stock);
    }
    printf("\n");
}

void print_client_cart(Client* client) {
    printf("Products in %s's cart:\n", client->name);
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (client->cart[i].stock > 0) {
            printf("%s - %d\n", client->cart[i].name, client->cart[i].stock);
        }
    }
    printf("\n");
}

void print_clients(Client* clients, int clients_count) {
    printf("Registered clients:\n");
    for (int i = 0; i < clients_count; i++) {
        printf("%d: %s - balance: %d\n", clients[i].id, clients[i].name, clients[i].balance);
    }
    printf("\n");
}

int main() {
    GameState game_state = {
        .warehouse = {
            .products_count = 0,
        },
        .clients_count = 0,
    };

    add_product_to_warehouse(&game_state, "apple", 10);
    add_product_to_warehouse(&game_state, "banana", 20);
    add_product_to_warehouse(&game_state, "orange", 15);

    add_client(&game_state, "Alice", 100);
    add_client(&game_state, "Bob", 50);

    printf("Welcome to Warehouse Manager!\n");
    printf("-----------------------------\n");

    while (1) {
        int option;
        printf("Choose an option:\n");
        printf("1. See products in warehouse\n");
        printf("2. See items in my cart\n");
        printf("3. Add item to cart\n");
        printf("4. Remove item from cart\n");
        printf("5. Buy items in cart\n");
        printf("6. Exit\n");
        scanf("%d", &option);

        if (option == 1) {
            print_products(&game_state.warehouse);
        } else if (option == 2) {
            print_clients(game_state.clients, game_state.clients_count);
            int client_id;
            printf("Choose a client (by ID):\n");
            scanf("%d", &client_id);
            print_client_cart(&game_state.clients[client_id]);
        } else if (option == 3) {
            print_products(&game_state.warehouse);
            int product_id;
            printf("Choose a product (by ID):\n");
            scanf("%d", &product_id);
            int client_id;
            printf("Choose a client (by ID):\n");
            scanf("%d", &client_id);
            int amount;
            printf("Choose amount to add to cart:\n");
            scanf("%d", &amount);
            if (game_state.warehouse.products[product_id].stock >= amount) {
                game_state.clients[client_id].cart[product_id].id = product_id;
                strcpy(game_state.clients[client_id].cart[product_id].name, game_state.warehouse.products[product_id].name);
                game_state.clients[client_id].cart[product_id].stock += amount;
                game_state.warehouse.products[product_id].stock -= amount;
                printf("%d %s added to %s's cart.\n", amount, game_state.warehouse.products[product_id].name, game_state.clients[client_id].name);
            } else {
                printf("Not enough stock.\n");
            }
        } else if (option == 4) {
            print_clients(game_state.clients, game_state.clients_count);
            int client_id;
            printf("Choose a client (by ID):\n");
            scanf("%d", &client_id);
            print_client_cart(&game_state.clients[client_id]);
            int product_id;
            printf("Choose a product (by ID):\n");
            scanf("%d", &product_id);
            if (game_state.clients[client_id].cart[product_id].stock > 0) {
                game_state.warehouse.products[product_id].stock += game_state.clients[client_id].cart[product_id].stock;
                game_state.clients[client_id].cart[product_id].stock = 0;
                printf("%s removed from %s's cart.\n", game_state.warehouse.products[product_id].name, game_state.clients[client_id].name);
            } else {
                printf("No such product in cart.\n");
            }
        } else if (option == 5) {
            print_clients(game_state.clients, game_state.clients_count);
            int client_id;
            printf("Choose a client (by ID):\n");
            scanf("%d", &client_id);
            Client* client = &game_state.clients[client_id];
            int total_cost = 0;
            for (int i = 0; i < MAX_PRODUCTS; i++) {
                if (client->cart[i].stock > 0) {
                    total_cost += client->cart[i].stock * 10;
                }
            }
            if (client->balance >= total_cost) {
                client->balance -= total_cost;
                for (int i = 0; i < MAX_PRODUCTS; i++) {
                    if (client->cart[i].stock > 0) {
                        game_state.warehouse.products[i].stock += client->cart[i].stock;
                        client->cart[i].stock = 0;
                    }
                }
                printf("Bought products for %d dollars. New balance: %d.\n", total_cost, client->balance);
            } else {
                printf("Not enough money!\n");
            }
        } else if (option == 6) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}