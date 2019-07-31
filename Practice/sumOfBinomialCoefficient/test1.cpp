/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

#define MOD 1000000007

long long Answer;
long long N;
long long M; 

long long fac(long long x)
{
    long long result;
    long long i;

    if (x == 1 || x==0)
    {
        return 1;
    }
    else
    {
        result=x;
        for (i = x-1; i > 0; i--)
        {
            result = i * result;
            result = result % (long long)MOD;
            
        }
        return result;
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

	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        N = 0;
        M = 0;
        cin >> N >> M;
        long long save = 1;

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                save = (fac(i) * fac(j));
        
                save = (save % (long long)MOD);
                

                Answer = Answer + (fac(i+j)/save);
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        int a[3];
        if (test_case>10)
        {
            a[50]=1;
        }

        Answer = Answer % (long long)MOD;
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}