//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include<stdio.h>

int main(){

int guests, room, i, j, k, bill=0;

printf("Welcome to C Hotel Management System!\n");

printf("Enter number of guests: ");
scanf("%d",&guests);

printf("Enter number of rooms: ");
scanf("%d",&room);

int guests_array[guests],room_array[room];

for(i=0;i<guests;i++){
    printf("Enter number of guests in room %d: ", i+1);
    scanf("%d",&guests_array[i]);
}

for(j=0;j<room;j++){
    printf("Enter room %d occupancy (1 for single room, 2 for double room): ", j+1);
    scanf("%d",&room_array[j]);
}

printf("\nHotel bill for each room:\n");

for(k=0;k<room;k++){
    if(room_array[k]==1){
        bill=1000*guests_array[k];
    }
    else{
        bill=2000*guests_array[k];
    }
    printf("Room %d bill: $%d\n", k+1, bill);
}

return 0;
}