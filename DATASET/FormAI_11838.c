//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, x2, y2, distance;
    printf("Mr. Holmes, we have a case where a dead body was found in a field. Could you please help us determine the distance between the body and a particular tree that may hold valuable evidence?\n");

    printf("Can you kindly provide me with the x and y coordinates of the body on the field?\n");
    scanf("%f %f", &x1, &y1);
    printf("And what about the x and y coordinates of the tree in question?\n");
    scanf("%f %f", &x2, &y2);

    distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    printf("Thank you, Dr. Watson. Our distance calculations have led us to a distance of %.2f units between the body and the tree. Let's proceed to investigate.\n", distance);
    return 0;
}