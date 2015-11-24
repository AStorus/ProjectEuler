#include <stdio.h>
#include <math.h>

/*
	Q:
	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
	a^2 + b^2 = c^2
	
	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
	Find the product abc.
	By Andrew Storus
*/
#define c sqrt(a * a + b * b)
#define maxCheckVal sqrt(1000)

double findProduct();

int main() {
	double ans = findProduct();
	printf("\nproduct: %.0f",ans);
	return 0;
}

double findProduct() {
	int a,b;
	double product;
	for(a = 3; a < 1000; a++){
		for(b = a; b < 1000; b++) {
			if(a + b + c == 1000) {
				product = a * b * c;
				printf("\na:%d, b:%d, c: %g", a, b, c);
			}
		}
	}
	return product;
}