#include <iostream>
using namespace std;

void print_title(){
    cout<<"-- Tic Tac Toe -- CSIE@CGU"<<endl;
    cout<<"Player 1 (X)  -  Player 2 (O)"<<endl;
    cout<<endl;
}

void print_background(char a[]){
        for(int i=0;i<9;i+=3){
            cout<<"   ▉     ▉   "<<endl;
            cout<<" "<<a[i]<<" ▉  "<<a[i+1]<<"  ▉  "<<a[i+2]<<"   "<<endl;
            cout<<"   ▉     ▉   "<<endl;
            if(i!=6){
                cout<<"■■■■■■■■■■■■■■■"<<endl;                
            }
        }
        cout<<endl;
}
void choose_number(int count,char a[]){
    int temp;
    int detect=0;
    cout<<"Player "<<count%2+1<<",請輸入『1~9』的數字：";
    cin>>temp;
    temp+=48;
    for(int i=0;i<=9;i++){
        if(temp==int(a[i])){
            if(count%2==0){
                a[i]='X';
            }
            else{
                a[i]='O';
            }
            detect=1;
        }
    }
    if(detect==0){
            cout<<"請重新輸入下一步"<<endl;
            choose_number(count,a);
        }
}
int whowin(char a){
    if(a=='X'){
        cout<<endl;
        cout<<"==>Player 1 win !";
        return 1;
        }
    else {
        cout<<endl;
        cout<<"==>Player 2 win !";
        return 1;
    }

}
int play(int count ,char a[]){
    for (int i=0;i<9;i++){
        if(i%3==0){
            if(a[i]==a[i+1]&&a[i]==a[i+2]){
                print_title();
                print_background(a);
                return whowin(a[i]);
            }
        }
        if(i<3){
            if(a[i]==a[i+3]&&a[i]==a[i+6]){
                print_title();
                print_background(a);
                return whowin(a[i]);
            }
        }
        if(i==0||i==2){
            if(a[i]==a[4]&&a[i]==a[i+6]){
                print_title();
                print_background(a);
                return whowin(a[i]);
            }
        }
    }
}
class TicTacToe{
    public:
    char num_array[9];
    TicTacToe(){
        for(int i=0;i<9;i++){
            num_array[i]=i+49;
        }
    }
    void run(){
        for(int i=0;i<9;i++){
            print_title();
            print_background(num_array);
            choose_number(i,num_array);
            if(play(i,num_array)==1){
                break;
            }
        }
    }
};

int main()
{
    TicTacToe game; 
    game.run();
    return 0;
}
