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

class Obsta
{
public:

    int x;
    int y;

	Obsta()
    {  
		x=0;
        y=0;
    }
    Obsta(int x1,int y1)
    {
        x=x1;
        y=y1;
    }

	Obsta& operator=(const Obsta &p) 
	{
		y=p.y;
		x=p.x;

    return *this;  // 자기 자신을 참조를 반환합니다.
	}

    bool operator==(const Obsta &other) const 
	{
		return y==other.y;
    }   

    bool operator!=(const Obsta &other) const 
	{
    return !(*this == other);
    }

	

};


int main(int argc, char** argv)
{
	int T, test_case;
	


	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int N,M,oNum;
		long long save,msave1,msave2;		
		Answer = 0;
		int ox,oy;
        int curY=0;
        int curX=0;
		cin >> N >> M >> oNum;
		vector <Obsta> oList;
		for(int i=0;i<oNum;i++)
		{
			cin >> ox >> oy;
			if(ox>N || oy>M)//don't need to count 
			{
				continue;
			}
			Obsta temp=Obsta(ox,oy);
		    oList.push_back(temp);
		}
		oNum=oList.size(); 
		for(int i=0;i<oNum;i++)
		{
			cout<<oList[i].x<<oList[i].y<<endl;
		}

		
		for(curY=1;curY<M;curY++)
		{ 
			vector <Obsta>::iterator it;
            it=find(oList.begin(),oList.end(),curY);
			for(it=oList.begin(); it!=oList.end(); it++)
			{
				route[0][(*it).x]=-1;
			}
			for(curX=1;curX<N;curX++)
            {
                if(route[0][curX]!=-1&&route[1][curX-1]!=-1)
                {
                    route[1][curX]=route[0][curX]+route[1][curX-1]; 
                }
                route[0][curX]=route[1][curX];   
            }
		}


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}