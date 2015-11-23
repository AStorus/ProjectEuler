#include <stdio.h>
#include <math.h>

#define MAX_PRIMES 10001
int numPrimes;
int primes[MAX_PRIMES];

int isPrime(int n);
void initializePrimes();
int calcNthPrime(int n);
void printPrimes();

/*
Andrew Storus
Solution to https://projecteuler.net/problem=7
*/

int main() {
	int i;
	int val;
	initializePrimes();
	val = calcNthPrime(10001);
	printPrimes();
	
	printf("\nlargest prime: %d", val);
	
	return 0;
}

void initializePrimes() {
	int i;
	numPrimes = 0;
	for(i = 0; i < MAX_PRIMES; i++) 
		primes[i] = 0;
}

int calcNthPrime(int n) {
	//returns val of Nth prime
	int i = 2;
	while(numPrimes < n) {
		if (isPrime(i) == 1) {
			primes[numPrimes] = i;
			numPrimes += 1;
		}
		i += 1;
	}
	return i - 1;
}

int isPrime(int n) {
	//returns 1 if prime, 0 if composite
	
	//If it is 2 or 3, add it to a list of primes
	//For every other number, check if it is divisible by any of the primes in the list
	//If it is divisible, it is a composite number
	//If it is not divisible, append it to the list of primes and return it is prime
	
	int i;
	if(n == 2 || n == 3) 
		return 1;
	else {
		for(i = 0; i < numPrimes; i++) {
			if(fmod(n, primes[i]) == 0) 
				return 0;
		}
		return 1;
	}
}

void printPrimes(){
	int i;
	for(i = 0; i < MAX_PRIMES; i++) 
		printf("prime #: %d val: %d \n", i, primes[i]);
}