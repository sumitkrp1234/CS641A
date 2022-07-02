#include <iostream>
#include<bits/stdc++.h>
using namespace std;
# define ll long long

int main(){
    char c;
    string str;
    while(std::cin>>c){
        str.push_back(c);
    }
    
    string key="CRYPTANALYSIS";
    vector<vector<char>>v(5,vector<char>(5,'.'));
    vector<bool> vis(26,false);
    ll row=0;
    ll col=0;
    ll j=0;
    vector<pair<ll,ll>> pos(26);
    for(ll i=0;i<key.size();i++){
    	if(vis[key[i]-'A']!=true){
    		vis[key[i]-'A']=true;
    		if(key[i]=='I' || key[i]=='J'){
    			vis[8]=true;
    			vis[9]=true;
    		}
    		if(col==5) {
    			v[++row][0]=key[i];
    			col=1;
    		}
    		else{
    			v[row][col]=key[i];
    			col++;
    		}
    	}
    }
    for(ll i=0;i<26;i++){
    	if(vis[i]!=true){
    		if(col==5 && row<=4) {
    			v[++row][0]=i+'A';
    			col=1;
    		}
    		else{
    			v[row][col]=i+'A';
    			col++;
    		}
    	}
    }
    for(ll i=0; i<5;i++){
    	for(ll j=0;j<5;j++){
    		if(v[i][j]!='I'&& v[i][j]!='J'){
    			cout<<v[i][j]<<" ";
    			pos[v[i][j]-'A']= make_pair(i,j);
    		}
    		else {
    			cout<<"I/J"<<" ";
    			pos[8]=make_pair(i,j);
    			pos[9]=make_pair(i,j);
    		}
    	}
    	cout<<endl;
    }

    ll cnt=0;
    for(ll i=0;i<str.size();i++){
        if(str[i]== '\"' || str[i]=='.' || str[i]=='_' || str[i]==',' || str[i]==' ') {

        }
        else cnt++;
    }
    cout<<"Count of total number of english letters = "<<cnt<<endl;
    for(ll i=0;i<str.size();){
        if(str[i]== '\"' || str[i]=='.' || str[i]=='_' || str[i]==',') {
            i++;
            continue;
        }
        ll row1=pos[(str[i]-'A')].first;
        ll col1=pos[(str[i]-'A')].second;
        ll flag=0;
        if(str[i+1]== '\"' || str[i+1]=='.' || str[i+1]=='_' || str[i+1]==','){
            i++;
            flag=1;
        }
        ll row2=pos[(str[i+1]-'A')].first;
        ll col2=pos[(str[i+1]-'A')].second;
        if(flag==0) cout<<str[i]<<" ";
        else cout<<str[i-1]<<" ";
        cout<<str[i+1]<<" ";
        cout<<row1<<" "<<row2<<" "<<col1<<" "<<col2<<" ";
        if(row1!=row2 && col1!=col2){
            if(flag==0)str[i]=v[row1][col2];
            else str[i-1]=v[row1][col2];
            str[i+1]=v[row2][col1];
        }
        else if(row1==row2){
            if(flag==0)str[i]=v[row1][(col1+4)%5];
            else if(flag==1) str[i-1]=v[row1][(col1+4)%5];
            str[i+1]=v[row2][(col2+4)%5];
        }
        else if(col1==col2){
            if(flag==0) str[i]=v[(row1+4)%5][col1];
            else str[i-1]=v[(row1+4)%5][col1];
            str[i+1]=v[(row2+4)%5][col2];   
        }

        if(flag==0) cout<<str[i]<<" ";
        else cout<<str[i-1]<<" ";
        cout<<str[i+1]<<" ";
        cout<<endl;
        i+=2;
    }
    cout<<str<<endl;

}