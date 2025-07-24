//FormAI DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include<stdio.h>
#include<string.h>

struct guest {
  char name[50];
  int room_num;
  int check_in_date;
  int check_out_date;
};

void display(struct guest g) {
  printf("\nGuest Name: %s", g.name);
  printf("\nRoom Number: %d", g.room_num);
  printf("\nCheck-in date: %d", g.check_in_date);
  printf("\nCheck-out date: %d\n", g.check_out_date);
}

int main() {
  struct guest g[10];
  int n, i;
  printf("Welcome to C Hotel Management System!\n");
  printf("\nEnter the number of guests: ");
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    printf("\n\nEnter details of guest %d:\n", i+1);
    printf("Name: ");
    scanf("%s", g[i].name);
    printf("Room Number: ");
    scanf("%d", &g[i].room_num);
    printf("Check-in date: ");
    scanf("%d", &g[i].check_in_date);
    printf("Check-out date: ");
    scanf("%d", &g[i].check_out_date);
  }
  printf("\n\nGuest details:\n");
  for(i = 0; i < n; i++) {
    display(g[i]);
  }
  return 0;
}