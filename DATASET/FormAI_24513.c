//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand(time(0)); // to generate random number seed with time

    int size = 800;

    char buffer[size][size]; // 2-D char array buffer to store the fractal pattern

    for(int i=0; i<size; i++){ 
        for(int j=0; j<size; j++){

            if(i==size/2 && j==size/2){ // middle of buffer
                buffer[i][j] = '0';
            }
            else{
                buffer[i][j] = '1'; // set the outer elements as black
            }
        }
    }

    int iterations = 10; // number of iterations to generate the fractal

    for(int i=0; i<iterations; i++){ // loop to generate the fractal pattern

        int step_size = pow(2, i); // change in step size with each iteration

        int check_size = step_size/2; 

        for(int x=check_size; x<size; x+=step_size){

            for(int y=check_size; y<size; y+=step_size){

                int random_num = rand()%2; // generate random number 0 or 1

                if(random_num==0){ // if random number is 0 set the elements as black
                    for(int a=x-check_size; a<=x+check_size; a++){

                        for(int b=y-check_size; b<=y+check_size; b++){
                            buffer[a][b] = '0'; // set as black
                        }
                    }
                }
            }
        }
    }

    printf(" ");
    for(int i=0; i<size; i++){
        printf("-");
    }
    printf("\n");

    for(int i=0; i<size; i++){
        printf("|");

        for(int j=0; j<size; j++){
            printf("%c", buffer[i][j]);
        }

        printf("|\n");
    }

    printf(" ");
    for(int i=0; i<size; i++){
        printf("-");
    }
    printf("\n");

    return 0;
}