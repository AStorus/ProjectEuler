#include <stdio.h>

/*
Find the sum of all the primes below two million.
By: Andrew Storus
*/

#define MAX_VAL 2000000
int currentSize;
long numPrimes;

int isPrime(int n, long *primes);
long long calcPrimeSum(int max, long *primes);
long *init(); 

int main() {
	long *primes = init();
	long long sum = calcPrimeSum(MAX_VAL, primes);
	printf("largest value prime generated: %d\n", primes[numPrimes - 1]);
	printf("sum of all the primes: %lld\n", sum);
	printf("number of primes generated: %ld", numPrimes);
	free(primes);
	return 0;
}

long *init() {
	currentSize = 150000;
	long *primes = malloc(sizeof(long) * currentSize);
	numPrimes = 0;
	return primes;
}

long long calcPrimeSum(int max, long *primes) {
	//returns sum of primes under 2 million
	long i = 2;
	long long sum = 0;
	while(i < max) {
		if (isPrime(i, primes) == 1) {
			primes[numPrimes] = i;
			numPrimes += 1;
			sum += i;
		}
		i += 1;
	}
	return sum;
}

int isPrime(int n, long *primes) {
	//returns 1 if prime, 0 if composite
	
	//If it is 2 or 3, add it to a list of primes
	//For every other number, check if it is divisible by any of the primes in the list
	//If it is divisible, it is a composite number
	//If it is not divisible, append it to the list of primes and return it is prime
	long i;
	if(n == 2 || n == 3) 
		return 1;
	else if(fmod(n, 2) == 0)
		return 0;
	else {
		for(i = 0; i < numPrimes; i++) {
			if(primes[i] > sqrt(n))
				return 1;
			if(fmod(n, primes[i]) == 0) 
				return 0;
		}
		return 1;
	}
}