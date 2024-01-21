#include<stdio.h>
int main()
{
    int size;
    scanf("%d",&size);
    int array[size];
    for(int i=0;i<size;i++)
        scanf("%d",&array[i]);
    int left = 0;
    int right = size-1;
    int mid;
    while(left<=right)
    {
        mid = left + (right - left)/2;
        
        if((array[mid]>=array[mid-1])&&(array[mid]>=array[mid+1]))
        {
            printf("%d",mid+1);
            return 0;
        }
        if((array[mid]>array[mid-1])&&(array[mid]<array[mid+1]))
        {
            left = mid + 1;
        }
        if((array[mid]<array[mid-1])&&(array[mid]>array[mid+1]))
        {
           right = mid -1;
        }
    }
}
