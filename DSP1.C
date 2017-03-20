/* By Saf1
  Write a menu driven program to implement linear and binary search
  also find the location of its first occurrence
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void read();
void show();
void sort();
void linear();
void binary();

int a[10],n,i,j,ch,key;

 int main(){
system("cls");//clrscr();
  do{
     puts("\nPress any key to continue..");
     getch();
     system("cls");//clrscr();
     printf("\nPress 1 : Linear Search");
     printf("\nPress 2 : Binary Search");
     printf("\nPress 0 : Exit");
     printf("\n\tEnter choice :\t");
     scanf("%d",&ch);

    switch(ch){
	case 1: linear();
		break;
	case 2: binary();
		break;
	case 0: exit(0);
	default:puts("\nWrong choice, Try Again");
     }
  }while(ch !=0);
  getch();
}
void read(){
  printf("\nEnter the number of Elements :\t");
  scanf("%d",&n);
  printf("\nEnter the array Elements\n");
  for(i=0;i<n;i++)
	scanf("%d",&a[i]);
}
void show(){
  printf("\nArray Elements are:\n");
  for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
void sort(){
  int tmp;

  show();
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++)
		if(a[j] > a[j+1])
		{
		   tmp  = a[j];
		   a[j] = a[j+1];
		   a[j+1] = tmp;
		}
  }
  printf("\nArray After Sort");
  show();
}
void linear(){
   read();
   show();
   printf("\nEnter the Key: \t");
   scanf("%d",&key);

   for(i=0;i<n;i++)
	if(key == a[i]){
		printf("\nElement Found at Position:\t%d",i+1);
		return;
	}
   puts("\nElement not found");
}
void binary(){
  int l,m,h;
  read();
  sort();
  puts("\nEnter the Key: \t");
  scanf("%d",&key);

  l=0;
  h=n-1;
  while(l<=h){
	m=(l+h)/2;
	if(key == a[m]){
        printf("\nElement Found at Position:\t%d",m+1);
	    return;
	}
	(key > a[m]) ? (l=m+1) : (h=m-1);
  }
  printf("\nElement Not Found");
}
