#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  * stk=NULL;
int * arr=NULL;
int top=-1;
int *prev=NULL;
int len =0;
int *arr_ptr=NULL;
int* Create_arr(){
int * arr=(int *)malloc (sizeof(int)*256);
//arr_ptr=arr;
return arr;
}
void free_arr(int * arr){
free(arr);
}
void parse_dptr(char*inst){

	if(*(inst)=='>')arr_ptr++;
	else if (*(inst)=='<')arr_ptr--;
	else if (*(inst)=='+')(*arr_ptr)++;
	else if(*(inst)=='-')(*arr_ptr)--;
	else if (*(inst)=='.')printf(" %c",*arr_ptr);
	//else if(*inst==']')arr_ptr=prev+2;
}
void push(int * stk,int val){
	stk[++top]=val;
}
int pop(int*stk){
	int i=top;
	top--;
	return stk[i];
}


void mem_dump(int *arr){
for(int i=0;i<10;i++)printf("%d\n",*(arr+i));
}
/*
void parse(char *inst){
	int c=0;
char* i=inst;
while(*i!='\0'){
	parse_dptr(i);
	if (*(i)=='['){
		prev=arr_ptr;		
		while(*prev!=0 ){
			//parse(inst);
			//parse(inst+(++i));
			//if(*arr_ptr==']')break;
			parse_dptr(i++);
			//mem_dump(arr);
			if(*i==']')i=i-c;
			c++;
			prev=arr_ptr;
		}
	}
	i++;
}
*/
void parse (char * inst){
	int c=0;
	char* i =inst;
	prev=arr_ptr;
	
	while(*i!='\0'){
		
		if(*i=='['){
			prev=arr_ptr;
			while(1){
				
				parse_dptr(i);
				i++;

				
				//printf("\n-------\n");
				//printf("arrptr=%p--prev=%p",arr_ptr,prev);
				//mem_dump(arr);
				//printf("\n-------\n");

				if(*i==']'){
					if(*arr_ptr==0){
					break;
				}
					//push(stk,c);
					i-=c;
					//arr_ptr=prev+1;
					c=0;
					//continue;
				}
				c++;

				
			}

		}
		else{
			parse_dptr((i));
			i++;
		}

	}
		

}


/*
void insert(int *arr,int val){
*(arr+(len++))=val;
}
*/
int main(){
arr=Create_arr();
arr_ptr=arr;
int *stk=malloc(sizeof(int)*256);
char * inst=(char*)malloc(sizeof(char)*100);
scanf("%s",inst);
parse (inst);
//for (int i=0;i<strlen(inst);i++){
//	parse((inst+i));
//}

mem_dump(arr);
//insert(arr,1);
//insert(arr,2);
//free_arr(arr);
}
