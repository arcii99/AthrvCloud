//FormAI DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSZ 27  // maximum shared memory size

int main() {
	char msg[] = "Hello, world!";
	void* shm_ptr;
	int shmid;

	// create a shared memory segment
	if ((shmid = shmget(IPC_PRIVATE, SHMSZ, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	// attach the shared memory segment to the process's address space
	if ((shm_ptr = shmat(shmid, NULL, 0)) == (void *) -1) {
		perror("shmat");
		exit(1);
	}

	// write a message to the shared memory
	strncpy(shm_ptr, msg, SHMSZ);

	// print out the message from the shared memory
	printf("Message from shared memory: %s\n", (char*)shm_ptr);

	// detach the shared memory segment from the process's address space
	if (shmdt(shm_ptr) == -1) {
		perror("shmdt");
		exit(1);
	}

	// delete the shared memory segment
	if (shmctl(shmid, IPC_RMID, NULL) == -1) {
		perror("shmctl");
		exit(1);
	}

	return 0;
}