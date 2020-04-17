#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct heap {
	int* array;
	int heap_size;
	int capacity;
};

struct heap* createHeap(int capacity) {
	struct heap *heap = malloc(sizeof(struct heap));
	if(!heap) {
		printf("memory error");
		return 0;
	}
	heap->array = malloc(sizeof(int)*capacity);
	heap->heap_size = -1;
	heap->capacity = capacity;
	return heap;
}

void resize(struct heap *h) {
	int *old_array = h->array;
	h->capacity = h->capacity*2;
	h->array = malloc(sizeof(int)*h->capacity);
	if(!h->array) {
		printf("memory error");
		return;
	}
	for(int i=0;i<=h->heap_size;i++) 
		h->array[i] = old_array[i];
	printf("\nResizing array size");
	free(old_array);
}

void swap(struct heap *h,int i1,int i2) {
	int temp;
	temp = h->array[i1];
	h->array[i1] = h->array[i2];
	h->array[i2] = temp;
}

void heapify(struct heap *h,int i) {
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;

	if (left <= h->heap_size && h->array[left] > h->array[largest] ) 
		largest = left;

	if (right <= h->heap_size && h->array[right] > h->array[largest]) 
		largest = right;

	if(largest!=i) {
		swap(h,largest,i);
		heapify(h,largest);
	}
}

void build_max_heap(struct heap *h) {
	for(int i = floor(h->heap_size-1)/2;i >= 0;i--) {
		heapify(h,i);
	}
}

void insert(struct heap *h,int data) {
	if(h->heap_size == h->capacity-1) 
		resize(h);
	h->array[++h->heap_size] = data;
}

void heapSort(struct heap *h) {
	build_max_heap(h);
	int n = h->heap_size;
	for(int i = n;i>=0;i--) {
		swap(h,h->heap_size,0);
		h->heap_size--;
		heapify(h,0);
	}
	h->heap_size = n;
}

void print(struct heap *h) {
	for(int i=0;i <= h->heap_size;i++) 
		printf("%d ",h->array[i]);
}

void main() {
	struct heap *h = createHeap(6);
	insert(h,6);
	insert(h,5);
	insert(h,4);
	insert(h,3);
	insert(h,2);
	insert(h,1);
	insert(h,0);
	printf("\nBefore sort : ");
	print(h);
	printf("\nAfter sort : ");
	heapSort(h);
	print(h);

}