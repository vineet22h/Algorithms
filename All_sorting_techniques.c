#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int*b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

void print(int a[],int n) {
   for(int i=0;i<n;i++) {
      printf("%d ",a[i]);
   }
   printf("\n");
}

void BubbleSort(int end[],int n) {
   for(int i=0;i<n;i++) {
      for (int j =1;j<n;j++) {
         if(end[j-1] > end[j]) {
            swap(&end[j-1],&end[j]);
         }
      }
   }
}

void insertionSort(int end[],int n) {
   for(int i=1;i<n;i++) {
      int key = end[i];
      int j = i-1;
      
      while(j>=0 && end[j] >= key) {
         end[j+1] = end[j];
         j--;
      }
      end[j+1] = key;
   }
}

void selectionSort(int end[],int n) {
   for(int i=0;i<n;i++) {
      int min = end[i];
      int index = i;
      for(int j= i+1;j<n;j++) {
         if(min > end[j]) {
            min = end[j];
            index = j;
         }
      }
      swap(&end[i],&end[index]);
     
   }
}

void merge(int a[],int l,int m,int r) {
   int n1 = m-l+1;
   int n2 = r-m;

   int *L = malloc(sizeof(int)*n1);
   int *R = malloc(sizeof(int)*n2);

   for(int i = 0;i<n1;i++)
      L[i] = a[l+i];
   for(int i = 0;i<n2;i++) 
      R[i] = a[m+1+i];

   int i,j,k;
   i = j= 0;
   k = l;

   while(i<n1 && j<n2) {
      if(L[i] < R[j]) {
         a[k] = L[i];
         i++;
         k++;
      }
      else {
         a[k] = R[j];
         j++;
         k++;
      }
   }
   while(i<n1) {
      a[k] = L[i];
      i++;
      k++;
   }
   while(j<n2) {
      a[k] = R[j];
      j++;
      k++;
   }
}

void mergeSort(int a[],int l ,int r) {
   if(l<r) {
      int middle = (l+r)/2;
      mergeSort(a,l,middle);
      mergeSort(a,middle+1,r);
      merge(a,l,middle,r);
   }
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

void main() {
   int start[] = {9,8,7,6,5,4};
   int end[] =  {9,8,7,6,5,4};
   int t[] = {9,8,7,6,5,4};
   int f[] = {9,8,7,6,5,4};
   int g[] = {9,8,7,6,5,4};
   int n = sizeof(start)/sizeof(start[0]);
   insertionSort(start,n);
   selectionSort(end,n);
   BubbleSort(t,n);
   mergeSort(f,0,n-1);
   quickSort(g,0,n-1);
   print(start,n);
   print(end,n);
   print(t,n);
   print(f,n);
   print(g,n);
}