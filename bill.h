#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 void bill(){
      int n,d,b,c,q=0,sum=0,ph,ch,y,y1,p,f=0,ot;
      float gst,bill;
      FILE *fp;
      char a[10],x[10],nam[20],nam1[20],nam2[20],x1[20];
     
              printf("\nyour cart is\n");
              fp=fopen("samplecart.txt","r");
               while(fscanf(fp,"\n%d %s %d %d",&d,a,&b,&c)!=EOF){
                printf("\n%d %s %d %d",d,a,b,c);
                   sum=sum+c;
                   q=q+b;
            } 
            fclose(fp);  
            gst=0.18*sum;
            bill=gst+sum;
            printf("\n-------------TOTAL AMOUNT:%d",sum);
            printf("\n-----------TOTAL QUANTITY:%d",q);
            printf("\n----------------------GST:%2.f",gst);
            printf("\n-------YOUR FINAL BILL IS:%2.f\n",bill);
            printf("\nEnter your name:");
            scanf("%s",nam);
            printf("\nEnter your contact number");
            scanf("%d",&ph);
            printf("\nSELECT YOUR PAYMENT MODE:\n\t1.Debit card\n\t2.cash");
            scanf("%d",&ch);
            if(ch==2)
                printf("\nPay %f to the cashier",bill);
             else if(ch==1)
                 {
                    printf("\nEnter card number");
                    scanf("%s",x);
                    printf("\nEnter cvv:");
                    scanf("%d",&y);
                    printf("\nEnter card holder name: ");
                    scanf("%s",nam2);
                    p=ph%1000;
                    fp=fopen("payment.txt","r");
                     while(fscanf(fp,"%s %d %s\n",x1,&y1,nam1)!=EOF){
                     
                                   if(strcmp(x,x1)==0&& y==y1 && strcmp(nam1,nam2)==0)
                                        {
                                           printf("\nEnter the OTP sent to your mobile number *******%d",p);
                                           scanf("%d",&ot);
                                           f=1;
                                          }
                     }
                     if(f==0)
                        printf("\nInvalid card number or cvv\nPay %.2f to the cashier",bill);
                 }
                 printf("\n%s Thank you for visiting our store",nam);
                 fclose(fp);
        
  }
