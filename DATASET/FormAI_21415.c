//FormAI DATASET v1.0 Category: Stock market tracker ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_STOCKS 5
#define MIN_STOCKS 3

typedef struct{
    char company_name[25];
    float stock_price;
    int stock_quantity;
    float total_value;
}Stock;

int main(){
    srand((unsigned) time(NULL));
    int n = rand() % (MAX_STOCKS - MIN_STOCKS + 1) + MIN_STOCKS; //Generating random number of stocks
    Stock stocks[n];
    
    //Initializing stocks
    for(int i=0; i<n; i++){
        printf("Enter the name of company: ");
        scanf("%s", &stocks[i].company_name);
        printf("Enter the current stock price: ");
        scanf("%f", &stocks[i].stock_price);
        printf("Enter the current quantity of stocks: ");
        scanf("%d", &stocks[i].stock_quantity);
        stocks[i].total_value = stocks[i].stock_price * stocks[i].stock_quantity;
        printf("\n\n");
    }
    
    //Displaying stocks
    printf("Details of %d stocks:\n\n", n);
    printf("Company Name\tStock Price\tStock Quantity\tTotal Value\n");
    for(int i=0; i<n; i++){
        printf("%s\t\t%f\t%d\t\t%f\n", stocks[i].company_name, stocks[i].stock_price, stocks[i].stock_quantity, stocks[i].total_value);
    }
    printf("\n\n");

    int option;
    do{
        printf("Enter 1 to view the total value of stocks.\n");
        printf("Enter 2 to view the company with highest stock value.\n");
        printf("Enter 3 to view the company with lowest stock value.\n");
        printf("Enter 4 to exit.\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                //Calculating total value of all stocks
                float total_value = 0;
                for(int i=0; i<n; i++){
                    total_value += stocks[i].total_value;
                }
                printf("Total value of all stocks: %f\n\n", total_value);
                break;

            case 2:
                //Finding company with highest stock value
                int highest_index = 0;
                for(int i=1; i<n; i++){
                    if(stocks[i].total_value > stocks[highest_index].total_value){
                        highest_index = i;
                    }
                }
                printf("Company with highest stock value:\n");
                printf("Company Name\tStock Price\tStock Quantity\tTotal Value\n");
                printf("%s\t\t%f\t%d\t\t%f\n\n", stocks[highest_index].company_name, stocks[highest_index].stock_price, stocks[highest_index].stock_quantity, stocks[highest_index].total_value);
                break;

            case 3:
                //Finding company with lowest stock value
                int lowest_index = 0;
                for(int i=1; i<n; i++){
                    if(stocks[i].total_value < stocks[lowest_index].total_value){
                        lowest_index = i;
                    }
                }
                printf("Company with lowest stock value:\n");
                printf("Company Name\tStock Price\tStock Quantity\tTotal Value\n");
                printf("%s\t\t%f\t%d\t\t%f\n\n", stocks[lowest_index].company_name, stocks[lowest_index].stock_price, stocks[lowest_index].stock_quantity, stocks[lowest_index].total_value);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);
            
            default:
                printf("Invalid option.\n\n");
        }
    }while(option != 4);

    return 0;
}