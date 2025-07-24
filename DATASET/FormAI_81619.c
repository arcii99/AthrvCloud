//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int signal_strength = 0;
	printf("Scanning for Wi-Fi signals...\n");
	srand(time(NULL));
	for(int i=0;i<10;i++){
		signal_strength = rand()%101;
		if(signal_strength == 100){
			printf("A perfectly strong Wi-Fi signal has been found!\n");
			break;
		}
		printf("Signal strength: %d\n", signal_strength);
		if(signal_strength > 80){
			printf("This signal is strong enough to connect to.\n");
		}
		else if(signal_strength > 50){
			printf("This signal may work, but may be slow.\n");
		}
		else{
			printf("This signal is too weak to use.\n");
		}
	}
	if(signal_strength != 100){
		printf("\nNo perfect Wi-Fi signal has been found. Please try again later.\n");
	}
	return 0;
}