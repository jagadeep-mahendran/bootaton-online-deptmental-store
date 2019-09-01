#include<stdio.h>
#include<string.h>
#include "cos.h"
#include "admin.h"
void login(){
    char a[50],x[50],y[50],y1[50],z[50],s[50];
    int test,g=0,f=0;
    FILE *fp;
    printf("\n**********WELCOME TO BOOMERANG DEPARTMANTAL STORE*************\n");
    printf("\n***********************Login********************************");
    printf("\nEnter the mail id:");
    scanf("%s",a);
    fp= fopen("mailid.txt", "r");
   while (fscanf(fp,"%s",x) != EOF) {
    //printf("%s",x);
   // printf("\n%s",a);
    test = strcmp(a,x);
    if(test==0)
         {
            printf("\n-----YOU ARE A ADMIN");
            printf("\n------------PASSWORD:");
            scanf("%s",y);
            rewind(fp);
            g=1;
                   while(fscanf(fp,"%s %s %s\n",z,y1,s)!= EOF){
                        if(strcmp(y,y1)==0 && strcmp(z,a)==0){
                            printf("\n                ACCESS GRANTED\n                  Hiii %s\n",s);
                             admin();
                            f=1;
                            }
                    }  
                  if(f==0)
                  printf("               ACCESS DENIED\n");  
                  break;
         
      }
      }
      if(g==0)
        {
         printf("you are a costomer");
        costumer();
        }
    fclose(fp);
}
