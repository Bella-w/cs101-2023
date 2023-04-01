#include <stdio.h>
int main(){
//     目的 : 將串列a中的 Hello!倒過來輸出
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
// 輸出結果為!olleH 
