#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void create_process() {
    int pid = fork();
    if(pid < 0) {
        printf("fork() failed");
    } else if(pid == 0) {
        // Child process
        printf("Child process created.\n");
        while(1) {
            sleep(1); // Sleep for 1 second
        }
        exit(0); // Child process exits
    } else {
        // Parent process
        printf("Parent process continues.\n");
    }
}


void quit() {
    kill(0, SIGTERM); // Sends SIGTERM to the entire process group
    printf("all processes were terminated.\n");
}

int main() {
  create_process();
  printf("hello\n");
  quit();
    return 0;
}
