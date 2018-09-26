/*Authors: Brandon Williams and Skyler Penna
 *Assignment: PS-1
 *Class: CS 450
 *Date: 9/25/2018
 *File: p1.c
*/
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
