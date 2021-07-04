// C++ Program to display marks of 5 students

#include <iostream>
using namespace std;

// declare function to display marks
// take a 1d array as parameter
void display(int arr[],int size) {
    int i,j,temp;
    cout<<"arrrrrrrrrr";
    for (i=0;i<size;i++){
    	cout<<arr[i]<<" ";
    }
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
		for(i=0;i<size;i++){
			cout<<"\n"<<arr[i]<<" ";
		}
}

int main() {

    // declare and initialize an array
    int arrSize=5,i;
    int marks[arrSize];
    for (i=0;i<arrSize;i++){
    	cin>>marks[i];
    }
    
    display(marks,arrSize);

    return 0;
}