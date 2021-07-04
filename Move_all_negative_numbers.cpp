#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
using namespace std;
int prime[100]={0};
void fun(int n){
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
}
int main(){
    fun(100);
    int n,count=0,p;
    cin>>n;
    for(int i=2;i<n/2;i++){
        if(n%i==0){
            if(prime[i]==0){
                p=i;
                break;
            }
        }
    }
    cout<<n-p;
    
}
// 371, 407, 1634, 8208, 9474, 54748, 92727, 93084, 548834, 1741725, 4210818, 9800817, 9926315, 24678050, 24678051, 88593477, 146511208, 472335975, 534494836, 912985153, and 4679307774.

// using namespace std;
// int allIndex(int arr[],int n,int num,int output[]){
//     if(n==7){
//         return 0;
//     }
//     int size=allIndex(arr,n+1,num,output);
//         if(arr[n]==num){
//             output[size]=n;
//             return size+1;
//         }
//         else    return size;
// }

// void Index(int arr[],int n,int num,int len){
    
//     int output[len];
//     int size=allIndex(arr,n,num,output);
//     for(int i=0;i<size;i++) {
//        cout<<output[i]<<"\n";

//     }
// }

// int main(){
//     int arr[]={2,2,3,2,4,2,2};
//     int n=0;
//     int num=2;
//     int len=sizeof(arr)/sizeof(arr[0]);
//     Index(arr,n,num,len);
// }
