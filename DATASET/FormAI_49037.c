//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

double celsius, fahrenheit;

void *cel_to_fah(void *arg){
    fahrenheit = (celsius * 9 / 5) + 32;
    pthread_exit(NULL);
}

void *fah_to_cel(void *arg){
    celsius = (fahrenheit - 32) * 5 / 9;
    pthread_exit(NULL);
}

int main(void){
    pthread_t tid1, tid2;
    int choice;
    
    printf("Enter 1 to convert Celsius to Fahrenheit\nEnter 2 to convert Fahrenheit to Celsius\n");
    scanf("%d", &choice);
    
    if(choice==1){
        printf("Enter the temperature in Celsius: ");
        scanf("%lf", &celsius);
        
        pthread_create(&tid1, NULL, cel_to_fah, NULL);
        pthread_join(tid1, NULL);
        
        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
    }
    else if(choice==2){
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%lf", &fahrenheit);

        pthread_create(&tid2, NULL, fah_to_cel, NULL);
        pthread_join(tid2, NULL);
        
        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
    }
    else{
        printf("Invalid choice!\n");
    }
    return 0;
}