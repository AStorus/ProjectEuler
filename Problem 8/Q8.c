#include <stdio.h>

/*
The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the vallde of this product?
*/

#define size 1000
#define adjacent 13
#define ASCII_OFFSET 48
char dataStr[] = "73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";
 
int* initData(){
	//conver the string of data from the problem to an array
	int *arrayPtr;
	int i,j;
	arrayPtr = malloc(sizeof(int) * size);
	for(i = 0; i < size; i++) 
		arrayPtr[i] = (int)dataStr[i] - ASCII_OFFSET;
	
	return arrayPtr;	
}

int scan(int *data, int len) {
	//scans the data array and returns the index of the beginning of the 13 digits whose value is largest
	int i, j;
	//need to use long long to store the size (max possible value is 10^13 - 1, well beyond integer range)
	long long maxVal = 0;
	int retIndx = 0;
	long long val = 1;
	for(i = 0; i < size - len; i++) {
		for(j = 0; j < len; j++)
			val *= data[i + j];
		if(val > maxVal){
			retIndx = i;
			maxVal = val;
		}
		val = 1;
	}

	return retIndx;
}

long long getMaxVal(int *data, int indx, int len) {
	long long ret = 1;
	int i;
	for(i = 0; i < len; i++) {
		ret *= data[indx + i];
	}
	return ret;
}

int main() {
	int *ptr = initData();
	int indx = scan(ptr, adjacent);
	long long val = getMaxVal(ptr, indx , adjacent);
		
	printf("digit first index#: %d \nvalue: %lli", indx, val);
	
	free(ptr);
	return 0;
}