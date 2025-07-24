//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/hdreg.h>
#include <pthread.h>

void *initialize_devices(void *arg) {
    int fd = open("/dev/hda", O_RDONLY);
    if(fd == -1) {
        perror("Error opening device file");
        exit(EXIT_FAILURE);
    }
    ioctl(fd, HDIO_GET_IDENTITY, 0);
    close(fd);
    return NULL;
}

int main() {
    pthread_t thread_id;
    int rc = pthread_create(&thread_id, NULL, initialize_devices, NULL);
    if(rc) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }
    // Continue with the boot process
    printf("System booting...\n");
    pthread_join(thread_id, NULL);
    printf("Device initialization complete.\n");
    return 0;
}