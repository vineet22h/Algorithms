#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[],int l,int r) {
	int pivot = a[r];
	int j = l-1;

	for(int i =  l;i<r;i++){
		if(pivot >= a[i]) 
			swap(&a[i],&a[++j]);
	}
	swap(&a[++j],&a[r]);
	return j;
}

void quickSort(int a[],int l,int r) {
	int q;
	if (l<r) {
		q = partition(a,l,r);
		quickSort(a,l,q-1);
		quickSort(a,q+1,r);
	}
}

void printArray(int arr[], int size) 
{ 
    for (int i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
} 

void main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    printf("Before Sort : ");
    printArray(arr,n);

    quickSort(arr,0,n-1); 

    printf("Sorted array: "); 
    printArray(arr, n); 
    
}
