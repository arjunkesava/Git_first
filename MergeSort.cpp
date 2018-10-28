/* C++ program for Merge Sort */
#include <bits/stdc++.h> 
using namespace std; 

/* Merge Sort follow`s Divide and Conquer technique */
/* It splits the array to two sub arrays and then sort them */

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		// If the left part element is less than right.
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		// else the right part element is added
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		// K is the normal linear index of arr
		k++; 
	} 

	// 
	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		// Finall we merge both the sub arrays
		merge(arr, l, m, r); 
	} 
} 

/* Function to print an array */
void printArray(int a[], int size) 
{ 
	for (int i=0; i < size; i++) 
		cout<<a[i]<<" ";
	cout<<endl;
}

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int arr_size = sizeof(arr)/sizeof(arr[0]); 

	cout<<"Given array is"<<endl; 
	printArray(arr, arr_size);

	// Main Algorithm Code of Merge Sort
	mergeSort(arr, 0, arr_size - 1); 

	cout<<endl<<"Sorted Array is"<<endl;
	printArray(arr, arr_size); 
	return 0; 
} 