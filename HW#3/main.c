#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int receipt_ip;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
} lotto_record_t;

int m,num[5][7];
void lottoNum(){
    int n,temp,k,i,j;
    for (k=0;k<m;k++){
        for(i=1;i<=7;i++){
            num[k][i-1]=(i!=7)?rand()%69+1:rand()%9+1;
            for(j=0;j<=i;j++){
                if(n==num[k][j]){
                    num[k][j]=(j!=7)?rand()%69+1:rand()%9+1;
                    j--;
                }
            }
        }
    }
    for(k=0;k<=5;k++){
        for(i=0;i<6;i++){
            for(j=0;j<i;j++){
                if(num[k][j]>num[k][i]){
                    temp=num[k][j];
                    num[k][j]=num[k][i];
                    num[k][i]=temp;
                }
            }
        }
    }
}
void if_lottery(int n,lotto_record_t record[],int prizenumber[3]) {
    for(int i=0;i<record[n].receipt_price;i++) {
        for(int j=0;j<7;j++) {
            for(int k=0;k<3;k++) {
                if(record[n].lotto_set[i][j]==prizenumber[k]) {
                    printf("彩卷 No. %d\n售出時間 : %s號碼 : ",record[n].receipt_ip,record[n].receipt_time);
                    for(int j=0;j<7;j++){
                        printf("%02d ",record[n].lotto_set[i][j]);
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }
}

int main()
{
    FILE*fp;
    FILE*fr;
    int n,prizenumber[3];
    printf("請問您要買幾個組樂透 ");
    scanf("%d",&n);
    printf("\n請輸入中獎號碼 (最多3個) : ");
    char k;
    int prize=0;
    do{
        scanf("%d",&prizenumber[prize]);
        prize++;
    }while(k=getchar()!='\n');
    printf("\n輸入中獎號碼為 : ");
    for(int i=0;i<3;i++) {
        if(prizenumber[i]!=0) {
            printf("%02d ",prizenumber[i]);
        }
    }
    int i,j,num[n][7];
    time_t t;
    time(&t);
    char *str=ctime(&t);
    lotto_record_t record[1];
    record[0].receipt_price=n;
    strcpy(record[0].receipt_time,str);
    int size=0;
    if(fr=fopen("record.bin","rb+")) {
        fseek(fr,0,SEEK_END);
        size=ftell(fr)/sizeof(lotto_record_t);
        fseek(fr,0,SEEK_SET);
    }else {
        record[0].receipt_ip=1;
    }
    lotto_record_t read_record[size];
    if(size>0) {
        for(int i=0;i<size;i++) {
            fread(&read_record[i],sizeof(lotto_record_t),1,fr);
        }
        record[0].receipt_ip=read_record[size-1].receipt_ip+1;
        fclose(fr);
    }
    if((fp=fopen("lotto.text","w+"))==NULL) {
        printf("Cannot open the file");
        exit(1);
    }
    fprintf(fp,"%s",  "======== lotto649 ========\n");
    fprintf(fp,"%s%02d%s","=======+ N0.0000",record[0].receipt_ip,"+=======\n");
    fprintf(fp,"%s%s","==",str);
    lottoNum();
    for(int i=n;i<5;i++) {
        fprintf(fp,"%s%d%s","[",i+1,"]: -- -- -- -- -- -- --\n");
    }
    fprintf(fp,"%s","======== csie@cgu ========\n");
    fr=fopen("record.bin","ab+");
    printf("\n以下為中獎彩卷 : \n");
    for(int i=0;i<size;i++) {
        if_lottery(i,read_record,prizenumber);
    }
    if_lottery(0,record,prizenumber);
    fwrite(record,sizeof(lotto_record_t),1,fr);
    fclose(fr);
    fclose(fp);

    return 0;
}
