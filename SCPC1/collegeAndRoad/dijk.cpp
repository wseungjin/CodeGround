#include <iostream>
#include <list>
#include <vector>


using namespace std;
#define MAX 10000000
#define V 5

int min(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

vector<int> dijk(int graph[V][V], int start)
{
    vector <int> dist;
    bool sptSet[V];
    int save;

    for(int i=0;i<V;i++)
    {
        dist.push_back(MAX);
        sptSet[i]=false;
    }
    dist[start-1]=0;
    

    for(int i=0;i<V;i++)
    {   

        int minDistance=MAX;

        for(int j=0;j<V;j++)
        {
            if(sptSet[j]==false&&minDistance>dist[j])
            {
                minDistance=dist[j];
                save=j;
            }
        }
        sptSet[save]=true;
        for(int j=0;j<V;j++)
        {
            if(dist[j]>dist[save]+graph[save][j])
            {
                dist[j]=dist[save]+graph[save][j];
            }
        }

    }

    


 
    return dist;
}

int main()  
{
    int graph[5][5]={{0,2,1,3,MAX},
                     {2,0,MAX,3,4},
                     {1,MAX,0,MAX,1},
                     {3,3,MAX,0,MAX},
                     {MAX,4,1,MAX,0}};


    for(int i=0;i<5;i++)
    {
        printf("%d %d\n",i+1,dijk(graph,1)[i]);
    }

}