#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "adminfunc.h"
void admin()
{
	int c,ch,r;
	do{
	printf("\n\n************ ADMIN MENU ***********");
	printf("\n\t1. Add Items \n\t2. Delete Items\n\t3.Restock items\n\t4.Change price\n\t5. Log Out");
	printf("\nEnter your choice : ");
	r=scanf("%d",&c);
	printf("\n");
	if(r==1 && c>=1 && c<=5)
	{
		switch(c)
		{
			case 1: add1();break;
			case 2: del1();break;
			case 3: restock();break;
			case 4: price();break;
			case 5: printf("\nLogged Out");exit(0);
		}
	}
	else if(r!=1)
	printf("\nInvalid Input.Please Input again. ");
	printf("\nDo you want to continue[1/0]");
	scanf("%d",&ch);
	}while(ch==1);
	
}

