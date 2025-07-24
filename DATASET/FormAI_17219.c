//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int fortune_num = rand() % 8;
  
    printf("Welcome to the automated fortune teller!\n");
    
    switch(fortune_num) {
        case 0:
            printf("You will meet someone special in the near future.\n");
            break;
        case 1:
            printf("Your hard work will pay off soon!\n");
            break;
        case 2:
            printf("Be cautious of new opportunities that seem too good to be true.\n");
            break;
        case 3:
            printf("Your creativity will help you solve a difficult problem.\n");
            break;
        case 4:
            printf("Travel is in your future. Embrace it.\n");
            break;
        case 5:
            printf("A loved one will surprise you with a thoughtful gesture.\n");
            break;
        case 6:
            printf("You will be presented with a life-changing decision soon. Choose wisely.\n");
            break;
        case 7:
            printf("Generosity will bring you good fortune in the future.\n");
            break;
        default:
            printf("Error: Invalid input.\n");
            break;     
    }
  
    return 0;
}