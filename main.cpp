#include <bits/stdc++.h>
using namespace std;
char s[1000005];
string tmp;
int len=0;
bool isAlpha(char x){
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}
bool isNum(char x){
    return (x >= '0' && x <= '9');
}
int main(){
    char c;
    while((c=getchar())!=EOF){
        s[len++]=c;
    }
    map<string,string> m;
    map<string,string>::iterator iter;
    m.insert(pair<string,string>("BEGIN","Begin"));
    m.insert(pair<string,string>("END","End"));
    m.insert(pair<string,string>("IF","If"));
    m.insert(pair<string,string>("THEN","Then"));
    m.insert(pair<string,string>("ELSE","Else"));
    s[len]='?';
    tmp="";
    for(int i=0;i<len;i++,tmp=""){
        if((s[i]>=9&&s[i]<=13)||s[i]==32){
            tmp="";
        }else if(isAlpha(s[i])){
            tmp+=s[i];
            while(isAlpha(s[i+1])||isNum(s[i+1])){
                i++;
                tmp+=s[i];
            }
            iter=m.find(tmp);
            if(iter!=m.end()){
                cout<<iter->second<<"\n";
            }else{
                cout<<"Ident("<<tmp<<")"<<"\n";
            }
            continue;
        }else if(isNum(s[i])){
            tmp+=s[i];
            while(isNum(s[i+1])){
                i++;
                tmp+=s[i];
            }
            cout<<"Int("<<stoi(tmp)<<")"<<"\n";
            continue;
        }else if(s[i]==':'){
            if(s[i+1]=='='){
                i++;
                cout<<"Assign"<<"\n";
            }else{
                cout<<"Colon"<<"\n";
            }
        }else if(s[i]=='+'){
            cout<<"Plus"<<"\n";
        }else if(s[i]=='*'){
            cout<<"Star"<<"\n";
        }else if(s[i]==','){
            cout<<"Comma"<<"\n";
        }else if(s[i]=='('){
            cout<<"LParenthesis"<<"\n";
        }else if(s[i]==')'){
            cout<<"RParenthesis"<<"\n";
        }else{
            cout<<"Unknown"<<"\n";
            break;
        }
    }
    return 0;
}