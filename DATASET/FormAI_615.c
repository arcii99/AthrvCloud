//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define UPPER_LIMIT 94

char *generate_password(void);
void randomize_array(char *);
int get_random_number(void);

int main(void){
    char *password = generate_password();
    printf("Your password is: %s\n", password);
    free(password);
    return 0;
}

char *generate_password(void){
    char *password = malloc(sizeof(char) * (PASSWORD_LENGTH + 1));
    char character_set[UPPER_LIMIT] = {'!' ,'\"' ,'#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', 
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
        'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '{', '|', '}', '~'};
    srand(time(NULL));
    randomize_array(character_set);
    for (int i = 0; i < PASSWORD_LENGTH; i++){
        password[i] = character_set[get_random_number()];
    }
    password[PASSWORD_LENGTH] = '\0';
    return password;
}

int get_random_number(void){
    return rand() % UPPER_LIMIT;
}

void randomize_array(char *array){
    for (int i = 0; i < UPPER_LIMIT; i++){
        int random_index = get_random_number();
        char temp = array[i];
        array[i] = array[random_index];
        array[random_index] = temp;
    }
}