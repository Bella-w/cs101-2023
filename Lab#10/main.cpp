#include <iostream>
#include<string>
#include<fstream>
using namespace std;

class myString{
    private:
        string m_str;
    public:
        myString(string s){
            m_str=s;
        }
};

class ReadClass{
    public:
        void showClass(){
            ifstream in;
            string line,all;
            int count=0;
            in.open("main.cpp");
            if(in.fail()){
                cout<<"Error opening a file"<<endl;
                in.close();
            }
            while(getline(in,line)){
                if(line[0]=='c'&&line[1]=='l'&&line[2]=='a'&&line[3]=='s'&&line[4]=='s'){
                    count++;
                    line[line.size()-1]='\0';
                    all=all+(line+'\n');
                }
            }
            cout<<count<<" class in main.cpp"<<endl;
            cout<<all<<endl;
            in.close();
        }
};

int main()
{
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
