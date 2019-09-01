#include<stdio.h>
#include<stdlib.h>
#include "edit.h"
#include "bill.h"
  void costumer(){
      int n,d,b,c1,c,cart,qan,edi,cho,ed,p,sl=1;
      FILE *fp,*fp1;
      char a[10];
      printf("\n**************WELCOME TO OUR STORE*****************");
      fp1=fopen("samplecart.txt","w");
            	fclose(fp1);
      do{
      
      printf("\nEnter the category you want to purchase:\n\t1-Electronics\n\t2-Sports\n\t3-Eatables\n\t4-EXIT=");
       scanf("%d",&n);
       if(n==4){
         printf("Thank you for visiting our departmental store");
         exit(0);
         }
      switch(n){
           case 1:fp=fopen("electronics.txt","r");
                break;
           case 2:fp=fopen("sports.txt","r");
                break;
           case 3:fp=fopen("food.txt","r");
                break;
           default:printf("Invalid input");
              
      }
             printf("s.no---item---qantity--price");
            while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                printf("\n%d %s %d %d",d,a,b,c);
            }
            	do{
              		printf("\nEnter the item to add in to the cart");
            		scanf("%d",&cart);
            		printf("Enter the quantity :");
            		scanf("%d",&qan);
            		
            		fp1=fopen("samplecart.txt","a");
            		rewind(fp);
            	while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
            	
                   if(cart==d){
                    if(qan<=b){
                fprintf(fp1,"%d %s %d %d\n",sl,a,qan,qan*c);
                printf("\nyour %s is added to your cart",a);
                sl++;
                fclose(fp1);
                }
                   else
                     printf("\nOut of stock....only %d is remaning",b);
            }
            }
            printf("\nDo want to continue in this catagory[1/0]");
            scanf("%d",&c1);
            }while(c1==1);
             printf("\nenter the choice\n\t1-continue shopping\n\t2-check out");
             scanf("%d",&p);
              fclose(fp);
           }while(p==1);
           if(p==2)
              printf("your cart is\n");
              fp=fopen("samplecart.txt","r");
               while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                printf("\n%d %s %d %d",d,a,b,c);
            }   
            fclose(fp);
            printf("\nDo you want to edit your cart[1/0]");
            scanf("%d",&ed);
             if(ed==1)
                 {do{
                  printf("\n\t1-Edit quantity\n\t2-Add items");
                     scanf("%d",&edi);
                     if(edi==1)
                         edit();
                        else if(edi==2)
                          add(sl);
                  
                  printf("\n Do you want to continue editing your cart[1/0]");
                  scanf("%d",&cho);
              }while(cho==1);
              }
                  printf("GO FOR BILLING");
                  bill();
  }
