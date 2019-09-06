#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, u, v, d;

int Answer;
vector <int> answer;

vector<vector<int> > Dijkstra(int start,vector<vector<pair<int, int> > > edge)
{
    vector<int> dist(N + 1, -1);
    // for(int i=1;i<=N;i++)
    // {
    //     cout << dist[i] << endl;
    // }
    vector<vector<int> > path(N+1);
    priority_queue<pair<int, int> > pq; // first : dist , second : vertex_pos
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start)); // Min-Heap처럼 사용하기 위해 앞의 거리 인자에 -값을 곱해줌.
    while (!pq.empty())
    {
        int here = pq.top().second;
        int heredist = -pq.top().first;
        // cout << "here" << here << " " << heredist << endl;
        pq.pop();
        if (heredist > dist[here])
            continue;
        for (int i = 0; i < edge[here].size(); i++)
        {
            int there = edge[here][i].first;
            int nextdist = heredist + edge[here][i].second;
            cout << "there" << there << " " << nextdist << endl;
            cout <<  there << " : " << here << "   distthere :" << dist[there] << "   nextdist : " << nextdist << endl;

            if (dist[there] == -1)
            { //최단 거리 갱신
                dist[there] = nextdist;
                path[there].push_back(here);
                pq.push(make_pair(-nextdist, there));
            }
            else if(dist[there] == nextdist)
            {
                dist[there] = nextdist;
                path[there].pop_back();                
                path[there].push_back(here);
                pq.push(make_pair(-nextdist, there));
            }
            else if(dist[there] > nextdist)
            {
                dist[there] = nextdist;
                path[there].pop_back();                
                path[there].push_back(here);
            

                pq.push(make_pair(-nextdist, there));
            }
           
        }
    }
    // for(int i=1;i<=N;i++)
    // {
    //     if(i!=start&&path[i][0]!=start)
    //     {
    //         for(int j=0;j<path[path[i][0]].size();j++)
    //         {
    //             path[i].push_back(path[path[i][0]][j]);
    //         }
            
    //     }
        
    // }    
    // for(int i=1;i<=N;i++)
    // {
    //     if(i!=start)
    //     {
    //         path[i].pop_back();      
    //     }  
    // }   


    return path;
}

int main(int argc, char **argv)
{
    int T, test_case;
    /*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        
        cin >> N >> M;
        Answer=0;
        answer.resize(N+1);
        for(int i=1;i<=N;i++)
        {
           answer[i]=1;      
        //    cout << answer[i] << " ";  
        }
        // cout << endl;     
        vector<vector<pair<int, int> > > edge(N+1);
        for (int i = 0; i < M; i++)
        {
            cin >> u >> v >> d;
            edge[u].push_back(make_pair(v, d));
            edge[v].push_back(make_pair(u, d));
        }
        // for (int i = 1; i <= N; i++)
        // {
        //     for(int j=0;j<edge[i].size();j++)
        //     {
        //         cout << i << ":" << edge[i][j].first << ":" << edge[i][j].second << "  ";  
        //     }
        //     cout << endl;
        // }


        for(int i = 1; i <= N; i++)
        {
            vector<vector<int> > pathL=Dijkstra(i,edge);
            // cout << "path from" << i << endl; 
            for(int j=1;j<=N;j++)
            {
                // cout << "path " << j << " : ";
                for(int l=0;l<pathL[j].size();l++)
                {
                    // cout <<  pathL[j][l] << " ";
                    if(i!=pathL[j][l])
                    {
                        answer[pathL[j][l]]=0;
                    }
                }
                // cout << endl;
            }
        }
        for(int i=1;i<=N;i++)
        {
            if(answer[i]==1)
            {
                Answer++;
            }
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << " ";
        for(int i=1;i<=N;i++)
        {
            if(answer[i]==1)
            {
                cout << i << " " ;
            }
            
        }
        cout << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}