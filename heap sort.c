#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}
  
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}
  
int main() {
    int a[50], n , i ;
    printf("Enter the  no of elements:  ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }      
    heapSort(a,n);
    
    printf("The sorted array is :  ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1)
            printf(" , ");
    }
  }
output:
Enter the number of elements :4
Enter the elements:
23
13
14
12
The sorted array:12 13 14 23
