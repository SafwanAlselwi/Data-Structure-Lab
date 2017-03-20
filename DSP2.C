/*
  Write a menu driven program to sort the array in asc/desc order using:
    a: Quick Sort
    b: Merge Sort
    Note: In quick sort, The first number  is chosen and considered as pivot number. The rest of numbers smaller than the pivot are moved to its left and the numbers greater than pivot are moved to its right. Repeat the same process to both left and right sides until the pivot number is single.
    Note: In merge Sort, divide the unsorted array into n sub arrays, each containing 1 element. An array of 1 element is considered as sorted. Then, Repeatedly merge sub arrays to produce new sorted arrays until there is only one array.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void swap(int *n1, int *n2){
    int tmp;
    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}
void readArray(int a[],int n){
    int i;
    printf("\nEnter the Elements\n");
    for(i=0; i<n ; i++)
        scanf("%d",&a[i]);
}
void printArray(int a[],int n){
    int i;
    for(i=0; i<n ; i++)
        printf("%d\t",a[i]);
}
void QSort(int a[],int low,int high){
    int pivot,i,j;
    if(low<high)
    {
        pivot = low;
        i  = low;
        j = high;
        while(i<j)
        {
            while(a[pivot] < a[j])
                j--;
            while(a[i]<=a[pivot]&& i<high)
                i++;
            if(i<j)
                swap(&a[i],&a[j]);
        }
        swap(&a[pivot],&a[j]);
        QSort(a,low,j-1);
        QSort(a,j+1,high);
    }
}

void Msort(int a[],int low , int mid , int high){
    //Merge two arrays i.e merge a[low .. mid] with a[mid+1.... high]
    int tmp[20],i,j,k;
    i=low;
    j=mid+1;

    for(k=low ; k<=high ; k++) // copy a[low..high] to tmp[low..high]
        tmp[k] = a[k];

    for(k=low ;k<=high ;k++)   // Merge back to a[low..high]
        if(i>mid)                a[k] = tmp[j++];
        else if(j>high)          a[k] = tmp[i++];
        else if(tmp[i]>tmp[j])   a[k] = tmp[j++];
        else                     a[k] = tmp[i++];
}
void mergePart(int a[],int low, int high){
    int mid;
    if(low<high)
    {
       mid=(low+high)/2;
       mergePart(a,low,mid);      // sort left array
       mergePart(a,mid+1,high);   // sort right array
       Msort(a,low,mid,high);     // Merge two arrays
     }
}
int main(){
  int a[10],n;
  int ch;
  do{
    puts("\nPress any key to continue..");
    getch();
    system("cls"); // clrscr();
    printf("\nPress 1 : Quick Sort");
    printf("\nPress 2 : Merge Sort");
    printf("\nPress 0 : Exit");
    printf("\n\tEnter choice :\t");
    scanf("%d",&ch);

    switch(ch){
	case 1:
	      printf("\nQuick Sort");
          printf("\nEnter the number of elements:\t");
          scanf("%d",&n);
          readArray(a,n);
          printf("\nArray Before sorting is:\n");
          printArray(a,n);
          QSort(a,0,n-1);
          printf("\nArray After sorting is:\n");
          printArray(a,n);
		  break;
	case 2:
          printf("\nMerge Sort");
          printf("\nEnter the number of elements:\t");
          scanf("%d",&n);
          readArray(a,n);
          printf("\nArray Before sorting is:\n");
          printArray(a,n);
          mergePart(a,0,n-1);
          printf("\nArray After sorting is:\n");
          printArray(a,n);
		break;
	case 0: exit(0);
	default:puts("\nWrong choice, Try Again");
    }
  }while(ch !=0);
  getch();
  return 0;
}
