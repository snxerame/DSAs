#include <stdio.h>
#include<string.h>
int main()
{
    //initialization and input 
    char a[100];
    char b[100];
    scanf("%[^\n]",a);
    getchar();
    scanf("%[^\n]",b);
    getchar();
    int lenA = strlen(a);
    int lenB = strlen(b);
    int carry = 0;
    char output[101];
    char out[101];
    
    //fulladder
    for(int i=0;i<lenB;i++)
    {
       int digit = a[lenA-i-1] + b[lenB-i-1] + carry -96 ;
       
      if(digit>9)
       {
           digit = digit -10;
           carry = 1;
       }
       else
       carry =0;
       output[i]=digit+48;
    }
    
    //halfadder
    for(int j=lenB;j<lenA;j++)
    {
        int digit = a[lenA-j-1] + carry - 48 ;
      if(digit>9)
       {
           digit = digit -10;
           carry = 1;
       }
       else
       carry = 0;
       
       output[j]=digit+48;
    }
    
    //Carry out 
    if(carry == 1)
    output[lenA]=1+48;
    
    //reversing array
    for(int k=0;k<strlen(output);k++)
    out[k]=output[strlen(output)-k-1];
    
    puts(out);
}
