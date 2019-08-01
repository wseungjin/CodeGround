/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;



int Answer;

int map[201][201];
int visited[201];

void dfs(int cur,int num) 
{
    visited[cur] = 1;
    printf("%d ", cur);
    for (int i = 1; i <= num; i++) 
    {
        if (visited[i]!=0 map[cur][i]) 
        {
            Answer=0;
            break;
        }
        else if(map[cur][i] == 0 )
        {
            continue;
        }
         // already visited or not connected.
        dfs(i,num);
    }
}

int main(int argc, char** argv)
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

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int N,M;
        cin >> N >> M;
        Answer=1;

        vector <pair<int,int> > comL(M);

        for(int i=0; i<=N; i++)
        {
        memset(map[i],0, sizeof(int)*(N+1));
        }
        memset(visited,0,sizeof(int)*(N+1));
        for(int i=0;i<M;i++)
        {   
            cin >> comL[i].first >> comL[i].second; 
            map[comL[i].first][comL[i].second]=1;
            map[comL[i].second][comL[i].first]=1;
        }

        


        dfs(1,N);



		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}