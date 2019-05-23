#include <stdio.h>

int count=0;

void merge(int a[10],int low,int mid,int high)
{
    count++;
    int temp[high-low+1],i,j,k=0;
    i=low;
    j=mid+1;
    
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=mid)
        temp[k++]=a[i++];
    
    while(j<=high)
        temp[k++]=a[j++];
        
    for(i=low;i<=high;i++)
        a[i]=temp[i-low];
}

void m_sort(int a[10],int low, int high)
{
    // count++;
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        m_sort(a,low,mid);
        m_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main(void) 
{
	int a[10],n,i;
	
	printf("Enter y Size: ");
	scanf("%d",&n);
	
	printf("Enter array elements to sort:\n");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}
	
	m_sort(a,0,n-1);
	
	printf("Sorted Array is:\n");
	for(i=0;i<n;i++)
	{
	    printf("%d ",a[i]);
	}
	
	printf("\nOPERATION COUNT=%d",count);
	return 0;
}

