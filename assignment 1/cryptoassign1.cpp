#include <iostream>
#include<bits/stdc++.h>
using namespace std;
# define ll long long

char substitution(char c){
    string s1="g_emftoahpswrbicnyv_lu_qd_";
    if(c>='a' && c<='z'){
        return s1[c-'a'];
    }
    else if(c>='A' && c<='Z'){
        return s1[c-'A']+'A'-'a';
    }
    else if(c>='0' && c<='9'){
        return (c-'6'+10)%10 +'0';
    }
    return c;
}
int main(){
    vector<string> s;
    string str;
    while(std::cin>>str){
        s.push_back(str);
    }
    map<char,ll>mp;
    ll sum=0;
    for(ll i=0;i<s.size();i++){
        for(ll j=0;j<s[i].size();j++){
            if(s[i][j]>='a' && s[i][j]<='z' ){
                mp[s[i][j]]++;
                sum++;
            }
            else if(s[i][j]>='A' && s[i][j]<='Z'){
                mp[s[i][j]-'A'+'a']++;
                sum++;
            }
        }
    }
    
    for(auto x:mp){
        cout<<x.first<<" "<<(float)((x.second)*100.0)/sum<<endl;
    }
    for(ll i=0;i<s.size();i++){
        for(ll j=0;j<s[i].size();j++){
            s[i][j]=substitution(s[i][j]);
        }
    }
    for(ll i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }

	return 0;
}



