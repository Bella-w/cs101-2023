#include <stdio.h>
void multi(int i,int j){

        if(i==9&&j==9){
            printf("%d*%d=%d\n",i,j,i*j);
            return ;
        }
        else{
            if(j==9){
                printf("%d*%d=%d  ",i,j,i*j);
                multi(i,j+1);
            }
            else if(i==9){
                printf("%d*%d=%d  ",i,j,i*j);
                multi(i+1,j);
            }
        } 
       
}
int main()
{
    multi(1,1);
    return 0;
}
