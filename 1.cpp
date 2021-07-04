#include<iostream>
using namespace std;
void sorting(int arr[],int kth,int size){
	int i,j,temp;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	cout<<"\n"<<"Sorted arr-->";
	for(i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n"<<"kth element-->"<<arr[kth-1];
	
}

int main(){
	int i,noArray,kElement,arraySize;
	int arr[10];
	// cout<<"enter number of array u want-->";
	cin>>noArray;
	while(noArray>0){
		// cout<<"\n"<<"Enter no of elements in array-->";
		cin>>arraySize;
		// cout<<"\n"<<"array elements-->";
		for(i=0;i<arraySize;i++){
			cin>>arr[i];
		}
		// cout<<"\n"<<"Enter kth smallest element-->";
		cin>>kElement;
		sorting(arr,kElement,arraySize);
		// for(i=0;i<arraySize;i++){
		// 	cout<<arr[i]<<" ";
		// }
		// cout<<"-->"<<kElement<<"\n";
		noArray--;
	}
	
}