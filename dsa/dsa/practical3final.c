#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void choose_input(int* ,int,int);
void bestcase(int* , int);
void worstCase(int* , int);
void avgCase(int* , int);
void worstCase_qs(int* , int n);
void quick_sortBest(int* , int, int, int);
int partitionBest(int a[], int p ,int r);
void quick_sortWorst(int a[], int p, int r, int n);
int partitionWorst(int a[], int p ,int r);
void merge_sort(int* , int, int, int); 
void merging (int* , int, int, int ,int , int, int*, int*);

int main()
{  
  int choice,n;
   
  int* arr;
  printf("Enter the number of elements of the array: "); 
  scanf("%d", &n);
  arr=(int *)calloc(n, sizeof(int));

  while(1)
  {
  printf("Which sort do you want to execute?\n");
  printf("Enter 1 for Merge Sort.\n");
  printf("Enter 2 for Quick Sort.\n");
  printf("Enter 3 for Heap Sort.\n");
  printf("Enter 4 for EXIT.\n");
  scanf("%d", &choice);
 
  switch (choice)
  {
   
    case 1:
    printf("Merge Sort \n");
    choose_input(arr,n,choice);
    break;
    
    case 2:
    printf("Quick Sort \n");
    choose_input(arr,n,choice);
    break;
    
    case 3:
    printf("Heap Sort \n");
    choose_input(arr,n,choice);
    break; 

    case 4:
    printf("EXIT");
    exit(0);
    break;
    
    default:
    printf("Invalid Input");
    break;
 }
 }
 }
 
 void choose_input(int a[],int n,int choice)
 {
    int input,check =1;
    while(check==1){
    printf("Which input do you want?\n");
    printf("Enter 1 for Best case.\n");
    printf("Enter 2 for Worst case.\n");
    printf("Enter 3 for Average case.\n"); 
    printf("Enter 4 for EXIT.\n");
    scanf("%d",&input);
   
    switch(input)
    {
    case 1:
    printf("Best Case\n");
    bestcase(a,n);
    if (choice == 1)
    { 
        double cputime;
        clock_t t1,t2;
        t1= clock();
        merge_sort(a,0,n-1,n);
        t2 = clock();

        cputime = (double)(t2-t1)/CLOCKS_PER_SEC;
        printf("Time for merge sort for best case is %lf\n",cputime);
    }
    else if (choice == 2)
    {
      
        double cputime;
        clock_t t1,t2;
        t1 = clock();
        quick_sortBest(a,0,n-1,n);
        t2 = clock();

        cputime = (double)(t2-t1)/CLOCKS_PER_SEC;
        printf("Time for quick sort  is %lf\n", cputime);
    }
    else if (choice == 3)
    {
      // heapSort(a,n,input);
    }
    break;
    
    case 2:
    printf("Worst case\n");
    worstCase(a,n);
    if (choice == 1)
    {
      
        double cputime;
        clock_t t1,t2;
        t1= clock();
        merge_sort(a,0,n-1,n);
        t2 = clock();

        cputime = (double)(t2-t1)/CLOCKS_PER_SEC;
        printf("Time for merge sort for worst case is %lf\n",cputime);
    
    }
    else if (choice == 2)
    {
      
       
        double cputime;
        clock_t t1,t2;
        t1 = clock();
        quick_sortWorst(a,0,n-1,n);
        t2 = clock();

        cputime = (double)(t2-t1)/CLOCKS_PER_SEC;
        printf("Time for quick sort  is %lf\n", cputime);
    }
    else if (choice == 3)
    {
      // heapSort(a,n,input);
    }
    break;
    
    case 3:
    printf("Average case \n");
    avgCase(a,n);
    if (choice == 1)
    {
       
        double cputime;
        clock_t t1,t2;
        t1= clock();
        merge_sort(a,0,n-1,n);
        t2 = clock();

        cputime = (double)(t2-t1)/CLOCKS_PER_SEC;
        printf("Time for merge sort for average case is %lf\n",cputime);
    
    }
    else if (choice == 2)
    {
       
        printf("No average case for quick sort!");
    }
    else if (choice == 3)
    {
      // heapSort(a,n,input);
    }
    break;
    

    case 4:
    printf("EXIT\n");
    check = 0;
    break;
    
    default:
    printf("Invalid Input");
    break;
    }
  
    }

  }
void bestcase(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
        // printf("%d  ", a[i]);
    }

}
void worstCase(int a[], int n)
{
    int i;
    int size = n;

    for(i=0; i < size; i++, n-- )
    {
        a[i] = n;
       // printf("%d  ", a[i]);
    }
}

void avgCase(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        a[i] = rand()%10000;
       // printf("%d  ", a[i]);
    }
}
void merge_sort(int a[], int p, int r, int n)
{
  int q;
  
  if( p < r)
  {
      
      q = (p + r)/2;
      merge_sort(a, p, q, n);
      merge_sort(a, q + 1, r, n);
      int n1 =  q - p + 1;
      int n2 = r - q;
      int* L;
      L = (int *)calloc(n1+1, sizeof(int));
      int* R;
      R = (int *)calloc(n2+1, sizeof(int));
      merging(a, p, q, r, n1, n2, L, R);
  }
  
}
void merging (int a[] , int p, int q, int r, int n1, int n2, int L[], int R[])
{
   int i, j, k;
  
   for(i = 0; i < n1; i++)
   {
       L[i] = a[p+i-1];
   }
   for(j = 0; j < n1; j++)
   {
       R[j] = a[q+j];
   }
    L[n1+1]=99999;
    R[n2+1]=99999;
    i=0;
    j=0;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];
            i++;
        }
        else
         {
            a[k] = R[j];
            j++;
        }
        k++;
    }

}
void quick_sortBest(int a[], int p, int r, int n)
{
  int q;
  if( p < r)
    {
      
      q = partitionBest(a ,p, r); 
      quick_sortBest(a, p, q-1, n);
      quick_sortBest(a, q + 1, r, n);
   }
}

int partitionBest(int a[], int p ,int r)
{
  int x = a[(p+r)/2]; // x is pivot
  int i = p-1;
  for(int j = p; j < r-1 ; j++)
  {
    if (a[j] <= x) 
    {
      i = i +1;

     int t = a[i];
     a[i] = a[j];
     a[j] = t; 
    }
  
}
   int k = a[i+1];
   a[i+1] = a[r];
   a[r]= k;

   

   return( i + 1);
}
void quick_sortWorst(int a[], int p, int r, int n)
{
  int q;
  if( p < r)
    {
      
      q = partitionWorst(a ,p, r); // for worst case q == max/min element best case q == n-1/2 
      quick_sortWorst(a, p, q-1, n);
      quick_sortWorst(a, q + 1, r, n);
    } 

}

int partitionWorst(int a[], int p ,int r)
{
  int x = a[r]; // x is pivot last element is the minimum element
  int i = p-1;
  for(int j = p; j < r-1 ; j++)
  {
    if (a[j] <= x) 
    {
      i=i +1;

     int t = a[i];
     a[i] = a[j];
     a[j] = t; 
    }
  
}
   int k = a[i+1];
   a[i+1] = a[r];
   a[r]= k;

   return( i + 1);
}
