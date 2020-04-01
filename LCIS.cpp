/*
Given two arrays, find length of the longest common increasing subsequence [LCIS] and print one of such sequences (multiple sequences may exist)

Suppose we consider two arrays –
arr1[] = {3, 4, 9, 1} and
arr2[] = {5, 3, 8, 9, 10, 2, 1}

Our answer would be {3, 9} as this is the longest common subsequence which is increasing also.
*/

int LCIS(int arr1[],int n,int arr2[],int m)
{
	int temp[m]; // will store LCIS

	for(int i=0;i<m;i++)
	{
		temp[i] = 0;
	}

	int current = 0; // current max LCIS

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr1[i] == arr2[j])
			{
				if(current+1 > temp[j])
					temp[j] = current+1;
			}

			if(arr1[i] > arr2[j])
			{
				if(temp[j] > current)
					current = temp[j];
			} 
		}
	}
	int result = 0;
	for(int i=0;i<m;i++)
	{
		if(temp[i] > result)
			result = temp[i];
	}

	return result;
}


int main()
{
}
