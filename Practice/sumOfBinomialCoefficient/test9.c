/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>

long long Answer;

long long fac(long long x)
{
    long long result;
    long long i;

    if (x == 1)
    {
        return x;
    }
    else
    {
        result=x;
        for (i = x-1; i > 0; i--)
        {
            result = i * result;
            result = result % (long long)1000000007;
            
        }
        return result;
    }
}

int main(void)
{
    int T, test_case;
    int N, M;

    /*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
    freopen("input.txt", "r", stdin);

    /*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
    // setbuf(stdout, NULL);

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        N = 0;
        M = 0;
        scanf("%d %d", &N, &M);
        long long save = 1;

        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                save = (fac(i) * fac(j));
        
                save = (save % (long long)1000000007);
                

                Answer = Answer + (fac(i + j)/save);
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).

        Answer = Answer % (long long)1000000007;

        printf("Case #%d\n", test_case + 1);
        printf("%lld\n", Answer);
    }

    return 0; //Your program should return 0 on normal termination.
}