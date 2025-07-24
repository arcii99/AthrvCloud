//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int width, height, i, j, color;
    srand(time(NULL));
    
    printf("Enter the width of pixel art: ");
    scanf("%d", &width);
    
    printf("Enter the height of pixel art: ");
    scanf("%d", &height);
    
    printf("\n");
    
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            color = rand() % 16; // generating a random number between 0 to 15
            switch(color)
            {
                case 0: printf("█"); break;
                case 1: printf("░"); break;
                case 2: printf("▒"); break;
                case 3: printf("▓"); break;
                case 4: printf("▔"); break;
                case 5: printf("▕"); break;
                case 6: printf("▖"); break;
                case 7: printf("▗"); break;
                case 8: printf("▘"); break;
                case 9: printf("▙"); break;
                case 10: printf("▚"); break;
                case 11: printf("▛"); break;
                case 12: printf("▜"); break;
                case 13: printf("▝"); break;
                case 14: printf("▞"); break;
                case 15: printf("▟"); break;
                
                default: printf(" "); break;
            }
        }
        printf("\n");
    }
    
    return 0;
}