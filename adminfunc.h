#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void add1()
{ int q,r,p;
	int x,y,z,deptchoice,valid,valid1,flag=0;

     char c[100],name[100],choice,choice1,dept[100];
     do{
	 printf("***** ADD ITEMS *****");
     printf("\n1. Electronics\n2. Sports\n3. Food");
     printf("\nEnter the Department number : ");
     scanf("%d",&deptchoice);
     if(deptchoice==1)
     strcpy(dept,"electronics.txt");
     else if(deptchoice==2)
     strcpy(dept,"sports.txt");
     else if(deptchoice==3)
     strcpy(dept,"food.txt");
     else
     while(deptchoice!=1 || deptchoice!=2 || deptchoice!=3)
     {
     	printf("\nInvalid Input.Please Input again.");
     	printf("\nEnter the Department number : ");
     scanf("%d",&deptchoice);
     printf("\nEnter the Department number : ");
     scanf("%d",&deptchoice);
     if(deptchoice==1 || deptchoice==2 || deptchoice==3)
     break;
	 }
     FILE *fh;
		fh=fopen(dept,"r");
     while(fscanf(fh,"%d %s %d %d",&x,c,&y,&z)!=EOF)
    	printf("\n%d %s %d %d",x,c,y,z);
    	fclose(fh);
    	do{
		
       	printf("\n\nEnter the product number of the new item : ");
        fflush(stdin);
        scanf("%d",&r);
        printf("\nEnter the name of the new item : ");
        scanf("%s",name);
        printf("\nEnter the quantity of the new item : ");
        scanf("%d",&q);
        printf("\nEnter the price of the new item : ");
        scanf("%d",&p);
        fh=fopen(dept,"a");
   		fprintf(fh,"\n%d %s %d %d",r,name,q,p);
   		fclose(fh);
   		fh=fopen(dept,"r");
    	while(fscanf(fh,"%d %s %d %d\n",&x,c,&y,&z)!=EOF)
    	printf("\n%d %s %d %d",x,c,y,z);
        fclose(fh);
      
		printf("\nDo you want to add another entry? Y/N : ");
		fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y' || choice=='Y' || choice=='n' || choice=='N')
        flag=1;
       	if((choice!='y' || choice!='Y') || (choice!='n' || choice!='N'))
		   {
		   while(flag!=1)
       	{ fflush(stdin);
       		printf("\nInvalid Input.Please Input again");
       		printf("\nDo you want to add another entry? Y/N : ");
        fflush(stdin);
        scanf("%c",&choice);
        if(choice=='y' || choice=='Y' || choice=='n' || choice=='N')
        {flag=1;break;
		}
		   }
		}
 		   }while(choice=='Y' || choice=='y');
 	
		 printf("\nDo you want to add items to any other Department? Y/N : ");   
 		 fflush(stdin);
        scanf("%c",&choice1);
 	}while(choice1=='y' || choice1=='Y');
}

void del1(){
       int d,b,c,sln,sl=0,d1,b1,c1,ch,op1,op2;
       char a[20],a1[20],fname[20];
       FILE *fp1,*fp2;
  do{
        printf("\nChoose the catagory to delete item\n\t1.Electronics\n\t2.sports\n\t3.Eatables");
        scanf("%d",&ch);
        switch(ch){
          case 1:strcpy(fname,"electronics.txt");
          	break;
          case 2:strcpy(fname,"sports.txt");
          	break;
          case 3:strcpy(fname,"food.txt");
          	break;
           default:printf("INVALID input:");
               }
       
        do{
        fp1=fopen(fname,"r");
       
             while(fscanf(fp1,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                   printf("%d %s %d %d\n",d,a,b,c);
                   }
             fclose(fp1);
          printf("\nEnter the sl.no to delete from catalogue");
          scanf("%d",&sln);
      
          fp1=fopen(fname,"r");
          fp2=fopen("temp.txt","w");
          sl=0;
          while(fscanf(fp1,"%d %s %d %d\n",&d,a,&b,&c)!=EOF){
                  if(sln!=d){
                 sl++;
                   fprintf(fp2,"%d %s %d %d\n",sl,a,b,c);
                 }
                     //printf("%d %s %d %d\n",d,a,b,c);                
            }
       
          fclose(fp1);
          fclose(fp2);
          remove(fname);
          rename("temp.txt",fname);
          fp1=fopen(fname,"r");
          while(fscanf(fp1,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
               
                printf("%d %s %d %d\n",d,a,b,c);
                
            }
      fclose(fp1); 
       printf("\nDo you want to continue deleting in ths catagory [1/0]");
          scanf("%d",&op1);   
      }while(op1==1);
       printf("\nDo you want to continue deleteing the item [1/0]");
       scanf("%d",&op2);
    }while(op2==1);
    printf("\nCHANGES HAS BEEN UPDATED");  
}



void restock()
{ int q,r,s,e,p,ch,op1,op2;
   char name[30],fname[30];
   do{
     printf("\nChoose the catagory to restock the qantity\n\t1.Electronics\n\t2.sports\n\t3.Eatables");
     scanf("%d",&ch);
     switch(ch){
          case 1:strcpy(fname,"electronics.txt");
          	break;
          case 2:strcpy(fname,"sports.txt");
          	break;
          case 3:strcpy(fname,"food.txt");
          	break;
           default:printf("INVALID input:");
     }
     FILE *fh,*fh1,*fh2,*fp;
  
     fh=fopen(fname,"r");
      while(fscanf(fh,"%d %s %d %d",&s,name,&e,&p)!=EOF)
        {
            printf("%d %s %d %d\n",s,name,e,p);
         }
         fclose(fh);
        do{
           printf("Enter the s.no of the item to change qantity of the item: ");
           fflush(stdin);
           scanf("%d",&r);
           printf("Enter the updated qantity of the item: ");
           scanf("%d",&q);
           fflush(stdin);
           
           fh=fopen(fname,"r");
           fh1=fopen("temp.txt","w");
          int n,y;
          while(fscanf(fh,"%d %s %d %d",&s,name,&e,&p)!=EOF)
          {      if(s==r)
                 e=q;
             fprintf(fh1,"%d %s %d %d\n",s,name,e,p);
           }
          fclose(fh);
          fclose(fh1);
          remove(fname);
          rename("temp.txt",fname);
          printf("\n----------after restock-----------\n");
          fp=fopen(fname,"r");
          while(fscanf(fp,"%d %s %d %d",&s,name,&e,&p)!=EOF)
          {
          printf("%d %s %d %d\n",s,name,e,p);
          }
     
          fclose(fp);
          printf("\nDo you want to restock in ths catagory [1/0]");
          scanf("%d",&op1);
         }while(op1==1);
       printf("\nDo you want to continue restock [1/0]");
       scanf("%d",&op2);
    }while(op2==1);
    printf("\nCHANGES HAS BEEN UPDATED");
}

    

void price()
{ int q,r,s,e,p,ch,op1,op2;
   char name[30],fname[30];
   do{
     printf("\nChoose the catagory to change price\n\t1.Electronics\n\t2.sports\n\t3.Eatables");
     scanf("%d",&ch);
     switch(ch){
          case 1:strcpy(fname,"electronics.txt");
          	break;
          case 2:strcpy(fname,"sports.txt");
          	break;
          case 3:strcpy(fname,"food.txt");
          	break;
           default:printf("INVALID input:");
     }
     FILE *fh,*fh1,*fh2,*fp;
  
     fh=fopen(fname,"r");
      while(fscanf(fh,"%d %s %d %d",&s,name,&e,&p)!=EOF)
        {
            printf("%d %s %d %d\n",s,name,e,p);
         }
         fclose(fh);
        do{
           printf("Enter the s.no of the item to change price of the item: ");
           fflush(stdin);
           scanf("%d",&r);
           printf("Enter the updated price of the item: ");
           scanf("%d",&q);
           fflush(stdin);
           
           fh=fopen(fname,"r");
           fh1=fopen("temp.txt","w");
          int n,y;
          while(fscanf(fh,"%d %s %d %d",&s,name,&e,&p)!=EOF)
          {      if(s==r)
                 p=q;
             fprintf(fh1,"%d %s %d %d\n",s,name,e,p);
           }
          fclose(fh);
          fclose(fh1);
          remove(fname);
          rename("temp.txt",fname);
          printf("\n----------after price change-----------\n");
          fp=fopen(fname,"r");
          while(fscanf(fp,"%d %s %d %d",&s,name,&e,&p)!=EOF)
          {
          printf("%d %s %d %d\n",s,name,e,p);
          }
     
          fclose(fp);
          printf("\nDo you want to continue changing price in ths catagory [1/0]");
          scanf("%d",&op1);
         }while(op1==1);
       printf("\nDo you want to continue changing price [1/0]");
       scanf("%d",&op2);
    }while(op2==1);
    printf("CHANGES HAS BEEN UPDATED");
}

    

