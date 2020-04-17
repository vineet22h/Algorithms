
// C code for  Activity Selection Problem
#include<stdio.h>

void activity_selection(int start[], int end[], int n)
{
   
   printf("%d -> %d\n",start[0],end[0]);
   int j,i=0;
   for(j=1; j< n; j++)
      if(start[j] >= end[i]) {
            printf("%d -> %d\n",start[j],end[j]); 
            i=j;
          }
}

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

void BubbleSort(int start[],int end[],int n) {
   for(int i=0;i<n;i++) {
      for (int j =1;j<n;j++) {
         if(end[j-1] > end[j]) {
            swap(&start[j-1],&start[j]);
            swap(&end[j-1],&end[j]);
         }
      }
   }
}

void insertionSort(int start[],int end[],int n) {
   for(int i=1;i<n;i++) {
      int key = end[i];
      for(int j =0;j<i;j++) {
         if(end[j] > key) {
            swap(&end[j],&end[j+1]);
            swap(&start[j],&start[j+1]);
         }
      }
   }
}

void selectionSort(int start[],int end[],int n) {
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
      swap(&start[i],&start[index]);
   }
}


 
int main()
{
   int n,i;
   int start[] = {5, 1, 2, 0, 5, 8};
   int end[] =  {9, 2, 4, 6, 7, 9};
   n = sizeof(start)/sizeof(start[0]);
   BubbleSort(start,end,n);
   print(start,n);
   print(end,n);
   activity_selection(start,end,n);
   return 0;
}