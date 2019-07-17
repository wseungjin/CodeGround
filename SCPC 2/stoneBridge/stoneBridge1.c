/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long Answer;

long long bridge[101][50001];
long long sum[50001];
int mine[50001];

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
        int num = 0;
        int k = 0;
        int mnum = 0;
        int temp=0;
        Answer = 0;

        memset(mine, 0, sizeof(mine)); //초기화
        memset(sum, 0, sizeof(sum));

        scanf("%d %d %d", &num, &k, &mnum);

        // printf("%d %d %d", num, k, mnum);
        // printf("\n");

        for (int i = 1; i <= mnum; i++) //마인
        {
            scanf("%d",&temp);
            mine[temp] = -1;
        }

        for (int i = 0; i <= num; i++) //초기화
        {
            for (int j = 0; j <= k; j++)
            {
                bridge[j][i] = 0;
            }
        }
        

        for (int i = 1; i <= num; i++) //구함
        {
            if (mine[i] < 0)
            {
                for (int j = 1; j <= k; j++)
                {
					bridge[j][i] = 0;
                }
				sum[i] = 0;
				continue;
			}
            for (int j = 1; j <= k; j++)
            {
                if (i<j)    
                {
                    bridge[j][i] = 0;
                }
				else if (j == i) 
                {
                    bridge[j][i] = 1;
                }
				else 
                { 
					bridge[j][i] = sum[i-j] - bridge[j][i-j];
					bridge[j][i] = bridge[j][i] % 1000000009;
				}
                sum[i] = sum[i] + bridge[j][i];
            }
        }

        // for (int j = 1; j <= k; j++) //출력
        // {
        //     for (int i = 1; i <= num; i++)
        //     {
        //         printf("%lld  ", bridge[j][i]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        // for (int i = 1; i <= num; i++) //답 뽑기
        // {
        //         printf("%lld ", sum[i]);       
        // }
        // printf("\n");


        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).

        printf("Case #%d\n", test_case + 1);
        printf("%lld\n", sum[num]%1000000009);
    }

    return 0; //Your program should return 0 on normal termination.
}