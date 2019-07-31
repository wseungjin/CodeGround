/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;
#define MAX 100000
#define MOD 1000000007

long long Answer;
long long facList[2*MAX+3];


void fac(long long x)
{
    long long i;

    
    facList[0]=1;
    facList[1]=1;
    if(x>1)
    {
        for (i = 2; i <= x; i++)
        {
            facList[i] = (i * facList[i-1])%MOD;
        }
    }
}

long long powRem(long long x) {
	long long rem = 1; // remainder
	long long pow = MOD - 2;

	while(pow > 0) {
		if(pow % 2)
			rem = ((rem * x) % MOD);
		x = ((x * x) % MOD);
		pow = pow / 2;
	}

	return rem;
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

	fac(2+MAX+1);

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int N,M,oNum;
		long long save,msave1,msave2;		
		Answer = 0;
		int ox,oy;
		cin >> N >> M >> oNum;
		// cout << N << M << oNum << endl;
		vector <pair<int,int> > oList;
		for(int i=0;i<oNum;i++)
		{
			cin >> ox >> oy;
			if(ox>N || oy>M)//don't need to count 
			{
				continue;
			}
			oList.push_back(make_pair(ox,oy));
			// cout << ox << oy << endl;
		}
		oNum=oList.size();

		
		save=powRem(facList[N-1]*facList[M-1])%MOD;
		Answer=(facList[N+M-2]*save)%MOD;
		cout << Answer << endl;
		for(int i=0;i<oNum;i++)
		{
			save=powRem(facList[oList[i].first-1]*facList[oList[i].second-1])%MOD;
			msave1=(facList[oList[i].first+oList[i].second-2]*save)%MOD;
			save=powRem(facList[N-oList[i].first]*facList[M-oList[i].second])%MOD;
			msave2=(facList[N+M-oList[i].first-oList[i].second]*save)%MOD;
			msave1=(msave1*msave2)%MOD;
			
			Answer=Answer-msave1;
			if(Answer<0)
			{
				Answer=Answer+MOD;
			}
			cout << Answer << endl;
		}


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}