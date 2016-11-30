/*
  BLG413 - System Programming
  Project 1 - Part 1
  Project Group 14
  Members:
	  I. Burak Caglar ------ 150120057
	  Omer Pala ------------ 150120043
	  O. Taylan Yildirim --- 150130063
  ./part1 input1d.txt
*/


#include <stdio.h>
#include <stdlib.h>

void part1(int* x,int len,int* y,int* rule);
void parse(int*,int);
int main ( int argc, char **argv )
{
	int ruleno,repeat;
	printf("Please give me ruleno : ");
	scanf ("%d",&ruleno);
	if( ruleno < 0 || ruleno >255) {
		printf("RULE NO IS OUT OF BOUNDS! ");
		return 0;
	}
	printf("\nPlease give me how many step do wou want : ");
	scanf("%d", &repeat);
	FILE *f;
 	f = fopen(argv[1],"r");
 	int count,*x,*y;
 	fscanf(f,"%d\n",&count);
	x = (int*)malloc(sizeof(int)*(count+2));
	y = (int*)malloc(sizeof(int)*(count));
	int i,j;
	for(j=1;j<count+1;j++){
 		fscanf(f,"%d",x+j);
 	}
	int rule[8];
	parse(rule,ruleno);
	printf("\n\n\n\n");
	for(i=0;i<2*count;i++) printf("_");
	printf("\n");
	for(i=1;i<count+1;i++) {
		if (x[i] == 1)			
			printf("\u25A0 ");
		else 
			printf("\u25A1 ");		
	}
	printf("\n");
	for(j=0;j<repeat;j++){
		part1(x,count+2,y,rule);
		for(i=0;i<count;i++) {
			x[i+1]=y[i];
		}
		for(i=1;i<count+1;i++) {
			if (x[i] == 1)			
				printf("\u25A0 ");
			else 
				printf("\u25A1 ");
		}
		printf("\n");
	}
	
	for(i=0;i<2*count;i++) printf("\"");
	printf("\n\n\n");
	free(x);
	free(y);
    return 0;
}

void parse(int *arr,int rule){
	int i;
	for(i=0;i<8;i++){
		if(rule%2==0){
			arr[i]=0;
		}
		else{
			arr[i]=1;
		}
		rule = rule/2;
	}
}
