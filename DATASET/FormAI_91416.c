//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest {
    char name[20];
    int room_number;
    char check_in_date[12];
    char check_out_date[12];
    int num_of_days;
    float total_cost;
};

int main() {
    int num_of_guests;
    printf("Enter the number of guests: ");
    scanf("%d", &num_of_guests);
    struct guest guests[num_of_guests];

    for(int i=0; i<num_of_guests; i++) {
        printf("\n=== Enter details for guest %d ===\n", i+1);
        printf("Enter name: ");
        scanf("%s", guests[i].name);
        printf("Enter room number: ");
        scanf("%d", &guests[i].room_number);
        printf("Enter check-in date (dd/mm/yyyy): ");
        scanf("%s", guests[i].check_in_date);
        printf("Enter check-out date (dd/mm/yyyy): ");
        scanf("%s", guests[i].check_out_date);
        printf("Enter number of days: ");
        scanf("%d", &guests[i].num_of_days);
        guests[i].total_cost = guests[i].num_of_days * 150; //default cost per day in dollars
    }

    printf("\n=== Guest details ===\n");
    for(int i=0; i<num_of_guests; i++) {
        printf("\nName: %s\nRoom number: %d\nCheck-in date: %s\nCheck-out date: %s\nNumber of days: %d\nTotal cost: $%.2f\n", 
            guests[i].name, guests[i].room_number, guests[i].check_in_date, guests[i].check_out_date, guests[i].num_of_days, guests[i].total_cost);
    }

    return 0;
}