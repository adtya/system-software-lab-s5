//Hierarchical File Organisation

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
   	char dn[20];
   	char d[20][20];
   	struct node* link[20];
   	int nu;
   	int du;
}*r,*pa;

int m=0,I;
void create1(struct node *);
struct node* search(char [],char s1[]);
struct node* searchs(char [],char s1[]);

void crd()
{
        struct node* n=(struct node *)malloc(sizeof(struct node));
        n->du=n->nu=0;
        if(n==NULL)
        {
                printf("\nDirectory not created");
                return;
        }
        printf("\nEnter directory name:");
        scanf("%s",n->dn);
        r->link[m++]=n;
}

void crsd()
{
        int l;
        char s[25];
        struct node *t,*n;
        n=(struct node *)malloc(sizeof(struct node));
        n->du=n->nu=0;
        printf("\nEnter name of parent directory:");
        scanf("%s",s);
        t=search(s,"NULL");
        if(t==NULL)
        {
                printf("\nInvalid Directory");
                return;
        }
       printf("\nEnter name of subdirectory:");
       scanf("%s",n->dn);
       l=t->du;
       t->link[l]=n;
       ++t->du;
}

void del()
{
   	char s[25],s1[25],s2[23];
   	int i,j,fl=0,k,ch;
   	struct node *t,*p,*n;
   	printf("\nMenu \n1)Delete directory\n2)Delete file from directory\n3)Delete file from subdirectory\n4)Delete subdirectory\nEnter choice:");
   	scanf("%d",&ch);
   	if(ch==1)
   	{
   	printf("\nEnter name of directory to be deleted:");
   	scanf("%s",s);
   	p=search(s,"NULL");
   	if(p==NULL)
       	{
          	printf("\nInvalid directory name");
          	return;
       	}
        --m;
        printf("\nDirectory deleted");
        for(j=0;j< p->du;++j)
        	free(p->link[j]);
        free(p);
        for(j=I;j<m;++j)
               	pa->link[j]=pa->link[j+1];
    	}
   	else if(ch==2)
   	{
   		printf("\nEnter directory name:");
     		scanf("%s",s);
     		printf("\nEnter filename:");
     		scanf("%s",s1);
     		n=search(s,"NULL");
     		if(n==NULL)
      		{
         		printf("\nInvalid directory name");
         		return;
      		}
     		for(j=0;j< n->nu;++j)
       		if(strcmp(s1,n->d[j])==0)
             	{
               		fl=1;
               		--n->nu;
               		printf("\nFile has been deleted");
               		for(k=j;k< n->nu;++k)
                  		strcpy(n->d[k],n->d[k+1]);
               		break;
             	}
    		if(fl==0)
     			printf("\nFile not found");
   	}
      	else if(ch==3)
   	{
    		printf("\nEnter subdirectory name:");
     		scanf("%s",s);
    		printf("\nEnter filename:");
     		scanf("%s",s1);
     		n=searchs(s,"NULL");
     		if(n==NULL)
      		{
         		printf("\nInvalid Directory name");
         		return;
      		}
     		for(j=0;j< n->nu;++j)
       			if(strcmp(s1,n->d[j])==0)
             		{
               			fl=1;
               			--n->nu;
               			printf("\nFile has been deleted");
               			for(k=j;k< n->nu;++k)
                  			strcpy(n->d[k],n->d[k+1]);
               			break;
             		}
    			if(fl==0)
    	 			printf("\nFile Not found");
   	}
   	else if(ch==4)
   	{
   		printf("\nEnter subdirectory to be deleted:");
   		scanf("%s",s);
   		p=searchs(s,"NULL");
   		if(p==NULL)
       		{
          		printf("\nInvalid Directory");
          		return;
       		}
           	--pa->du;
           	printf("\nSubdirectory has been deleted");
           	free(p);
           	for(j=I;j< pa->du;++j)
               		pa->link[j]=pa->link[j+1];
    	}
}

void create()
{
        int i,ch;
        char s[20];
        struct node *t,*n;
        printf("\nMenu\n1)Create file in directory\n2)Create file in subdirectory\nEnter choice:");
        scanf("%d",&ch);
        if(ch==1)
        {
        printf("\nEnter directory name:");
        scanf("%s",s);
        t=search(s,"NULL");
        if(t==NULL)
        {
                printf("\nInvalid directory name");
                return;
        }
        create1(t);
        printf("\nFile Created");
        }
        if(ch==2)
        {
                printf("\nEnter subdirectory name:");
                scanf("%s",s);
                t=searchs(s,"NULL");
                if(t==NULL)
                {
                        printf("\nInvalid Directory");
                        return;
                }
                create1(t);
                printf("\nFile Created");
        }
}

void create1(struct node *n)
{
   	char s[25];
   	int j,l;
     	printf("\nEnter filename:");
     	scanf("%s",n->d[(n->nu)]);
    	n->nu++;
}

void print()
{
    	int i,j,k;
    	struct node* n;
    	if(r==NULL)
    	{
       		printf("\nEmpty");
       		return;
    	}
    	printf("\nRoot Directory:%s",r->dn);
    	printf("\nDirectory\t\tFiles");
    	for(i=0;i<m;++i)
    	{
     		n=r->link[i];
      		printf("\n%s\t\t\t",n->dn);
      		for(j=0;j<n->nu;++j)
        	printf("%s\t",n->d[j]);
      		if(n->du==0)
         		continue;
      		printf("\n\t\tSubdirectories\t\tFiles");
      		for(j=0;j<n->du;++j)
        	{
          		printf("\n\t\t%s\t\t\t",n->link[j]->dn);
           		for(k=0;k<n->link[j]->nu;++k)
               		printf("%s\t",n->link[j]->d[k]);
        	}
    	}
}

struct node * search(char s[],char s1[])
{
     	int i,fl=0,j;
     	struct node*n;
     	for(i=0;i<m;++i)
     	{
      		fl=0;
      		n=r->link[i];
      		if(strcmp(s,n->dn)==0)
        	{
          		if(strcmp(s1,"NULL")==0)
           		{
             			pa=r;
             			I=i;
             			return n;
           		}
          		for(j=0;j<n->nu;++j)
            			if(strcmp(s1,n->d[j])==0)
             			{
               				fl=1;
               				printf("\nFound");
               				print();
               				return n;
             			}
          			break;
        		}
    		}
   	if(i==m)
      		return NULL;
   	else if(fl==0)
     		printf("\nFile Not found");
}

struct node * searchs(char s[],char s1[])
{
     	int i,fl=0,j,k;
     	struct node* n;
     	for(i=0;i<m;++i)
     	{
       		fl=0;
       		n=r->link[i];
       		for(k=0;k<n->du;++k)
        	if(strcmp(s,n->link[k]->dn)==0)
         	{
          		if(strcmp(s1,"NULL")==0)
           		{
             			pa=n;
             			I=k;
             			return n->link[k];
           		}
          		for(j=0;j<n->link[k]->nu;++j)
            			if(strcmp(s1,n->link[k]->d[j])==0)
             			{
               				fl=1;
               				printf("\nFound");
               				print();
               				return n;
             			}
          		break;
        	}
   	}
   	if(i==m)
      		return NULL;
   	else if(fl==0)
     		printf("\nFile Not found");
}

void main()
{
	int i,j,n,ch;
    	char s[20],s1[20];
    	struct node*t;
    	r=(struct node *)malloc(sizeof(struct node));
    	printf("\nEnter name of root:");
    	scanf("%s",r->dn);
    	pa=r;
    	printf("\nRoot Created");
   	do
   	{
     		printf("\n\nMENU \n1)Create Directory\n2)Create Subdirectory \n3)Create File \n4)Delete \n5)Search File in Directory \n6)Search File in Subdirectory\n7)Display \n8)Exit \nEnter choice:");
     		scanf("%d",&ch);
     		if(ch==8)
        		break;
     		switch(ch)
     		{
         		case 1:crd();
               			break;
         		case 2:crsd();
               			break;
         		case 3:create();
               			break;
         		case 4:del();
               			break;
         		case 5:printf("\nEnter name of directory:");
                		scanf("%s",s);
          			printf("\nEnter filename:");
                		scanf("%s",s1);
                		t=search(s,s1);
                		if(t==NULL)
                   		printf("\nInvalid Directory");
          	 		break;
         		case 6:printf("\nEnter Subdirectory name:");
                		scanf("%s",s);
				printf("\nEnter filename:");
                		scanf("%s",s1);
                		t=searchs(s,s1);
                		if(t==NULL)
                   		printf("\nInvalid Subdirectory");
                		break;
         		case 7:print();
               			break;
     		}

   	}while(1);
}

