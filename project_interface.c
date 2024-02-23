/*
 * File: project_interface.c
 * The program, once executed, should print user interface with 4 choices and let user interact by entering an integer.
 * Each number (1-4) triggers a unique action. After completing the action, the program displays the same menu again.
 * CSCI435
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

// Functions:
/*
 * add the functions here?
 */

int main()
{
	bool quit = false;
	// Print interface
	while(quit == false){
		printf("1. Create a new process\n2. Terminate a process\n3. Print active processes\n4. Quit\nYour choice (1-4):\n");
		
		// User input
		int choice;
		
		scanf("%d", &choice); //choice holds user input
	
		// Complete Action
		if(choice < 1){
			//
			printf("Invalid choice. Please try again.\n");
		}
		else if(choice  > 4){
			//
			printf("Invalid choice. Please try again.\n");
		}
		else if(choice == 1){
			//create a new process
			printf("choice 1:\n");
			
		}
		else if(choice == 2){
			//terminate a process
			printf("choice 2:\n");
			
		}
		else if(choice == 3){
			//print active processes
			printf("choice 3:\n");
			
		}
		else if(choice == 4){
			//quit
			printf("Goodbye!\n");
			quit = true;
		}
		else{
			//
			printf("Invalid choice. Please try again.\n");
		}
		
	}
	return 0;
}
