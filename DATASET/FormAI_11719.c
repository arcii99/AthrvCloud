//FormAI DATASET v1.0 Category: Memory management ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

void* myMalloc(unsigned int size){
    void *temp = malloc(size + sizeof(unsigned int)); // alloco la memoria richiesta e in più 4 byte per contenere la grandezza della memoria allocata
    unsigned int *tempSize = (unsigned int*)temp; // cast del puntatore a unsigned int
    *tempSize = size; // salvo la grandezza della memoria allocata all'interno dei primi 4 byte
    return (void*)(tempSize+1); // ritorno il puntatore alla memoria disponibile per l'utilizzatore
}

void myFree(void* ptr){
    unsigned int *tempSize = (unsigned int*)ptr - 1; // cast al puntatore ai primi 4 byte contenenti la grandezza della memoria
    free((void*)tempSize); // libero il puntatore iniziale restituito dalla malloc
}

int main(){
    int n;
    printf("Enter the size of the array you want: ");
    scanf("%d", &n);

    // Utilizzo della funzione myMalloc
    int *arr = (int*)myMalloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
        arr[i] = i+1;

    // Utilizzo della funzione myFree
    myFree((void*)arr);
    return 0;
}