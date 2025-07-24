//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Coordinates {
   double x, y;
};

struct Node {
   struct Coordinates coordinates;
   struct Node* next;
};

void insert(struct Node** headRef, struct Coordinates coordinates) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->coordinates = coordinates;
   newNode->next = (*headRef);
   (*headRef) = newNode;
}

void display(struct Node* head) {
   printf("\n");
   while (head != NULL) {
      printf("%.4f,%.4f -> ", head->coordinates.x, head->coordinates.y);
      head = head->next;
   }
}

int main() {
   srand(time(0));

   int nodes;
   printf("Enter the number of nodes: ");
   scanf("%d", &nodes);

   struct Node* head = NULL;
   struct Coordinates current, previous = {0, 0};
   insert(&head, previous);

   for (int i = 1; i <= nodes; i++) {
      current.x = previous.x + ((double)rand() / RAND_MAX);
      current.y = previous.y + ((double)rand() / RAND_MAX);
      insert(&head, current);
      previous = current;
   }

   display(head);

   double currentX, currentY;
   printf("\nEnter current coordinates (format: x,y): ");
   scanf("%lf,%lf", &currentX, &currentY);

   struct Node* closestNode = head;
   double closestDistance = sqrt(pow(head->coordinates.x - currentX, 2) + pow(head->coordinates.y - currentY, 2));
   while (head != NULL) {
      double distance = sqrt(pow(head->coordinates.x - currentX, 2) + pow(head->coordinates.y - currentY, 2));
      if (distance < closestDistance) {
         closestNode = head;
         closestDistance = distance;
      }
      head = head->next;
   }

   printf("\nThe closest node to current coordinates is: (%.4f,%.4f)\n", closestNode->coordinates.x, closestNode->coordinates.y);

   return 0;
}