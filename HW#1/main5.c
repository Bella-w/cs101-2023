#include <stdio.h>

int main(){
    char a[] = "-99acbc";
    char b[] = "99acbc";
    char c[] = "ac-99bc";
    for(int i = 0 ; i < ((int)sizeof(a)/sizeof(char)-1) ; i++){
        if((a[i] >= 48 && a[i] <= 57) || a[i] == 45){
            printf("%c", a[i]);
        }
    }
    printf("\n");
    for(int i = 0 ; i < ((int)sizeof(b)/sizeof(char)-1) ; i++){
        if((b[i] >= 48 && b[i] <= 57) || b[i] == 45){
            printf("%c", b[i]);
        }
    }
    printf("\n");
    for(int i = 0 ; i < ((int)sizeof(c)/sizeof(char)-1) ; i++){
        if((c[i] >= 48 && c[i] <= 57) || c[i] == 45){
            printf("%c", c[i]);
        }
    }
    printf("\n");
    return 0;
}
