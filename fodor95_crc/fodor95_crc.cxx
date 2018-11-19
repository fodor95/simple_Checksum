#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(){
	//some info for the user
	printf("If you want to leave, just type in \"takemeout\" \n");
	
	//define a label, so we can enter more strings, one after another
	startplace:
	
	//declaring the variable which stores the string
	//lets say the maximum length is 20 characters
	char dataFromArduino[20];
	
	//copy some string into the variable
	//strcpy(dataFromArduino, "www.fodor95.com");
	
	//or read some data from the keyboard
	printf("Enter a string, no space characters please:");
	scanf("%s",&dataFromArduino);
	
	//save its lenght and print it
	int lengthOfData = strlen(dataFromArduino);
	printf("Length of string: %d characters\n", lengthOfData);
	
	//declaring the sum variable for storing the sum of characters
	int sum = 0;
	
	//we need an additional variable to start multipling the characters from 1
	// and not from 0, since if we multiply any number with 0 we get 0, so the 
	// first character always gets lost, and we can have same crc for two 
	// different numbers
	int multiplier = 1;
	
	for(int i = 0; i < lengthOfData; i++){
		//stepping over every character of the message(string) and
		// multipling by its place
		sum += (dataFromArduino[i])*multiplier;
		
		//before the next character we need to increment the multiplier
		multiplier += 1;
	}
	
	//variable to store our crc
	int crc = 0;
	
	//how long we want the crc to be, 101 means the modulo of the nr can be up to 100, so 3 digits
	int numberOfChecksumDigits = 1001;
	
	//calculating the crc
	crc = sum%numberOfChecksumDigits;
	
	//printing out on the screen the crc
	printf("checksum: %d \n", crc);
	
	
	//if we type in takemeoutnow, then the application stops, otherwise it jumps 
	// back to its startpoint
	int answer = strcmp("takemeout",dataFromArduino);
	
	if(answer != 0)
		goto startplace;
	
	
	//waiting for a character, so the debugger window does not dissapear 
	// immediately after the program finishes the operation
	printf("\n>You wanted to leave, good bye");
	getch();
}
