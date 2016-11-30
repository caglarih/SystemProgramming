/*
  BLG413 - System Programming
  Project 1 - Part 2
  Project Group 14
  Members:
	  I. Burak Caglar ------ 150120057
	  Omer Pala ------------ 150120043
	  O. Taylan Yildirim --- 150130063
  ./part2 input2d.txt rule2d.txt
*/
 #include <stdio.h>
 #include <stdlib.h>
 void part2(int* x,int* size,int* y,int* rule);
 void print(int*,int*);
 void swap(int*,int*);
 void initrule(int*,char*);
 int main(int argc, char **argv ){
 	
 	FILE *f;
 	f = fopen(argv[1],"r");
 	int size[2],i,j,par2[2],count=1;
 	fscanf(f,"%d %d\n",size,size+1);
 	int *x = (int*)malloc(sizeof(int)*(size[0]+2)*(size[1]+2));
 	int *y = (int*)malloc(sizeof(int)*(size[0]+2)*(size[1]+2));
 	for(i=1;i<size[1]+1;i++){
 		for(j=1;j<size[0]+1;j++){
 			fscanf(f,"%d",x+i*(size[0]+2)+j);
 		}
 	}
 	for(i=0;i<size[1]+2;i++){
 		for(j=0;j<size[0]+2;j++){
 			y[i*(size[0]+2)+j]=0;
 		}
 	}
 	printf("\nInitial matrix\n\n");
 	print(x,size);
 	fclose(f);
	int rule[32], iterator = 0, step;
	initrule(rule, argv[2]);
	int goOn = 1;
	char it;

 	while(goOn){	
 		printf("  Step: %d\n\n",count);
 		par2[0] = 5; par2[1]=5;
 		part2(x,par2,y,rule);
		print(y,size);
		count++;
 		
 		for(i=0;i<size[1]+2;i++){
 			for(j=0;j<size[0]+2;j++){
 				x[i*(size[0]+2)+j]=y[i*(size[0]+2)+j];
 				y[i*(size[0]+2)+j]=0;
 			}
 		}
		//swap(x,y);
		//print(x,size);
		//print(y,size);
 		printf("Do you want to continue to generating. (Y for continue) \n");
 		scanf(" %c", &it);
 		if(it == 'Y' || it == 'y'){
		    goOn = 1;
 		}
 		else{
 			goOn = 0;
 		}
 	}
 	free(x);
 	free(y);
 	return 0;
 }
 void swap(int *x,int *y){
 		int *temp;
 		temp = x;
 		x = y;
 		y = temp;
 }
 void print(int* y, int* size){
		int i,j;
    	printf("      ");
		for(i=0;i<size[0]*2+1;i++) printf("_");
		printf("\n");
 		for(i=1;i<size[1]+1;i++){
 			printf("      ");
 			for(j=1;j<size[0]+1;j++) {
			    if (y[(size[0]+2)*i+j] == 1)			
				    printf("|\u25A0");
			    else 
				    printf("|\u25A1");
		    }
 			printf("|\n");
 		}
		printf("      ");
		for(i=0;i<size[0]*2+1;i++) printf("\"");
		printf("\n\n");
 }
void initrule(int* tmp ,char* fl){
	
	FILE *f;
 	f = fopen(fl,"r");
	int i = 0 ;
	while (i < 32){
	fscanf(f,"%d",&tmp[i]);	
	i++;
	}
	fclose(f);
}
