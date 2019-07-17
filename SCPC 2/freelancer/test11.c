/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <stdlib.h>

int Answer;

int maxOf(int a, int b, int c)
{   
    int max=0;
    if(a > max) max =a ;
    if(b > max) max =b;
    if(c > max) max =c ;
    return max;


}

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
        int temp = -1;
        int save = 0;
        scanf("%d", &num);
        int *numArrayA = (int *)calloc(num, sizeof(int));
        int *numArrayB = (int *)calloc(num, sizeof(int));

        int *sum = (int *)calloc(num, sizeof(int));


        for (int i = 0; i < num; i++)
        {
            scanf("%d", &numArrayA[i]);
        }
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &numArrayB[i]);
        }

        sum[0]= maxOf(numArrayA[0],numArrayB[0],0);

        sum[1]= maxOf(numArrayB[1],numArrayB[0]+numArrayA[1],numArrayA[0]+numArrayA[1]);

        for (int i = 2; i < num; i++)
        {
            sum[i]=maxOf(sum[i-1]+numArrayA[i],
                        sum[i-2]+numArrayB[i],
                        sum[i-2]+numArrayA[i-1]+numArrayA[i]);


            
        }
    

    Answer = sum[num-1];
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