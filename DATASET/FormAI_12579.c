//FormAI DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 100
#define MAX_BIDDERS 50

//Product Structure
typedef struct{
    char name[50];
    float minimum_bid;
    float current_bid;
    int bidder_id;
}Product;

//Bidder Structure
typedef struct{
    char name[50];
    float wallet;
    int products_bought[MAX_PRODUCTS];
}Bidder;

//Function Declarations
void add_product(Product products[], int *num_products);
void remove_product(Product products[], int *num_products);
void list_products(Product products[], int num_products);
void register_bidder(Bidder bidders[], int *num_bidders);
void show_bidders(Bidder bidders[], int num_bidders);
void bid_product(Product products[], int num_products, Bidder bidders[], int bidder_id);
void close_auction(Product products[], int num_products, Bidder bidders[], int num_bidders);

int main(){
    //Initialize Variables
    Product products[MAX_PRODUCTS];
    int num_products = 0;
    Bidder bidders[MAX_BIDDERS];
    int num_bidders = 0;
    int bidder_id = 0;

    int option = 0;
    do{
        //Main Menu
        printf("\nDigital Auction System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. List Products\n");
        printf("4. Register Bidder\n");
        printf("5. Show Bidders\n");
        printf("6. Bid Product\n");
        printf("7. Close Auction\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        //Perform selected operation
        switch(option){
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                remove_product(products, &num_products);
                break;
            case 3:
                list_products(products, num_products);
                break;
            case 4:
                register_bidder(bidders, &num_bidders);
                break;
            case 5:
                show_bidders(bidders, num_bidders);
                break;
            case 6:
                bid_product(products, num_products, bidders, bidder_id);
                bidder_id++;
                break;
            case 7:
                close_auction(products, num_products, bidders, num_bidders);
                break;
            case 0:
                printf("Exiting...");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }while(option != 0);

    return 0;
}

//Function Definitions

//Add new product to the system
void add_product(Product products[], int *num_products){
    //Create new product
    Product new_product;
    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);
    printf("Enter the minimum bid required: ");
    scanf("%f", &new_product.minimum_bid);
    new_product.current_bid = new_product.minimum_bid;
    new_product.bidder_id = -1;

    //Add product to the list
    products[*num_products] = new_product;
    (*num_products)++;
}

//Remove a product from the system
void remove_product(Product products[], int *num_products){
    if(*num_products == 0){
        printf("No products in the system.\n");
    }
    else{
        //Print list of products
        list_products(products, *num_products);

        int product_id;
        printf("Enter the ID of the product you want to remove: ");
        scanf("%d", &product_id);

        if(product_id >= 0 && product_id < *num_products){
            //Shift all products after the removed product one position to the left
            for(int i = product_id; i < (*num_products) - 1; i++){
                products[i] = products[i+1];
            }
            (*num_products)--;
            printf("Product removed.\n");
        }
        else{
            printf("Invalid product ID, please try again.\n");
        }
    }
}

//Show a list of available products in the system
void list_products(Product products[], int num_products){
    if(num_products == 0){
        printf("No products in the system.\n");
    }
    else{
        printf("\nList of Products:\n");
        for(int i = 0; i < num_products; i++){
            printf("%d. %s ($%.2f)\n", i, products[i].name, products[i].current_bid);
        }
    }
}

//Register a new bidder in the system
void register_bidder(Bidder bidders[], int *num_bidders){
    //Create new bidder
    Bidder new_bidder;
    printf("Enter your name: ");
    scanf("%s", new_bidder.name);
    printf("Enter your wallet balance: ");
    scanf("%f", &new_bidder.wallet);

    //Add bidder to the list
    bidders[*num_bidders] = new_bidder;
    (*num_bidders)++;
}

//Print a list of registered bidders in the system
void show_bidders(Bidder bidders[], int num_bidders){
    if(num_bidders == 0){
        printf("No bidders in the system.\n");
    }
    else{
        printf("\nList of Bidders:\n");
        for(int i = 0; i < num_bidders; i++){
            printf("%d. %s (Balance: $%.2f)\n", i, bidders[i].name, bidders[i].wallet);
        }
    }
}

//Bid a product by a bidder
void bid_product(Product products[], int num_products, Bidder bidders[], int bidder_id){
    if(num_products == 0){
        printf("No products in the system.\n");
    }
    else if(bidder_id >= MAX_BIDDERS){
        printf("Maximum number of bidders reached.\n");
    }
    else{
        //Print list of products
        list_products(products, num_products);

        //Enter product ID to bid on
        int product_id;
        printf("Enter the ID of the product you want to bid: ");
        scanf("%d", &product_id);
        if(product_id >= 0 && product_id < num_products){
            //Enter bid amount
            float bid_amount;
            printf("Enter your bid amount: ");
            scanf("%f", &bid_amount);

            //Check if bid is higher than the current bid and bidder has enough balance
            if(bid_amount > products[product_id].current_bid && bid_amount <= bidders[bidder_id].wallet){
                //Update product and bidder information
                products[product_id].current_bid = bid_amount;
                products[product_id].bidder_id = bidder_id;
                bidders[bidder_id].wallet -= bid_amount;
                bidders[bidder_id].products_bought[product_id] = 1;
                printf("Bid accepted.\n");
            }
            else{
                printf("Invalid bid amount.\n");
            }
        }
        else{
            printf("Invalid product ID, please try again.\n");
        }
    }
}

//Close the auction, display results and reset the system for a new auction
void close_auction(Product products[], int num_products, Bidder bidders[], int num_bidders){
    if(num_products == 0){
        printf("No products in the system.\n");
    }
    else{
        int highest_bidder_id;
        float total_earnings = 0.0;

        //Display results for each product
        printf("\nAuction Results:\n");
        for(int i = 0; i < num_products; i++){
            if(products[i].bidder_id == -1){
                printf("%s: No bidders.\n", products[i].name);
            }
            else{
                printf("%s: Highest Bid - $%.2f by %s.\n",
                       products[i].name,
                       products[i].current_bid,
                       bidders[products[i].bidder_id].name);

                //Calculate earnings and add to bidder's wallet
                highest_bidder_id = products[i].bidder_id;
                bidders[highest_bidder_id].wallet += products[i].current_bid;
                total_earnings += products[i].current_bid;
            }
        }

        //Display total earnings and bidder information
        printf("\nTotal Earnings: $%.2f\n", total_earnings);
        printf("\nBidder Information:\n");
        for(int i = 0; i < num_bidders; i++){
            printf("%s: Total Spent - $%.2f, Products Bought - ", bidders[i].name, bidders[i].wallet);
            for(int j = 0; j < num_products; j++){
                if(bidders[i].products_bought[j]){
                    printf("%s, ", products[j].name);
                }
            }
            printf("\n");
        }

        //Reset system for new auction
        for(int i = 0; i < num_products; i++){
            products[i].current_bid = products[i].minimum_bid;
            products[i].bidder_id = -1;
        }
        for(int i = 0; i < num_bidders; i++){
            bidders[i].wallet = 0.0;
            memset(bidders[i].products_bought, 0, sizeof(bidders[i].products_bought));
        }
        printf("\nSystem reset for new auction.\n");
    }
}