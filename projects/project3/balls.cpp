#include <iostream>
void sort(int arr[], int max);

int main()
{
	int max=5;
	int arr[5]={3,4,5,1,2};
	for(int index=0;index<max;index++)
	{
		std::cout<<arr[index];
	}
	std::cout << std::endl;

	sort(arr,max);

	for(int index=0;index<max;index++)
	{
		std::cout<<arr[index];
	}
	std::cout << std::endl;
	return 0;
}

void sort(int arr[], int max)
{
	int temp;
	for(int i=0;i<=max;i++)
	{
		for(int j=0;j<max-1;j++)
		{
			if(arr[j+1] > arr[j])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
