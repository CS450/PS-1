#include <unistd.h>
#include <stdio.h>

int staticVar = 0; //a static variable
int main(){
	staticVar = getpid();
	printf("address of main: %p\n",main);
	while(1){
		sleep(20);
		printf("Address: %p; Process ID: %d\n", &staticVar, staticVar);
	}
	
}
