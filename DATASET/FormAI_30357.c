//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct product{

char name[50];
int id;
int price;

};

void print_product(struct product p){

printf("Product ID: %d\n",p.id);
printf("Product Name: %s\n",p.name);
printf("Product Price: %d\n\n",p.price);

}

int main(){

srand(time(NULL));

struct product products[5];

strcpy(products[0].name,"Laptop");
strcpy(products[1].name,"Mobile Phone");
strcpy(products[2].name,"Television");
strcpy(products[3].name,"Digital Camera");
strcpy(products[4].name,"Headphones");

for(int i=0;i<5;i++){

products[i].id=i+1;
products[i].price=rand()%1000;

print_product(products[i]);

}


int max_bid=0;
int max_bid_index=-1;
int total_bids=0;

while(max_bid_index==-1){

int bid=-1;

while(bid==-1){

printf("Enter your bid: ");
scanf("%d",&bid);

if(bid<=max_bid){
    printf("You must bid a higher amount than the current highest bid of %d\n",max_bid);
    bid=-1;
}
else{
    max_bid=bid;
    max_bid_index=rand()%5;
    printf("You are currently the highest bidder on: "); 
    print_product(products[max_bid_index]);
    printf("Your bid: %d\n\n",max_bid);
    total_bids++;
}

}

}

printf("Auction over!\nTotal bids: %d\n",total_bids);
printf("Highest bidder on product no. %d: \n",products[max_bid_index].id);
print_product(products[max_bid_index]);

return 0;

}