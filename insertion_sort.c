#include<stdio.h>

int main()
{


}

void insertion_sort(int A[], int n)
{
	int i,j,item;

	for (i=1;i<n;i++)
	{
		item = A[i];

		j = i-1;

		while (j>=0 && A[j]>item)
		{
			A[j+1] = A [j];

			j=j-1;
		}

		A[j+1] = item;
	}

}