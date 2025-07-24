//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

//Global variables
int cash = 0;
int card = 0;
int total_sales = 0;

//Function to calculate total sales
void* calculate_sales(void *arg) {
    while(1) {
        total_sales = cash + card;
        printf("Total Sales: %d\n", total_sales);
        sleep(10); //Update sales after every 10 seconds
    }
    return NULL;
}

//Function to handle cash payment
void* cash_payment(void *arg) {
    int amount = *(int*)arg;
    printf("Processing Cash Payment of %d\n", amount);
    sleep(5); //Simulate payment processing time
    cash += amount;
    printf("Cash Payment Processed!\n");
    return NULL;
}

//Function to handle card payment
void* card_payment(void *arg) {
    int amount = *(int*)arg;
    printf("Processing Card Payment of %d\n", amount);
    sleep(2); //Simulate payment processing time
    card += amount;
    printf("Card Payment Processed!\n");
    return NULL;
}

int main() {
    pthread_t tid1, tid2, tid3;
    
    int c1 = 50, c2 = 75, c3 = 100; //Cost of items
    int cash1 = 100, cash2 = 150, cash3 = 200; //Cash received for items
    int card1 = 75, card2 = 100, card3 = 125; //Card payment for items
    
    printf("Welcome to the Cafe Billing System!\n\n");
    
    //Create thread to calculate total sales
    pthread_create(&tid1, NULL, calculate_sales, NULL);
    
    //Create thread to handle cash payment for item 1
    pthread_create(&tid2, NULL, cash_payment, &cash1);
    pthread_join(tid2, NULL); //Wait for thread to finish
    
    //Create thread to handle card payment for item 2
    pthread_create(&tid3, NULL, card_payment, &card2);
    pthread_join(tid3, NULL); //Wait for thread to finish
    
    printf("\nItem\t\tCost\t\tCash\t\tCard\n");
    printf("1\t\t%d\t\t%d\t\t0\n", c1, cash1);
    printf("2\t\t%d\t\t0\t\t%d\n", c2, card2);
    printf("\nTotal Sales: %d\n", total_sales);
    
    //Create thread to handle cash payment for item 3
    pthread_create(&tid2, NULL, cash_payment, &cash3);
    pthread_join(tid2, NULL); //Wait for thread to finish
    
    //Create thread to handle card payment for item 1
    pthread_create(&tid3, NULL, card_payment, &card1);
    pthread_join(tid3, NULL); //Wait for thread to finish
    
    printf("\nItem\t\tCost\t\tCash\t\tCard\n");
    printf("1\t\t%d\t\t%d\t\t%d\n", c1, cash1, card1);
    printf("2\t\t%d\t\t0\t\t%d\n", c2, card2);
    printf("3\t\t%d\t\t%d\t\t0\n", c3, cash3);
    printf("\nTotal Sales: %d\n", total_sales);
    
    return 0;
}