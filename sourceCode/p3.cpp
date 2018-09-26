/*Authors: Brandon Williams and Skyler Penna
 *Assignment: PS-1
 *Class: CS 450
 *Date: 9/25/2018
 *File: p3.cpp
*/

#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std::chrono; 

void emptyFunction() {}
void incrementFunction();
void dynamicFunction(int *p);

static int a = 0;

int main(){


	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	emptyFunction();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2-t1);
	std::cout << "elapsed time for my empty function: " << time_span.count() << " seconds." << std::endl;

	t1 = high_resolution_clock::now();
	incrementFunction();
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2-t1);
	std::cout << "elapsed time for my function to increment a static variable: " << time_span.count() << " seconds." << std::endl;

	t1 = high_resolution_clock::now();
	int *ptr; 
	ptr = new (std::nothrow) int[10];
	if(ptr == nullptr)
		std::cout << "Error: memory could not be allocated";
	dynamicFunction(ptr);
	t2 = high_resolution_clock::now();
	time_span = duration_cast<duration<double>>(t2-t1);
	std::cout << "elapsed time for my function that writes to memory in the heap: " << time_span.count() << " seconds." << std::endl;


	t1 = high_resolution_clock::now();
	getpid();
	t2 = high_resolution_clock::now();

	time_span = duration_cast<duration<double>>(t2-t1);

	std::cout << "elapsed time for syscall: " << time_span.count() << " seconds." << std::endl;

	return 0;
}
void dynamicFunction(int *p){
	for(int i = 0; i < 10; i++){
		p[i] = i*10;
	}	
}
void incrementFunction(){
	a++;
}

/*
There is no syscall or int 0x80 instruction in the corresponding p3.s assembly fileis most likely due to the fact that the every function we are using, including the 
high resolution clock from the Chrono library is being run in user space instead ofdirectly from the kernel. 

The work that each call, for my functions and the syscall must follow are represented by the following steps. 
 1.)make a call
 2.)start a procedure
 3.)depending if it is accessing a global variable, or initializing data in the 
    heap the it might be accessing memory on the heap and completing operations on
    it. 
 4.)it will then make a ret call and end the procedure. 
 5.)the system call has sgnificantly more instructions that it must perform to 
    communicate back and forth with the kernal. 

The user function is anywhere from 3 to 4 times faster than the system call. When
a user function has to access multiple items on the heap and make changes, it slows the function down by a little, but it is still 3 times faster than the system call

*/
