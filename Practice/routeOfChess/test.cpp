/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 100000
#define MOD 1000000007

long long Answer;
long long facL[2*MAX+3];
long long facR[2*MAX+3];


long long powRem(long long x) 
{
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

void fac(long long x)
{
    long long i;
    facL[0]=1;
	facR[0]=1;
    
    for (i = 1; i <= x; i++)
    {
        facL[i] = (i * facL[i-1])%MOD;
		facR[i] = powRem(facL[i])%MOD;
    }
    
}

long long comb(long long n, long long k) 
{
	if(n<k||k<0)
	{
		return 0;
	}

	return ((facL[n]*facR[k]%MOD)*facR[n-k])%MOD;
}

long long cal(pair<int,int> x, pair<int,int> y)
{
	return comb(y.first-x.first+y.second-x.second,y.second-x.second);
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

	fac(2*MAX+1);

	// for(int i=0; i<2*MAX+1;i++)
	// {
	// 	cout << facR[i] << endl;
	// }

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		// ios_base::sync_with_stdio(false);
	    // cin.tie(NULL);

		int N,M,K;
		// long long save,msave1,msave2;		
		Answer = 0;
		int ox,oy;
		cin >> N >> M >> K;
		// cout << N << M << K << endl;
		vector <pair<int,int> > oList(K+2);
		vector <long long> path(K+2);
		
		for(int i=1;i<=K;i++)
		{
			cin >> ox >> oy;
			oList[i].first=ox;
			oList[i].second=oy;
			// cout << ox << oy << endl;
		}
		oList[K+1].first=N;
		oList[K+1].second=M;
		oList[0].first=1;
		oList[0].second=1;

		sort(oList.begin()+1,oList.begin()+K+1);

		for(int i=K;i>=0;i--)
		{
			path[i]=cal(oList[i],oList[K+1]);
			for(int j=i+1;j<=K;j++)
			{
				if(oList[i].first<=oList[j].first&&oList[i].second<=oList[j].second)
				{
					path[i]=path[i]-(path[j]*cal(oList[i],oList[j]));
					path[i]=(path[i]%MOD+MOD)%MOD;
				}
			}

		}
		Answer=path[0];
		


		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}