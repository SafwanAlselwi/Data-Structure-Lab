/* By Assaad
Write a program to solve the problem of towers of hanoi with 3 pegs and N discs.
For more details and farther explaination see this video
https://www.youtube.com/watch?v=aN3Fdp2nTkQ
*/
#include<stdio.h>
#include<conio.h>
void tower(int,char,char,char);
void main()
{
	int n;
	clrscr();
	printf("\nEnter the number of disks\n");
	scanf("%d",&n);
	tower(n,'A','B','C');
	getch();
}

void tower(int n,char BEG,char AUX, char END)
{
	if(n==1) /* If only 1 disk, make the move and return */
		printf("\nMove One Disk From %c -> %c ",BEG,END);
	else
	{
		tower(n-1,BEG,END,AUX);
		tower(1  ,BEG,AUX,END);
		tower(n-1,AUX,BEG,END);
	}
}