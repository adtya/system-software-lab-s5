#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


struct symtab{
    int addr;
    char label[15];
}s[100];

int hash(char str[]){
int n;
int hashval=0;
n=strlen(str);
for(int i=0;i<n;i++){
    if(isalpha(str[i])){
        tolower(str[i]);
        hashval+=str[i]-'a';
    }
    else if(isdigit(str[i])){
    hashval+=str[i]-'0';
    }
}
return hashval%31;
}

void insert(char symbol[],int addr){
    int hashval,oldvar;
    oldvar=hashval=hash(symbol);
    if(strcmp(s[hashval].label,"")==0){
    strcpy(s[hashval].label,symbol);
    s[hashval].addr=addr;
    }
    else
    {
        while(strcmp(s[hashval].label,"")&&hashval!=oldvar-1){
            //printf("%d\n",hashval);
            hashval=(hashval+1)%31;
        }
        strcpy(s[hashval].label,symbol);
        s[hashval].addr=addr;
    }
}

int search(char symbol[]){
    int hashval,oldvar;
    oldvar=hashval=hash(symbol);
    if(strcmp(s[hashval].label,symbol)==0)
        return hashval;
    else{
    while(hashval!=oldvar-1 && (strcmp(s[hashval].label,symbol)!=0)){
        hashval=(hashval+1)%31;
    }
    }
    if(strcmp(s[hashval].label,symbol)==0)
    return -1;
}

void display(char symbol[]){
    int hashval=search(symbol);
    if(search(symbol)==-1)
        printf("Value not found!!\n");
    else
        printf("Symbol: %s\nAddress:%d",symbol,s[hashval].addr);
}

void main(){
int ch,addr,val;
for(int i=0;i<100;i++)
    strcpy(s[i].label,"");
char sname[15];
do{
    printf("\n\n1.Insert into SYMTAB\n2.Search SYMTAB\n3.Exit\nEnter choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 1:printf("Enter the symbol to be inserted: ");
    scanf("%s",sname);
    printf("Enter the address of the symbol in the program: ");
    scanf("%d",&addr);
    insert(sname,addr);
    break;
    case 2:printf("Enter the symbol to be searched: ");
    scanf("%s",sname);
    display(sname);
    break;
    case 3: 
    break;
    default: printf("WRONG CHOICE!!\n\n");
    }
}while(ch!=3);
for(int i=0;i<100;i++){
    if(strcmp(s[i].label,""))
        printf("%s\t%d\n",s[i].label,s[i].addr);
}
}

