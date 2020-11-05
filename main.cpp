#include <iostream>
#include <string>
#include <map>
using namespace std;
int p=-1;
int cur;
char opg_stack [5005];
map<char,int> stin{{'+',0},{'*',1},{'i',2},{'(',3},{')',4},{'#',5}};
map<char,int> stout{{'+',0},{'*',1},{'i',2},{'(',3},{')',4},{'#',5}};
int opg_martix [6][6]={{1,-1,-1,-1,1,1},{1,1,-1,-1,1,1},{1,1,100,100,1,1},{-1,-1,-1,-1,0,100},{1,1,100,100,1,1},{-1,-1,-1,-1,100,0}};
int main(){
    string s;
    cin>>s;
    opg_stack[++p]='#';
    cur=p;
    s.insert(s.size(),1,'#');
    for(int i=0;i<s.size();){
        //for(int j=0;j<=p;j++){
          //  cout<<opg_stack[j];
        //}
        //cout<<s[i]<<"!"<<endl;
        //cout<<opg_stack[p]<<"!"<<endl;
        cur=p;
        if(!stout.count(s[i])){
            cout<<"E"<<endl;
            break;
        }else{
            int tmp=p;
            while(opg_stack[p]=='N'){
                p--;
            }
            cur=p;
            p=tmp;
            //cout<<opg_stack[cur]<<"!"<<s[i]<<endl;
            if(opg_martix[stin[opg_stack[cur]]][stout[s[i]]]==100){
                cout<<"E"<<endl;
                break;
            }else if(opg_martix[stin[opg_stack[cur]]][stout[s[i]]]==-1){
                opg_stack[++p]=s[i];
                //cout<<opg_stack[p]<<endl;
                cout<<"I"<<s[i]<<endl;
                i++;
            }else if(opg_martix[stin[opg_stack[cur]]][stout[s[i]]]==1){
                if(cur==p&&opg_stack[cur]!='i'){
                    //cout<<opg_stack[cur]<<endl;
                    //cout<<s[i]<<endl;
                    cout<<"RE"<<endl;
                    break;
                }else if(opg_stack[p]=='#'&&s[i]!='i'){
                    cout<<"RE"<<endl;
                    break;
                }else{
                    while(opg_stack[cur]=='N'||opg_martix[stin[opg_stack[cur]]][stout[s[i]]]==1){
                        if(opg_martix[stin[opg_stack[cur]]][stout[s[i]]]==1&&opg_stack[cur]!='N'){
                            //cout<<opg_stack[cur];
                           cout<<"R"<<endl;
                        }
                        cur--;
                    }
                    p=cur+1;
                    opg_stack[p]='N';
                    //cout<<"R"<<endl;
                }
            }
            else if(opg_martix[stin[opg_stack[cur]]][stout[s[i]]]==0){
                //cout<<"KKK"<<endl;
                if(cur==p&&s[i]==')'){
                    cout<<"RE"<<endl;
                    break;
                }else if(s[i]=='#'){
                    //cout<<"R";
                    break;
                }else{
                    cout<<"I"<<s[i]<<endl;
                    i++;
                    p=cur;
                    opg_stack[p]='N';
                    cout<<"R"<<endl;
                }
            }
        }
    }
    return 0;
}
