#include <stdio.h>
#include <string.h>

/*
What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

algorithm takes O(n^2) time to find the answer
*/
char dataStr[] = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 \
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 \
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 \
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 \
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 \
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 \
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 \
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 \
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 \
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 \
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 \
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 \
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 \
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 \
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 \
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 \
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 \
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 \
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 \
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

#define SIZE 20
#define ASCII_OFFSET 48
#define OFFSET 4
#define CALC_EAST data[i][j] * data[i][j + 1] * data[i][j + 2] * data[i][j + 3]
#define CALC_SOUTHEAST data[i][j] * data[i + 1][j + 1] * data[i + 2][j + 2] * data[i + 3][j + 3]
#define CALC_SOUTH data[i][j] * data[i + 1][j] * data[i + 2][j] * data[i + 3][j]
#define CALC_SOUTHWEST data[i][j] * data[i + 1][j - 1] * data[i + 2][j - 2] * data[i + 3][j - 3]

enum DIR {
	E = 0,//left to right
	SE = 1,//diagnollay right & down
	S = 2,//top to bottom
	SW = 3 //diagonally left & down
};

//Used to hold info about which product has the largest value
typedef struct candidate {
	int r; //row (first index)
	int c; //column (second index)
	long val; //value of the product of the 4 elements starting at data[r][c] extending in the direction designated by dir
	enum DIR dir;//direction (
} candidate;

int **init();
candidate *scan(int **data);
void destroy(int **data);

int main() {
	int **data;
	data = init();
		
	candidate *c = scan(data);
	printf("\nlargest product\nrow: %d \ncol: %d \nval: %ld \ndir: %d", c->r, c->c, c->val, c->dir);

	free(c);
	destroy(data);
	
	return 0;
}

int **init() {
	/// Initialize a 2D array of ints on the heap from the global string data
	int** data;
	int i, j, k;

	int num, flag;
	data = malloc(sizeof(int *) * SIZE);
	for(i = 0; i < SIZE; i++) {
		data[i] = malloc(sizeof(int) * SIZE);
	}
	
	k = 0, j = 0, i = 0;
	flag = 1;
	//loop through the string char by char
	while(k < strlen(dataStr)) {
		//if we find a space, we know we are about to encounter a new number
		if(dataStr[k] == ' ')
			flag = 1;
		//get the ascii value of the most significant digit, multiply by 10
		//(all numbers are guaranteed to be less than 100)
		else if(flag == 1){
			num = (dataStr[k] - ASCII_OFFSET) * 10;
			flag += 1;
		}
		else {//if flag == 2, get the ascii value of the least significant digit, add it to what we calculated above
			num += dataStr[k] - ASCII_OFFSET;
			data[i][j] = num;
			flag = 0;
			
			//increment the column counter
			j = (j + 1) % SIZE;
			//increment the row counter
			if(j == 0)
				i = (i + 1) % SIZE;
		}
		//increment the char counter
		k += 1;
	}
	return data;
}

candidate *scan(int **data){
	candidate *c;
	c = malloc(sizeof(candidate));
	int i, j;
	enum DIR k;
	long currentVal;
	
	c->r = 0;
	c->c = 0;
	c->val = data[c->r][c->c];
	c->dir = E;
	//loop through the whole 2d array
	for(i = 0; i < SIZE; i++) {
		for(j = 0; j < SIZE; j++) {
			//check the 4 possible directions
			for(k = E; k <= SW; k++) {
				//check the bounds of each direction so we don't seg fault
				//j is counter for the column
				//i is counter for the row
				if((k == E) && (j <= SIZE - OFFSET)) {
					currentVal = CALC_EAST;
				}
				else if((k == SE) && (j <= SIZE - OFFSET) && (i <= SIZE - OFFSET)) {
					currentVal = CALC_SOUTHEAST;
				}
				else if((k == S) && (i <= SIZE - OFFSET)) {
					currentVal = CALC_SOUTH;
				}
				else if((k == SW) && (j >= OFFSET - 1) && (i <= SIZE - OFFSET)){
					currentVal = CALC_SOUTHWEST;
				}
				//check if this value is larger than the maxval we currently have
				if(currentVal > c->val) {
					c->r = i;
					c->c = j;
					c->val = currentVal;
					c->dir = k;
				}
			}
			currentVal = 0;
		}
	}
		
	return c;
}

//free everything on the heap
void destroy(int **data) {
	int i;
	int* currentPtr;
	for(i = 0; i < SIZE; i++){
		currentPtr = data[i];
		free(currentPtr);
	}
	free(data);
}