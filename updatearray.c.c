#include<stdio.h>   
void main()   
{  
 int a[100],n,item,updates,upd_ele,i,j,found=0;
 printf("enter dimension of array\n");
 scanf("%d",&n);
 printf("enter array elements\n");
 for(i=0;i,n;i++)
 {
   scanf("%d",&a[i]);
 }
 printf("enter the number of elements you want to update\n");
 scanf("%d",&updates);
 for(j=0;j<updates;j++)
 {
   printf("enter the element you want to update\n");
   scanf("%d",&item);
   for(i=0;i<n;i++)
   {
      if(item==a[i])
      {
         found=1;
         printf("enter the element you want to update with\n");
         scanf("%d",&upd_ele);
         a[i]=upd_ele;
         break;
      }
   }
   if(found==0)
   {
      printf("element is not present in array");
   }
 }
 printf("updated array is\n");
 for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
 }
}
  
