#include<stdio.h>
int main()
{
    int target;
    int size;
    int array[1000000];
    
    scanf("%d",&size);
    scanf("%d",&target);
    
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);
    }
    
    int left = 0;
    int right = size-1;
    int mid;
    
    while(left<=right)
    {
        mid = left + (right - left)/2;
        
        if(array[mid] == target)
        {
            printf("%d",mid+1);
            return 0;
        }
        if(array[mid]>target)
        {
            right = mid -1;
        }
        if(array[mid]<target)
        {
            left=mid+1;
        }
    }
}
