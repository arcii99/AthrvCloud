//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define MAX_BAGS 50

typedef struct{
    int id;
    int flight_no;
} Passenger;

typedef struct{
    int bags[N]; // Max N bags allowed for one passenger
    int num_bags;
} Luggage;

Passenger passengers[MAX_BAGS];
Luggage luggage[MAX_BAGS];

int assign_flight_no(){
    return (rand() % 1000) + 100; // Randomly assign flight numbers
}

void assign_bags(){
    for(int i=0;i<MAX_BAGS;i++){
        int num_bags = rand() % N; // Randomly assign number of bags between 0 and N
        luggage[i].num_bags = num_bags;
        for(int j=0;j<num_bags;j++){
            luggage[i].bags[j] = rand() % 50; // Randomly assign bag weights between 0 and 50 kgs
        }
    }
}

void display_luggage(){
    printf("Passenger\tFlight No.\tBags\n");
    printf("--------------------------------------------------\n");
    for(int i=0;i<MAX_BAGS;i++){
        printf("%d\t\t%d\t\t", passengers[i].id, passengers[i].flight_no);
        for(int j=0;j<luggage[i].num_bags;j++){
            printf("%dkg, ", luggage[i].bags[j]);
        }
        printf("\n");
    }
}

void sort_bags(){
    for(int i=0;i<MAX_BAGS;i++){
        int num_bags = luggage[i].num_bags;
        for(int j=0;j<num_bags-1;j++){
            for(int k=j+1;k<num_bags;k++){
                if(luggage[i].bags[j] > luggage[i].bags[k]){
                    int temp = luggage[i].bags[j];
                    luggage[i].bags[j] = luggage[i].bags[k];
                    luggage[i].bags[k] = temp;
                }
            }
        }
    }
}

int main(){
    srand(time(0)); // Seed the random number generator
    for(int i=0;i<MAX_BAGS;i++){
        passengers[i].id = i+1;
        passengers[i].flight_no = assign_flight_no();
    }
    printf("Before sorting:\n");
    assign_bags();
    display_luggage();
    printf("\nAfter sorting:\n");
    sort_bags();
    display_luggage();
    return 0;
}