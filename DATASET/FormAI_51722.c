//FormAI DATASET v1.0 Category: Computer Biology ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Protein {
    char name[50];
    int length;
    float weight;
};

typedef struct Protein Protein;

void printProtein(Protein *p) {
    printf("Name: %s\n", p->name);
    printf("Length: %d\n", p->length);
    printf("Weight: %.2f\n", p->weight);
}

int main() {
    Protein *p1, *p2;
    p1 = (Protein *) malloc(sizeof(Protein));
    p2 = (Protein *) malloc(sizeof(Protein));

    strcpy(p1->name, "Myoglobin");
    p1->length = 153;
    p1->weight = 16953.70;

    strncpy(p2->name, "Hemoglobin", 50);
    p2->length = 146;
    p2->weight = 15818.00;

    printProtein(p1);
    printf("\n");
    printProtein(p2);

    free(p1);
    free(p2);

    return 0;
}