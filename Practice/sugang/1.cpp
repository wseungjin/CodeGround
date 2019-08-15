/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;
int D[5001][10001];
int nList[5001];

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
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
        int N,M;
		Answer = 0;
        cin >> N >> M;
        int temp;
        
        for(int i=1;i<=N;i++)
        {
            cin >> temp;
            nList[i]=temp;
        }
        // for(int i=1;i<=N;i++)
        // {
        //     cout << nList[i] << endl;
        // }

        D[0][0]=0;

           for(int i=1;i<=N;i++)
            {
                for(int j=0;j<=M;j++)
                {
                    if(j<nList[i])
                    {
                        D[i][j]=D[i-1][j];
                    }
                    else if (D[i-1][j]<D[i-1][j-nList[i]]+nList[i])
                    {
                        D[i][j]=D[i-1][j-nList[i]]+nList[i];
                    }
                    else
                    {
                        D[i][j]=D[i-1][j];
                    }
                    
                }
            }

            for(int i=1;i<=N;i++)
            {
                for(int j=0;j<=M;j++)
                {
                       cout << D[i][j] << "  ";
                }
                cout << endl;
            }

        

		cout << "Case #" << test_case+1 << endl;
		cout << D[N][M] << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}