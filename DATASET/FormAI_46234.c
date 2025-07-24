//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4   // Number of threads considered in the program

// Structure for passing arguments to the thread function
typedef struct{
    int i;  // row
    int j;  // column
} args;

// The periodic table, array of arrays
char elements[7][18] = {
    {' ','H',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'},
    {' ','L','i','B','e',' ',' ',' ',' ',' ',' ','N','a','M','g',' ',' ','\0'},
    {'B','e','C',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','A','l','S','i'},
    {' ',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'},
    {' ',' ','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'},
    {' ','F',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'},
    {' ','N','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'}
};

// Thread function - checks if the specified element exists in row i
void* check_row(void* arg){
    args* input = (args*) arg;
    int i = input -> i;
    int j = input -> j;
    char element = elements[i][j];
    int found = 0;
    for(int k = 0; k < 18; k++){
        if(elements[i][k] == element && k != j){
            found = 1;
            break;
        }
    }
    if(found) printf("%c is found in row %d\n", element, i+1);
    pthread_exit(NULL);
}

// Main function creates threads to check elements in rows and columns
int main(){
    pthread_t threads[NUM_THREADS];
    int rc;
    args arg_arr[NUM_THREADS] = {{0,1}, {1,2}, {2,0}, {5,1}};  // Array of arguments to pass to thread functions
    for(int i = 0; i < NUM_THREADS; i++){
        rc = pthread_create(&threads[i], NULL, check_row, &arg_arr[i]);  // Create thread for each given argument
        if(rc){
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);   // Wait for threads to complete
    }
    return 0;
}