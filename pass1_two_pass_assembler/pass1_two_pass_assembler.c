#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int searchoptab(char str[])
{
	char opcode[15];
	FILE *f2;
	f2=fopen("optab.txt","r");
	if(f2!=NULL)
	{
    		while(!feof(f2))
		{
        		fscanf(f2,"%s%*d",opcode);
        		if(strcmp(opcode,str)==0)
			{
        			fclose(f2);
            			return 1;
        		}
    		}
	}
	else
    	printf("Cannot acces OPTAB\n");

	fclose(f2);
	return 0;
}


void main()
{
	FILE *f1,*f2,*f3,*f4;
	char label[15],opcode[15],operand[15];
	long int locctr,startaddr,plen;
	//open files required for the operation
	f1=fopen("input.txt","r");
	f2=fopen("optab.txt","r");
	f3=fopen("symtab.txt","w");
	f4=fopen("inter.txt","w");
	if(f1!=NULL)
	{
    		//read the contents of the input file i.e the program
    		fscanf(f1,"%s%s%s",label,opcode,operand);
    		if(strcmp("START",opcode)==0)
        		startaddr=locctr=atoi(operand);
    		else
        		locctr=0;
    		while(!feof(f1))
		{
        		//if not end of file do the following
        		fscanf(f1,"%s%s%s",label,opcode,operand);
        		fprintf(f4,"%ld\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        		//if label is not empty
        		if(strcmp(label,"-")!=0)
			{
            			fprintf(f3,"%s\t%ld\n",label,locctr);
        		}
        		if(searchoptab(opcode)==1)
            			locctr+=3;
        		else if(strcmp(opcode,"WORD")==0)
            			locctr+=3;
        		else if(strcmp(opcode,"RESW")==0)
			{
            			int op;
            			op=atoi(operand);
            			locctr+=3*op;
        		}
        		else if(strcmp(opcode,"RESB")==0)
			{
            			int op;
            			op=atoi(operand);
            			locctr+=op;
        		}
        		else if(strcmp(opcode,"BYTE")==0)
			{
            			int len;
            			len=strlen(operand);
            			locctr+=len;
        		}
        		else if(strcmp(opcode,"END")==0)
			{
            			continue;
        		}
        		else
            			printf("Invalid opcode %s!!\n",opcode);
    		}
    		plen=locctr-startaddr;
    		printf("Program Length: %ld\n",plen);
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}
