#include <iostream>
#include <cstdlib>
using namespace std;

//Swap function
void swap( int* a, int*b ){
	int m;
	m = *a;
	*a =*b;
	*b = m;
}

//paartitioning the array

int Partition(int arr[], int low, int high){
	int pivot , index , i;
	index = low ;
	pivot = high;
	
	//getting the position of the pivot
	for( i = low; i<high ; i++){
		if( arr[i]< arr[pivot]){
			swap( &arr[i],&arr[index]);
			index ++;
			
		}
	}
	
	//Swapping value at high and at the index obtained
	swap(&arr[pivot],&arr[index]);
	return index;
	
}

//Random selection of pivot
int RandomPivotParrtitioning( int arr[], int low, int high){
	int p , n , m;
	n =rand();
	//Randomizing the pivot value in the given subpart of array
	p = low +n%(high- low+1);
	
	//swapping pivot value from high, so pivot value will be taken as a part while partitioning
	swap(&arr[high], &arr[p]);
	return Partition(arr ,low ,high);
	
}


int QuickSort (int arr[], int low, int high){
	int pindex;
	if(low<high){
		//Partitioning array using randomized pivot
		pindex =RandomPivotParrtitioning( arr, low, high);
		
		//Recursively implementing quick sort
		QuickSort(arr, low, pindex-1);
		QuickSort(arr, pindex+1 , high);
		
	}
	return 0;
	
}


int main(){
	int n, i;
	cout<<"Enter the size of the array ";
	cin>>n;
	
	int arr[n];
	for (i =0; i<n; i++){
		cout<<"Enter element "<<i+1<<":";
		cin>> arr[i];
	}	
	
	QuickSort (arr, 0 ,n-1);
	cout<<"Sorted data";
	for( i = 0; i<n ; i++){
		cout<<"-> "<<arr[i];
	}
	return 0;
}




















