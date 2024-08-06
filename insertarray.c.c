#include<stdio.h>
void main()
{
	int a[100],b[100],i,j,n,pos,item;
	printf("enter dimension of array\n");
	scanf("%d",&n);
	printf("enter elements in array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nenter the position at which you want to insert an element\n");
	scanf("%d",&pos);
	printf("enter the element you want to insert\n");
	scanf("%d",&item);
	for(i=0;i<pos-1;i++)
	{
		b[i]=a[i];
	}
	b[pos-1]=item;
	for(i=pos;i<=n;i++)
	{
		b[i]=a[i-1];
	}
	printf("updated array is\n");
	for(i=0;i<=n;i++)
	{
		printf("%d\t",b[i]);
	}
}
