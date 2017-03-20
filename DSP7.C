/*By Saf1
  Write a menu driven recursive program to:
    a: Find Factorial of a given number.
    b: Generate first N terms of a fibonacci sequence.
    c: Find GCD of three numbers.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int fact(int n);
int fib(int n);
int gcd(int n1,int n2);

int main(){
  int num,ch,i;
  int n1,n2,n3; //GCD numbers
  system("cls"); //clrscr();
  do{
    puts("\nPress any key to continue..");
    getch();
    system("cls"); //clrscr();
    printf("\nPress 1 : Factorial");
    printf("\nPress 2 : Fibonacci");
    printf("\nPress 3 : GCD");
    printf("\nPress 0 : Exit");
    printf("\n\tEnter choice :\t");
    scanf("%d",&ch);

    switch(ch){
		case 1:
			printf("\nFactorial of a given number");
			printf("\nEnter the number:\t");
			scanf("%d",&num);
			printf("\nFactorial of %d is %d",num, fact(num) );
			break;
		case 2:
			printf("\nGenerate First N terms of a Fibonacci sequence");
			printf("\nEnter the number of terms:\t");
			scanf("%d",&num);
			for(i=0; i<num;i++)
				printf("Term %d=\t %d\n",i,fib(i));
			break;
		case 3:
			printf("\nFind GCD of three numbers");
			printf("\nEnter 3 Numbers :\t");
			scanf("%d%d%d",&n1,&n2,&n3);
			printf("\nGCD of %d, %d, %d = %d",n1,n2,n3,gcd(gcd(n1,n2),n3) );
			break;
		case 0: exit(0);
		default:puts("\nWrong choice, Try Again");
    }
  }while(ch !=0);
  getch();
}

int fact(int n){
	if (n==0)
		return 1;
	else
		return n * fact(n-1);
}

int fib(int n){
    if(n==0 || n==1)
		return n;
    else
		return fib(n-1) + fib(n-2);
}

int gcd(int n1,int n2){
    while(n1!=n2){
		if(n1>n2)
			return gcd(n1-n2,n2);
		else
			return gcd(n1,n2-n1);
    }
    return n1;
}
