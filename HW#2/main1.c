#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int m,n[5][7];
void lottoNum(){
    int num,temp;
    for (int k=0;k<m;k++){
        for(int i=1;i<=7;i++){
            n[k][i-1]=(i!=7)?rand()%69+1:rand()%9+1;
            for(int j=0;j<=i;j++){
                if(num==n[k][j]){
                    n[k][j]=(j!=7)?rand()%69+1:rand()%9+1;
                    j--;
                }
            }
        }
    }
    for(int k=0;k<=5;k++){
        for(int i=0;i<6;i++){
            for(int j=0;j<i;j++){
                if(n[k][j]>n[k][i]){
                    temp=n[k][j];
                    n[k][j]=n[k][i];
                    n[k][i]=temp;
                }
            }
        }
    }
}
void printFile(){
    FILE *lotto;
	int i,j;
	time_t t=time(0);
	char *c=ctime(&t);
	c[strlen(c)-1]=0;
	lotto =fopen("lotto.txt","w+");
	fprintf(lotto,"========= lotto649 =========\n");
	fprintf(lotto,"= %s =",c);
	for(i=1;i<=5;i++){
		fprintf(lotto,"\n[%d]: ",i);
		if(i<=m)
			for(j=0;j<7;j++)
				fprintf(lotto,"%02d ",n[i-1][j]);
		else
			fprintf(lotto,"-- -- -- -- -- -- --");
	}
	fprintf(lotto,"\n========= csie@CGU =========");
	fclose(lotto);
}
int main()
{
    srand(time(0));
	printf("歡迎光臨長庚樂透彩購買機台\n"
		   "請問您要買幾組樂透彩：");
	scanf("%d",&m);
	printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n",m);
    lottoNum();
    printFile();
    return 0;
}
