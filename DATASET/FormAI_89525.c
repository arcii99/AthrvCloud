//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define MAX_INPUT_LENGTH 100

char input[MAX_INPUT_LENGTH];
int position;
double memory;
double result;

void skip_spaces() {
    while (input[position] == ' ') {
        position++;
    }
}

void parse_number() {
    skip_spaces();
    int length = 0;
    while (input[position] >= '0' && input[position] <= '9' || input[position] == '.') {
        input[length] = input[position];
        position++;
        length++;
    }
    input[length] = '\0';
    result = atof(input);
}

void clear_memory() {
    memory = 0;
}

void add_to_memory() {
    memory += result;
}

void subtract_from_memory() {
    memory -= result;
}

void multiply_with_memory() {
    memory *= result;
}

void divide_memory() {
    if (result == 0) {
        printf("Error: Division by zero\n");
    } else {
        memory /= result;
    }
}

void exponentiate() {
    memory = pow(memory, result);
}

void calculate_sin() {
    memory = sin(result);
}

void calculate_cos() {
    memory = cos(result);
}

void calculate_tan() {
    memory = tan(result);
}

void calculate_asin() {
    memory = asin(result);
}

void calculate_acos() {
    memory = acos(result);
}

void calculate_atan() {
    memory = atan(result);
}

void calculate_sqrt() {
    memory = sqrt(result);
}

void calculate_log() {
    memory = log(result);
}

void calculate_floor() {
    memory = floor(result);
}

void calculate_ceil() {
    memory = ceil(result);
}

void print_result() {
    printf("%f\n", memory);
}

void process_operation(char operation) {
    switch (operation) {
        case 'c':
            clear_memory();
            break;
        case 'm':
            add_to_memory();
            break;
        case 's':
            subtract_from_memory();
            break;
        case 'x':
            multiply_with_memory();
            break;
        case '/':
            divide_memory();
            break;
        case '^':
            exponentiate();
            break;
        case 'n':
            calculate_sin();
            break;
        case 'o':
            calculate_cos();
            break;
        case 'a':
            calculate_tan();
            break;
        case 'i':
            calculate_asin();
            break;
        case 'j':
            calculate_acos();
            break;
        case 'k':
            calculate_atan();
            break;
        case 'q':
            calculate_sqrt();
            break;
        case 'l':
            calculate_log();
            break;
        case 'f':
            calculate_floor();
            break;
        case 'e':
            calculate_ceil();
            break;
        default:
            printf("Error: Invalid operation\n");
            break;
    }
}

void prompt_user() {
    printf("Enter an operation and a operand: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
}

void process_user_input() {
    position = 0;
    skip_spaces();
    process_operation(input[position]);
    position++;
    parse_number();
}

int main() {
    while (1) {
        prompt_user();
        process_user_input();
        print_result();
    }
    return 0;
}