//FormAI DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>

#define SIZE 4096
#define SHM_NAME "/myshm"
#define SEM_NAME "/mysem"

int current_pos = 0;
char* binary_char = NULL;
sem_t* semaphore_ptr = NULL;

void binary_converter(int decimal_num) {
    sem_wait(semaphore_ptr);
    if (current_pos + 8 > SIZE) {
        printf("Shared memory is full!\n");
    } else {
        for (int i = 7; i >= 0; i--) {
            binary_char[current_pos++] = decimal_num >> i & 1 ? '1' : '0';
        }
    }
    sem_post(semaphore_ptr);
}

int main() {
    int fd_shm;
    char* str;
    sem_unlink(SEM_NAME);
    fd_shm = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0600);

    if (fd_shm < 0) {
        printf("Failed to open shared memory!\n");
        exit(-1);
    }

    if (ftruncate(fd_shm, SIZE) != 0) {
        printf("Failed to truncate shared memory!\n");
        exit(-1);
    }

    str = (char*) mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd_shm, 0);
    if (str == MAP_FAILED) {
        printf("Failed to map shared memory!\n");
        exit(-1);
    }

    semaphore_ptr = sem_open(SEM_NAME, O_CREAT, 0600, 1);
    if (semaphore_ptr == SEM_FAILED) {
        printf("Failed to open semaphore!\n");
        exit(-1);
    }

    binary_char = str;
    int test_cases, decimal_num;
    printf("Enter the number of decimal numbers you want to convert: ");
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        printf("Enter a decimal number: ");
        scanf("%d", &decimal_num);
        binary_converter(decimal_num);
    }

    printf("\nBinary representation of all decimal numbers in shared memory:\n\n");

    for (int i = 0; i < current_pos; i++) {
        putchar(binary_char[i]);
        if ((i + 1) % 8 == 0) {
            printf(" ");
        }
    }

    putchar('\n');

    if (munmap(str, SIZE) != 0) {
        printf("Failed to unmap shared memory!\n");
    }

    if (shm_unlink(SHM_NAME) != 0) {
        printf("Failed to unlink shared memory!\n");
    }

    if (sem_close(semaphore_ptr) != 0) {
        printf("Failed to close semaphore!\n");
    }

    if (sem_unlink(SEM_NAME) != 0) {
        printf("Failed to unlink semaphore!\n");
    }

    return 0;
}