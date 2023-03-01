#include <stdio.h>

int main()
{
    char a[]="AABBBCCCCddd";
    int n = sizeof(a)-1;
    int i=1,j;
    for(int k=0;k<n;k++){
        j=k+1;
        if(a[k]==a[j]){
            i=i+1;
        }else{
            printf("%c%d",a[k],i);
            i=1;
        }
    }
    return 0;
}
