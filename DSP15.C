/*
Write a program to sort the array of N elements using HEAP SORT
*/
#include <stdio.h>
void createheap(int a[], int n)
{
	int i,j,k,item;
	for(k=1;k<n;k++)
	{
		item = a[k];
		i=k;
		j=(i-1)/2;
		while(i>0 && item>a[j])
		{
			a[i] = a[j];
			i=j;
			j=(i-1)/2;
		}
		a[i]=item;
    }
}
void heapsort(int a[],int n)
{
	int i,temp;
	createheap(a,n);
	for(i=n-1;i>0;i--)
	{
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		createheap(a,i);
	}
}
void main()
{
	int a[20],n, i;
	clrscr();
	printf("\nEnter number of elements in array: ");
	scanf("%d", &n);
	printf("\nEnter elements: ");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	heapsort(a,n);

	printf("\n sorted list:\n");
	for(i=0;i<n;i++)
		printf("%d\t", a[i]);
	getch();
}