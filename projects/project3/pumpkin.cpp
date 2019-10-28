/// Header files /////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

/// Function Declarations ////////////////////////////////////////////////////////////

/// Function: Patch Size
/// Requirements: None
/// Results: Returns the size of a patch
/// Input/Parameters: The garden itself, the row and column being indexed, as well as the bounds. A counter variable is also used.
/// Output: Returns an integer
/// Description: Searches through a garden recursively to keep count of how many pumpkins there are.
int patch_size(char** garden, int row, int col, int maxRow, int maxCol,  int counter);
/// Function: Sort
/// Requirements: None
/// Results: Organizes a vector in ascending order
/// Input/Parameters: A vector of ints
/// Output: None
/// Description: Function uses bubble sort algorithm to organize the vector
void sort(std::vector<int> &arr);

/// Main Function ////////////////////////////////////////////////////////////////////
int main()
{
	//VARIABLES:
	int rows=1, cols=1, size=0, patch_ct=0, garden_ct=0;
	bool loop_main=true;
	std::vector<int> size_arr;
	while(loop_main==true)
	{
		if(rows==0 || cols==0)
		{
			loop_main=false;
		}
		//MAKING THE GARDEN:
		else
		{
			garden_ct+=1;
			std::cin >> rows >> cols;
			char** garden = new char*[rows];
			for(int index=0;index<rows;index++)
			{
				garden[index]=new char[cols];
			}
			//CREATING THE GARDEN:
			for(int index=0;index<rows; index++)
			{
				for(int subindex=0;subindex<cols;subindex++)
				{
					std::cin >> garden[index][subindex];
				}
			}
			//SEARCHING FOR A PUMPKIN:
			for(int index=0;index<rows;index++)
			{
				for(int subindex=0;subindex<cols;subindex++)
				{
					if(garden[index][subindex]=='p')
					{
						patch_ct++;
						size=patch_size(garden, index, subindex, rows, cols, size);
						size_arr.push_back(size);
					}
					size=0;
				}
			}
			//OUTPUTTING THE GARDEN'S INFORMATION:
			sort(size_arr);
			if(rows!=0&&cols!=0)
			{
				std::cout << "Garden # " << garden_ct << ": " << patch_ct << " patches, sizes:";
				for(int index=0;index<size_arr.size(); index++)
				{
					std::cout << " " << size_arr[index];
				}
				std::cout << std::endl;
			}
			size_arr.clear();
			patch_ct=0;
		}
	}
	return 0;
}

/// Function Definitions //////////////////////////////////////////////////////////////

/// Function: Patch Size
/// Requirements: None
/// Results: Returns the size of a patch
/// Input/Parameters: The garden itself(2D array of chars), the row and column being indexed in main, the bounds of the garden.
///										A counter variable is also used to keep track of the number of pumpkins in the patch.
/// Output: Returns an integer
/// Description: Searches through a garden recursively to keep count of how many pumpkins there are. This function works since
///							 the main function searches through the garden iteravely until it finds a 'p'. If there is one, then it calls
///							 this function. This function updates the value to a 'P' to mark that it has been seen, then it checks if any
///							 adjacent elements are also 'p'. The order of operations for searching the garden is as follows:
///							 																			RIGHT -> DOWN -> LEFT -> UP
int patch_size(char** garden, int row, int col, int maxRow, int maxCol,  int counter)
{
	counter++;
	garden[row][col] = 'P';
	if(col<maxCol-1 && garden[row][col+1]=='p')
	{
		counter=patch_size(garden, row, col+1, maxRow, maxCol, counter);
	}
	if(row<maxRow-1 && garden[row+1][col]=='p')
	{
		counter=patch_size(garden, row+1, col, maxRow, maxCol, counter);
	}
	if(col>0 && garden[row][col-1]=='p')
	{
		counter=patch_size(garden, row, col-1, maxRow, maxCol, counter);
	}
	if(row>0 && garden[row-1][col]=='p')
	{
		counter=patch_size(garden, row-1, col, maxRow, maxCol, counter);
	}
	return counter;
}
/// Function: Sort
/// Requirements: None
/// Results: Organizes a vector in ascending order
/// Input/Parameters: A vector of ints
/// Output: None
/// Description: Function uses bubble sort algorithm to organize the vector
void sort(std::vector<int> &arr)
{
	int temp;
	int max = arr.size();
	for(int i=0;i<=max;i++)
	{
		for(int j=0;j<max-1;j++)
		{
			if(arr[j+1] < arr[j])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
