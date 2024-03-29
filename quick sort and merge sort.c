quick sort
#include <stdio.h>
  
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
int partition(int arr[], int l, int r)
{
    int x = arr[r];
    int i = (l - 1);
  
    for (int j = l; j <=r - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}
  
void quickSortIterative(int arr[], int l, int r)
{
    // Create an auxiliary stack
    int stack[r - l + 1];
    int top = -1;
  
    // push initial values of l and r to stack
    stack[++top] = l;
    stack[++top] = r;
  
    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];
  
        int p = partition(arr, l, r);
  
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
}
  

int main()
{
    int a[50], n , i ;
    printf("Enter the  no of elements:  ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }      
    quickSortIterative(a, 0, n - 1);
    printf("The sorted array  :  ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1)
            printf(" , ");
    }
    return 0;
}
output:
Enter the no of elements:4
Enter the elements:
234
65
12
15
The sorted array: 12 15 65 234
Merge sort
#include  <stdio.h>

void  mergesort(int  x[ ] , int  n)
{
  int  temp[50] , i , j , k , lb1 , lb2 , ub1 , ub2 , size ;

  size=1 ;
  while(size<n)
  {
    lb1=0 ;
    k=0 ;

    while(lb1+size<n)
    {
      lb2 = lb1+size ;
      ub1 = lb2-1 ;
      if(ub1+size<n)
		ub2 = ub1+size ;
      else
		ub2 = n-1 ;

      i=lb1 ;
      j=lb2 ;

      while(i <= ub1 && j <= ub2)
		if(x[i]<x[j])
	  		temp[k++] = x[i++] ;
		else
	  		temp[k++] = x[j++] ;

      while(i<=ub1)
		temp[k++] = x[i++] ;

      while(j<=ub2)
		temp[k++] = x[j++] ;

      lb1 = ub2+1 ;
    }

    for(i=0 ; i<=ub2 ; i++)
      x[i] = temp[i] ;

    size = size*2 ;
  }
}

int  main() //main function
{
 int  i , n , x[20] ;

 printf("Enter the  no  of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 mergesort(x,n) ;

 printf("The orted array :") ;
 for(i=0 ; i<n ; i++){
    printf("%d " , x[i]) ;
    if(i!=n-1)
      printf(" , ");
 }
 return 0;
}
output:
Enter the no of elements :5
Enter the elements :
23
1
56
13
2
The sorted array : 1 2 13 23 56
