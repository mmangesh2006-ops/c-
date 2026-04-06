#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void reverseVector (vector<int> &arr){
	stack<int> st;
	
	for(int i=0;i<arr.size();i++){
		st.push(arr[i]);
	}
	
	for(int i=0;i<arr.size();i++){
		arr[i]=st.top();
		st.pop();
	}
}

void display(vector<int> &arr){
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";	
	}
}

int main(){
	vector<int> arr ;
	int n;
	cout<<"enter no. of elements"<<endl;
	cin>>n;
	cout<<"enter the elements"<<endl;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	reverseVector(arr);
	display(arr);
	return 0;
}
