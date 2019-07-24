/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Answer;

int main(void)
{
    int T, test_case;
    /*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
    // freopen("input.txt", "r", stdin);

    /*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {

        int num = 0;
        long long temp = 0;
        Answer = 0;
        long long min = -1;
        long long a;
        int breakflag = 0;

        scanf("%d", &num);
        long long *numArray = (long long *)calloc(num, sizeof(long long));
        scanf("%lld", &numArray[0]);
        for (int i = 1; i < num; i++)
        {
            scanf("%lld", &numArray[i]);
            numArray[i - 1] = numArray[i] - numArray[i - 1];
            if (min == -1 || numArray[i - 1] < min)
            {
                min = numArray[i - 1];
            }
        }
        // printf("%lld\n",min);
        if (min != 0)
        {
            Answer = 1;
        }
        for (int i = 2; i <= min; i++)
        {
            breakflag = 0;
            for (int j = 0; j < num - 1; j++)
            {
                if (numArray[j] % i != 0)
                {
                    breakflag = 1;
                    // printf("1break\n");
                    break;
                }
            }
            if (breakflag == 0)
            {
                // printf("ans++");
                Answer++;
            }
        }
        breakflag = 0;
        if (Answer == 0)
        {
            for (int i = 0; i < num - 2; i++)
            {
                if (numArray[i] == numArray[i + 1])
                {
                }
                else
                {
                    breakflag = 1;
                    // printf("2break\n");

                    break;
                }
            }
            if (breakflag == 0)
            {
                Answer = 1;
            }
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }

    return 0; //Your program should return 0 on normal termination.
}