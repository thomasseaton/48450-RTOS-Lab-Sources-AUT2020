/*
   -----48450 -- week 3 lab handout 1 -- read the command line----- 

This program is defined for 3 param input. Try ./P1 100 jian_zhang 9.9 
*/

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

void print_the_Param_on_Screen(int first, char second[], float thrid);

int main(int argc, char** argv)
{
	/* Verify the correct number of arguments were passed in */
	if (argc != 4) {
		fprintf(stderr, "USAGE:./main.out 6 RealTimeOs.txt 8.8\n");
	}
	/*define the local variables for storing input arguments*/
	int first_int = 0;
	char second_chs[64] = { 0 };
	float third_float = 0.0;
	/*convert the arguments and store in the local variables*/
	first_int = atoi(argv[1]);
	strcpy(second_chs, argv[2]);
	third_float = atof(argv[3]);
	/*output the augments to check whether the conversion is right*/ 
	
    print_the_Param_on_Screen(first_int, second_chs, third_float);
	return 0;
}

void print_the_Param_on_Screen(int first, char second[], float third){
	printf("The first parameter is: %d\n", first);
	printf("The second parameter is: %s\n", second);
	printf("The third parameter is: %.4f\n", third);
	
}
