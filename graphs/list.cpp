#include<iostream>
#include<unordered_list>
#include<list>
using namespace std;
class graph{
unordered_map<int,list<pair<int,int> > > adjlist;
void addEdge(int u,int v , int weight , bool direction){
    adjlist[u].push_back(v,weight);
    if(direction==0){
        adjlist[v].push_back(u,weight);
    }
}
void print(){
    for(auto node: adjlist){
        cout<<node.first;
        for(auto neighbourhood: node.second){
            cout<<"(<<"neighbourhood.first<<","<<neighbourhood.second<<"),";
        }
        cout<<endl;
    }
}
};
int main(){
    graph g;
    g.addEdge(1,0,4,0);
    g.print();
}
