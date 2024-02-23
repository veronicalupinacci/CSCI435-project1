/*
 * File: project_interface.c
 * The program, once executed, should print user interface with 4 choices and
 * let user interact by entering an integer. Each number (1-4) triggers a unique
 * action. After completing the action, the program displays the same menu
 * again. CSCI435
 *
 *Authors: Miled Kalbourji, Veronica Lupinacci, Rebekah Watrous
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>

bool quit;
pid_t pid;

// Functions:

pid_t create_process() {
  pid = fork();
  if (pid < 0) {
    printf("fork() failed");
    return -1;  // Return -1 to indicate failure
  } else if (pid == 0) {
    // Child process
    while (1) {
      sleep(100);  // Sleep for 1 second
    }
    exit(0);  // Child process exits
  } else {
    // Parent process
    printf("Parent process continues.\n");
  }
  return pid;  // Return the PID of the child process
}

void terminate_process(int pid) {
  if (kill(pid, SIGKILL) == 0) {
    printf("Process with PID %d terminated.\n", pid);
  } else {
    perror("Error while terminating process");
  }
}

void print_active_processes() {
  printf("Active Processes:\n");
  system("ps -eo pid");
}

bool quit_all() {
  kill(0, SIGTERM);  // Sends SIGTERM to the entire process group
  return true;
}

int main() {
  quit = false;
  // Print interface
  while (quit == false) {
    printf(
        "1. Create a new process\n2. Terminate a process\n3. Print active "
        "processes\n4. Quit\nYour choice (1-4):\n");

    // User input
    int choice;

    scanf("%d", &choice);  // choice holds user input

    // Complete Action
    if (choice == 1) {
      // create a new process
      pid = create_process();
      printf("New process created with PID: %d\n\n", pid);
    } 
    else if (choice == 2) {
      // terminate a process
      printf("Enter PID of the process to terminate: ");
      scanf("%d", &pid);
      terminate_process(pid);
    } 
    else if (choice == 3) {
      // print active processes
      print_active_processes();
    } 
    else if (choice == 4) {
      // quit
      quit = quit_all();
    } 
    else {
      //a number other than 1 through 4 was input
      printf("Invalid choice. Please try again.\n");
    }
  }
  return 0;
}