#include<stdio.h>
int main()
{
	int a[50],b[50],i,j,pos,n;
	printf("enter dimension of array\n");
	scanf("%d",&n);
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nenter the position from which you want to delete an element\n");
	scanf("%d",&pos);
	for(j=0;j<pos-1;j++)
	{
		b[j]=a[j];
	}
	for(j=pos-1;j<n;j++)
	{
		b[j]=a[j+1];
	}
	printf("updated array is\n");
	for(j=0;j<n-1;j++)
	{
		printf("%d\t",b[j]);
	}
	return 9;
}
