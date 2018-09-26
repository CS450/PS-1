#include <iostream>
#include <chrono>
#include <unistd.h>
#include <sys/time.h>
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
    struct timeval time;
    gettimeofday(&time, NULL);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2-t1);
    std::cout << "elapsed time for gettimeofday() using vDSO: " << time_span.count() << " seconds." << std::endl;

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

    
