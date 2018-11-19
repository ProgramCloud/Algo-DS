#include<iostream> 
#include<list> 
using namespace std; 
class Graph 
{ 
 int v;
 list<int> *adj;
 void DFSutil(int v,bool visited[]);
public:
 Graph(int v);
 void addEdge(int v,int w);
 void connected();
};
Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::DFSutil(int v,bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";
	list<int>::iterator i;
	for(i=adj[v].begin();i!=adj[v].end();i++)
	{
		if(!visited[*i])
			DFSutil(*i,visited);
	}
}
void Graph::connected()
{
	int count=0;
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	cout<<"Connected Components-"<<endl;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			DFSutil(i,visited);
			count++;
			cout<<"\n";
		}
	}
	cout<<"Number of Connected componenets-"<<count;
	
}
  
int main() 
{ 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
  
    g.connected(); 
  
    return 0; 
} 
