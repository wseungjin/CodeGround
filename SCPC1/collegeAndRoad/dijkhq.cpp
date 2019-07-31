#include <cstdio>
#include <queue>
#include <map>
#include <stack>
#include <vector>

using namespace std;

#define MAX 10000000

class Graph
{
    int n=0;
    vector<Vertex> vt;
    priority_queue<Vertex> pq;

    vector<int> dijk(int s)
    {
        vector<int> dist(n, -1* MAX);
        vector<int> found(n,0);
        dist[s-1]=0;

        for(int i=0;i<n;i++)
        {
            pq.push(vt[i]);
        }

        while(!pq.empty)
        {
            int index = pq.top().index-1;
            int minDistance=pq.top().eg[1].dist;
            if(dist[index]>
            
            
            )
            
        }

        return dist;

    } 
};

class Vertex
{
public :
    int index;
    vector<Edge> eg;

};

class Edge
{
public :
    int dest;
    int dist;    
};

int main