/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;
#define MAX 100000
#define MOD 1000000007

long long Answer;
long long route[2][MAX+1];


int main(int argc, char** argv)
{
	int T, test_case;
	


	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int N,M,oNum;
        Answer = 0;
		int ox,oy;
        int curY=0;
        int curX=0;
		cin >> N >> M >> oNum;
		vector <int> xList;
        vector <int> yList;
 		for(int i=0;i<oNum;i++)
		{
			cin >> ox >> oy;
			if(ox>N || oy>M)//don't need to count 
			{
				continue;
			}
		    xList.push_back(ox);
            yList.push_back(oy);
		}
		oNum=yList.size(); 

		
		route[1][1]=1;
		route[1][0]=0;
		for(curX=0;curX<N+1;curX++)
        {
            route[0][curX]=0;   
        }
		
		for(curY=1;curY<M+1;curY++)
		{ 
			vector <int>::iterator it;
            it=find(yList.begin(),yList.end(),curY);
			for(it=yList.begin(); it!=yList.end(); it++)
			{
				if(curY==*(it))
				{	
				route[1][xList[it-yList.begin()]]=-1;
				// cout <<xList[it-yList.begin()] << curY << endl;
				}
			}
			for(curX=1;curX<N+1;curX++)
            {
				if(curY==1&&curX==1)
				{
					// cout << route[1][curX] << " ";
					route[0][curX]=route[1][curX];   
					// continue;
				}
				else if(route[1][curX]==-1)
				{
					route[1][curX]=0;
				}
                else if(route[0][curX]!=-1&&route[1][curX-1]!=-1)
                {
                    route[1][curX]=(route[0][curX]+route[1][curX-1])%MOD; 
                }
				else if(route[0][curX]==-1&&route[1][curX-1]==-1)
				{
					route[1][curX]=0;
				}
				else if(route[0][curX]==-1)
				{
					route[1][curX]=route[1][curX-1];
				}
				else if(route[1][curX-1]==-1)
				{
					route[1][curX]=route[0][curX];
				}
				// cout << route[1][curX]<< " ";
                route[0][curX]=route[1][curX];   
            }
			// cout << endl;
			
		}

		


		cout << "Case #" << test_case+1 << endl;
		cout << route[1][N] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}