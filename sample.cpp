#include<bits/stdc++.h>
using namespace std;
int main(){
   string str="cat batman latt matter cat matter cat";
   string str1,str2;
   unordered_map<string,int> mp;
   int flag=0;
   int len=str.length();
   for(int i=0;i<str.length();i++){
      str1+=str[i];
      if(str[i]==' ' || i==len-1){
         mp[str1]++;
         str1="";      
      }
   }
   for(int i=0;i<str.length();i++){
      str1+=str[i];
      if(str[i]==' ' || i==len-1){
         if(mp[str1]>1){
            cout<<str1;
            mp[str1]=0;
         }
         str1="";
      }
   }
}
