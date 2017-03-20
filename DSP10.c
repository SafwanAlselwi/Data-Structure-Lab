/*By Saf1
  Write a menu driven program to:
    a: Find the length of a string
    b: Concatenate two strings
    c: Extract a substring from a given string
    d: Finding and Replacing a string by another string in a text
    Use Pointers and user-defined functions
*/
#include<stdio.h>
#include<conio.h>

void input(char *s);
int length(char *s);
char* concate(char *s1,char *s2);
char* extract(char *s, int start, int len);
char* replace(char str[50],char find[50],char rep[50]);

int main(){
  int ch,start=0, len=0;
  char s1[50],s2[50],s3[100];
  do{
    puts("\nPress any key to continue..");
    getch();
    system("cls"); // clrscr();
    printf("\nPress 1 : Length of String");
    printf("\nPress 2 : Concatenate Two strings");
    printf("\nPress 3 : Extract a substring");
    printf("\nPress 4 : Finding and Replacing a string");
    printf("\nPress 0 : Exit");
    printf("\n\tEnter choice :\t");
    scanf("%d",&ch);

    switch(ch){
	case 1:
		printf("Enter a String:\t");
		input(s1);
		printf("\nLength = %d",length(s1));
		break;
	case 2:
		printf("\nConcatenate two strings");
		printf("\nEnter 1st String :\t");
		input(s1);
		printf("\nEnter 2nd String :\t");
		input(s2);
		printf("%s",concate(s1,s2));
		break;
	case 3:
		printf("\nExtract a substring");
		printf("\nEnter Original String :\t");
		input(s1);
		printf("\nEnter Starting Position and Length :\t");
		scanf("%d %d",&start,&len);
		printf("\nExtracted String :\t%s",extract(s1,start,len));
		break;
	case 4:
		printf("\nFinding and Replacing a string");
		printf("\nEnter Original String :\t");
		input(s1);
		printf("\nEnter a Old String:\t");
		input(s2);
		printf("\nEnter a New String:\t");
		input(s3);
		printf("\nString After Replacement:\t%s",replace(s1,s2,s3));
		break;
	case 0: exit(0);
	default:puts("\nWrong choice, Try Again");
    }
  }while(ch !=0);
  getch();
  return 0;
}
void input(char *s){
    char ch;
    fflush(stdin);
    while( (ch=getchar())!='\n' )
        *s++=ch;
    *s='\0';
}
int length(char *s){
    int len=0;
    while(*s !='\0'){
        len++;
        s++;
    }
    return len;
}
char* concate(char *s1,char *s2){
    char *p,tmp[100];
    int i=0;
    p=s1;
    while(*p !='\0')
       tmp[i++] = *p++;

    p=s2;
    while(*p !='\0')
        tmp[i++] = *p++;

    tmp[i] = '\0';
    return tmp;
}
char* extract(char *s, int start, int len){
    char tmp[100];
    int i=0;
    while(*s!='\0' && len>0){
		tmp[i++] = s[start++];
		len--;
    }
    tmp[i] = '\0';
    return tmp;
}
char* replace(char str[50],char find[50],char rep[50]){
    char tmp[100];
    int i,j,k,m,n;
    i=j=m=n=0;
    //i-->tmp, j-->find, k-->rep, m,n-->str
    while(str[n]!='\0'){
		if(str[m]==find[j]){ //matching so replace
			m++;
			j++;
			if(find[j]=='\0'){ //Occurences
                j=0;  //Reinitialize j, so that if we have more than one occurance they'll be replaced
                n=m;
                k=0;
                while(rep[k]!='\0')
                    tmp[i++] = rep[k++];
			}
		}
		else{//mismatch so copy the same character
			tmp[i++] = str[n++];
			j=0;
			m=n;
		}
    }//while
    tmp[i] = '\0';
    return tmp;
}
