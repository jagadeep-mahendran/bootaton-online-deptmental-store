#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void add(int sl){
 int n,d,b,c1,c,cart,qan,edi,cho,ed,p;
      FILE *fp,*fp1;
      char a[10];
      
      printf("\nEnter the category you want to purchase again:\n\t1-Electronics\n\t2-Sports\n\t3-Eatables\n\t4-EXIT=");
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
                 
                fprintf(fp1,"%d %s %d %d\n",sl,a,qan,qan*c);
                printf("\nyour %s is added to your cart",a);
                sl++;
                fclose(fp1);
            }
            }
            printf("\nDo want to continue in this catagory[1/0]");
            scanf("%d",&c1);
            }while(c1==1);
       }
struct cusmod
{
    char name[25];
    int p;
    int s;
    int e;
}stu;

void append(int r,int q){

   FILE *fh,*fh1,*fh2,*fp;
fh=fopen("samplecart.txt","r");
fh1=fopen("temp.txt","w");
fh2=fopen("bct.txt","r");

    int n,y;
    int tee;
    /*while(fscanf(fh2,"%d %s %d",&stu.s,&stu.name,&stu.p)!=EOF)
    { if(r==stu.s)
       {
           tee=stu.p; break;}
       }
       printf("%d",tee);

    fclose(fh2);*/
    n=fscanf(fh,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p);
    do
    {if(stu.s!=r)
         {fprintf(fh1,"%d %s %d %d\n",stu.s,stu.name,stu.e,stu.p);

          n=fscanf(fh,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p);}
        else
            { tee=stu.p/stu.e;
                fprintf(fh1,"%d %s %d %d\n",stu.s,stu.name,q,q*tee);
               n=fscanf(fh,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p);

                }


    }while(n!=EOF );
    fclose(fh);
    fclose(fh1);
    remove("samplecart.txt");
    rename("temp.txt","samplecart.txt");
    fp=fopen("samplecart.txt","r");
    while(fscanf(fp,"%d %s %d %d",&stu.s,stu.name,&stu.e,&stu.p)!=EOF)
    {
        printf("%d %s %d %d\n",stu.s,stu.name,stu.e,stu.p);
    }
    fclose(fp);
}
void edit()
{ int q,r;
       printf("Enter the s.no of the item to be modified ");
        fflush(stdin);
        scanf("%d",&r);
        printf("Enter the updated quantity: ");
        scanf("%d",&q);
        append(r,q);
        fflush(stdin);
    
}
