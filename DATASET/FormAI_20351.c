//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

float get_price_change() { 
    return (float) (rand() % 101 - 50) / 100.0; 
} 

int main() { 
    srand(time(NULL)); 
    
    float current_price = 100.0; 
    float price_change = get_price_change(); 
    
    printf("Starting price: $%.2f\n", current_price); 
    
    for (int i = 0; i < 10; i++) { 
        current_price += price_change; 
        
        printf("\nDay %d: ", i+1); 
        if (price_change > 0) {
            printf("$%.2f (+%.2f%%)\n", current_price, price_change*100); 
        } else {
            printf("$%.2f (%.2f%%)\n", current_price, price_change*100); 
        }
        
        price_change = get_price_change(); 
    } 
    
    return 0; 
}