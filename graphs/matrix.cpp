#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cout<<"no of nodes";
	cin>>n;
	vector<vector<int> > adj(n,vector<int>(n,0));
	int e;
	cout<< "enter no. of edeges";
	cin>>e;
	int u,v;
	for(int i =0;i<n;i++){
		cin>>u>>v;
		adj[u][v]=1;
	}
	for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
		cout<<adj[i][j];
	}
	}
	return 0;
}