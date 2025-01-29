//1.  Pick toys
John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys.


Example:
Input:
1
abaccab


#include<iostream>
#include<algorithm>
#include<map>
#define INT_MIN (-2147483647 - 1)
using namespace std;
int main(){
    string s;
    cin>>s;
    int k,j=0,i=0;
    k=2;
    map<char,int>m;
    int ans=0;
    while(j<s.size()){
        m[s[j]]++;
        if(m.size()<k){
            j++;
        }else if(m.size()==k){
            ans=max(ans,j-i+1);
            j++;
        }else{
            while(m.size()>k){
                m[s[i]]--;
                if((m[s[i]]==0)){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout<<ans;
}

//2. Minimum window substring

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string smallestWindow (string s, string p)
{
    // Your code here
    map<char,int>m;
    int n=s.size();
    for(int i=0;i<p.size();i++){
        m[p[i]]++;
    }
    int c=m.size();
    int i=0,j=0;
    int resStart=0,reslen=INT_MAX;
    while(j<n){
        m[s[j]]--;
        if(m[s[j]]==0){
            c--;
        }
        if(c==0){
            while(c==0){
                if(reslen>(j-i+1)){
                    reslen=j-i+1;
                    resStart=i;
                }
                m[s[i]]++;
                if(m[s[i]]>0){
                    c++;
                }
                i++;
            }
        }
        j++;
            
    }
    if(reslen==INT_MAX){
        return "-1";
    }
    return s.substr(resStart,reslen);
}
int main(){
    string s,p;
    cin>>s>>p;
    cout<<smallestWindow(s,p);
}


