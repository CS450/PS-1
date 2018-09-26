/*
Authors: Brandon Williams and Skyler Penna
CS450-Problemset 1 #2:
What: This program sets an alarm and exits after 3 seconds.
Why: The signal is called in main using SIGALRM, and alarm_handler as its types.
the alarm_handler is set to = 1 in the alarm_handler function.  Then alarm() is called with the value
3 so that the alarm is signalled after 3 seconds.
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* The signal handler isn't allowed to do anything except
    * access this variable and re-invoke signal().
     */
volatile sig_atomic_t alarm_flag = 0;

/* Prototype for signal handler */
void alarm_handler (int sig);

int main (void) {
  // Call signal() to set up a handler for SIGALRM
    signal(SIGALRM, alarm_handler);

  // Call alarm() to have the alarm go off in a few seconds
    alarm(3);

    while (!alarm_flag) {
        puts("Waiting for an alarm");
    }
    printf("done\n");
    return 0;
}

void alarm_handler(int sig) {
    alarm_flag = 1;
}

