//FormAI DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {

int a,b,result1,result2,result3,result4;

printf("Enter the first number: ");
scanf("%d", &a);

printf("Enter the second number: ");
scanf("%d", &b);

result1 = a + b;
result2 = a - b;
result3 = a * b;
result4 = a / b;

if((result1 > result2) && (result1 > result3) && (result1 > result4)) {
    printf("\nResult of operation %d + %d is: %d which is the largest.\n", a, b, result1);
}
else if((result2 > result1) && (result2 > result3) && (result2 > result4)) {
    printf("\nResult of operation %d - %d is: %d which is the largest.\n", a, b, result2);
}
else if((result3 > result1) && (result3 > result2) && (result3 > result4)) {
    printf("\nResult of operation %d * %d is: %d which is the largest.\n", a, b, result3);
}
else if((result4 > result1) && (result4 > result2) && (result4 > result3)) {
    printf("\nResult of operation %d / %d is: %d which is the largest.\n", a, b, result4);
}
else {
    printf("\nThere is no largest result since two or more results are equal.\n");
}

return 0;
}