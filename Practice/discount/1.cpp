/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

#define INF 100000

using namespace std;

int Answer;
int map[101][101];
int visited[101];
int dist[101];

int min(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

void dijkstra(int start)
{
   
    dist[start] = 0;
    int mindex=0;
    int mdist=0;
    int flag=0;
    while(visited[start]!=1)
    {
        flag=0;
        mindex=start;
        // cout << "start " << start << endl;

        for (int i = 1; i < 101; i++)
        {
            // cout << "i " << i << endl;

            if (dist[i] > dist[start] + map[i][start])
            {
                dist[i] = dist[start] + map[i][start];
                // cout << "update " << i << endl;

                if(flag==0)
                {
                    mdist=dist[i];
                    mindex=i;
                    flag=1;
                }
                else if(flag == 1 && mdist>dist[i])
                {
                    mdist=dist[i];
                    mindex=i;
                }

            }
        
        }
        visited[start]=1;
        start=mindex;

    }
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

        Answer = 0;
        int N, M, K, P;
        int a, b, res;
        int x, y;
        

        vector<pair<int, int> > xy;
        
        // for (int i = 0; i < 101; i++)
        // {
        //    cout << dist[i] << endl;
        // }


        for (int i = 0; i < 101; i++)
        {
            memset(map[i], 55555, sizeof(int) * 101);
            map[i][i] = 0;
        }

        cin >> N >> M >> K;

        for (int i = 0; i < M; i++)
        {
            cin >> a >> b >> res;
            map[a][b] = res;
            map[b][a] = res;
            // cout << a << b << res << endl;

        }
        cin >> P;
        for (int i = 0; i < P; i++)
        {
            cin >> x >> y;
            xy.push_back(make_pair(x, y));
            memset(visited, 0, sizeof(int) * 101);
            memset(dist, 55555, sizeof(int) * 101);
            dijkstra(x);
            if(dist[y]>K)
            {
                Answer++;
            }
        }

        // for (int i = 1; i < N+1; i++)
        // {
        //    cout << dist[i] << endl;
        // }



        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}