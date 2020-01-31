/*
 ============================================================================
 Name        : bitFact.c
 Author      : Ashley Van Spankeren
 Description : Asks user to input a positive integer (note: valid input ranges from 0 to 8)
				then outputs the factorial of the integer in decimal and binary.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE_INT 16


/* Throughout the program, the variable idx is used to represent the index of the array*/


// Sets every bit in an array to 0
void clearArray(unsigned char theBits[SIZE_INT]){
	int idx = 0;
	while (idx < SIZE_INT){
		theBits[idx] = 0;
		idx++;
	}
}

// Prints out each bit of the array 
void printBitArray(unsigned char theBits[SIZE_INT]){
	int idx = 0;
	while (idx < SIZE_INT){
		printf("%u", theBits[idx]);
		idx++;
	}
	printf("\n");
}

// Places each of the bits of 'value' into its designated element of the array
void toBits(unsigned short value, unsigned char inBits[SIZE_INT]){
	int idx = SIZE_INT - 1;
	unsigned short mask = 0000000000000001;
	while (value !=0){
		if ((value & mask) == 0){
			inBits[idx] = 0;
		}else{
			inBits[idx] = 1;
		}
		value = value>>1;
		idx = idx - 1;
	}
}

// Calculates the factorial of the number passed in
unsigned short factorial(unsigned short num){
	if (num == 0)
		return 1;
	if (num == 1)
		return 1;
	else{
		return num * factorial(num - 1);
	}
}

int main(void) {
	unsigned char inBits[SIZE_INT];
	unsigned short user_val; // will store the values entered by the user
	while (1){
		clearArray(inBits);
		printf("Enter a positive number: ");
		scanf("%u", &user_val);
		printf("\n %u factorial = %u = ", user_val, factorial(user_val));
		toBits(factorial(user_val), inBits);
		printBitArray(inBits);
		printf("Do another? (1 = yes, 0 = false) ==> ");
		scanf("%d", &user_val);
		if (user_val != 1)
			break;
	}
	return 0;
}
