// Julianna Diaz
// COP 3502
// Professor Torosdagli
// 23 June 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Function to search  a number in between a high and low value
int search(int numbers[], int low, int high, int value) {

  // Variable to hold the middle of the array
  int middle; 
  // Finding the index number 
  middle = (low+high)/2;


  // Checking if lower value is higher than the high value. Returns -1
  if(low > high)
    return -1;

  // runs search if the value given is smaller than the middle index
  else if(value < numbers[middle]) 
    // continues search with middle of array decreased by 1 as the high value
    return search(numbers, low, middle-1, value);
  // runs if the value is greater than the middle index of the array
  else if(value > numbers[middle])
    // continues search with middle of array increased by 1 as the low value
    return search(numbers, middle+1, high, value);
  // Returns middle index of the array
  else
    return middle; 

}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}