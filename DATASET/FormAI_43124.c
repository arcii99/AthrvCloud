//FormAI DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

struct stock{
    char name[50];
    float price;
    int quantity;
};

void printStock(struct stock st){
    printf("\nName: %s\nPrice per share: %.02f\nQuantity: %d\n", st.name, st.price, st.quantity);
}

void printPortfolio(struct stock portfolio[], int size){
    printf("--------- Portfolio Summary ---------\n");
    float totalValue = 0;
    for(int i=0; i<size; i++){
        printStock(portfolio[i]);
        float value = portfolio[i].price * portfolio[i].quantity;
        printf("Total Value: %.02f\n", value);
        totalValue += value;
    }
    printf("Total Portfolio Value: %.02f\n\n", totalValue);
}

void updateStock(struct stock *st, float price, int quantity){
    st->price = price;
    st->quantity = quantity;
}

int main(){
    struct stock apple = {"AAPL", 120.00, 100};
    struct stock microsoft = {"MSFT", 250.00, 50};
    struct stock tesla = {"TSLA", 850.00, 25};

    struct stock portfolio[] = {apple, microsoft, tesla};
    int size = sizeof(portfolio)/sizeof(portfolio[0]);

    printPortfolio(portfolio, size);

    printf("Updating prices and quantities...\n");
    updateStock(&apple, 125.00, 75);
    updateStock(&microsoft, 260.00, 100);
    updateStock(&tesla, 900.00, 10);

    printPortfolio(portfolio, size);

    return 0;
}