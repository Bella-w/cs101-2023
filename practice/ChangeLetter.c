#include <stdio.h>
int main(){
    char a[]="Hello!";
    int n=sizeof(a);
    int m=n-1;
    for(n;n>=0;n--){
        char b=a[n];
        printf("%c",b);
        m--;
    };
    return 0;
}
