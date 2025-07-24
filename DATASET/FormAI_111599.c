//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include<stdio.h>

int main(){
    printf("Warehouse Management System \n");
    printf("-------------------------- \n");
    printf("Oh my goodness! We forgot to include the inventory list! \n");
    printf("What do we do now? Panic? No way! \n");

    int itemsInStock[5] = {25, 10, 13, 7, 50};
    char itemNames[5][20] = {"Shoes", "Shirts", "Pants", "Hats", "Socks"};

    printf("Alright, we managed to get the inventory list, phew! \n");
    printf("\n");
    printf("Here is our current inventory: \n");

    for(int i=0; i<5; i++){
        printf("%s: %d \n", itemNames[i], itemsInStock[i]);
    }

    printf("\n");
    printf("Looks like we need to restock some items soon! \n");
    printf("\n");
    printf("Let's add some items to our inventory: \n");

    int newItems[5] = {8, 11, 3, 14, 6};

    for(int i=0; i<5; i++){
        itemsInStock[i] += newItems[i];
        printf("%s: %d \n", itemNames[i], itemsInStock[i]);
    }

    printf("\n");
    printf("Phew, that was close! Our warehouse management system saved our day! \n");

    return 0;
}