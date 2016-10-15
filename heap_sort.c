#include<stdio.h>
#include<stdlib.h>

void heapsort(int a[], int length)
{
  buildheap(a, length);
  int heapsize, i, temp;
  heapsize = length - 1;
  for( i=heapsize; i >= 0; i--)
  {
    temp = a[0];
    a[0] = a[heapsize];
    a[heapsize] = temp;
    heapsize--;
    satisfyheap(a, 0, heapsize);
  }
  for( i=0; i < length; i++)
  {
    cout << "\t" << a[i];
  }
}

void buildheap(int a[], int length)
{
  int i, heapsize;
  heapsize = length - 1;
  for( i=(length/2); i >= 0; i--)
  {
    satisfyheap(a, i, heapsize);
  }
}

void satisfyheap(int a[], int i, int heapsize)
{
  int l, r, largest, temp;
  l = 2*i;
  r = 2*i + 1;
  if(l <= heapsize && a[l] > a[i])
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if( r <= heapsize && a[r] > a[largest])
  {
    largest = r;
  }
  if(largest != i)
  {
    temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
    satisfyheap(a, largest, heapsize);
  }
}
main()
{
    int n;
    printf("Please enter the number of elements: ");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    printf("\nPlease enter the elements:");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qksort(a,0,n-1);
    printf("The array after sorting is as follows:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

