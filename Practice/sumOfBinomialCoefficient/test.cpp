/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

#define MOD 1000000007
#define MAX 1000000
long long Answer;
long long N;
long long M; 
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

	freopen("input.txt", "r", stdin);
    fac(2*MAX+2);
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        N = 0;
        M = 0;
        cin >> N >> M;
        long long save=0;
        
          
        save=powRem(facList[N+1]*facList[M+1]%MOD);
        Answer=(facList[M+N+2]*save)%MOD -1;
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}