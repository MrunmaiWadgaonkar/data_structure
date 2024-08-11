#include<stdio.h>
void main()
{
	int a[100],n,i,j,t,min=0;
	printf("enter dimension of array\n");
	scanf("%d",&n);
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
	}
	printf("sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
