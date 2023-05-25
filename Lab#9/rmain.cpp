#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMyString{
public:    
    void replaceString(string s1,string s2){
        string str;
        ifstream in("main.cpp");
        ofstream out("rmain.cpp");
        while(!in.eof()){
            getline(in,str);
            for(int i=0;i<str.size();i++){
                if(str[i]==s1[0]&&str[i+1]==s1[1])
                    str.replace(str.begin()+i,str.begin()+i+2,s2);
            }
            out<<str<<endl;
        }
    }
};

int main(){
    ReplaceMyString my;
    my.replaceString("IU is best","IU is best is best");
    return 0;
}
