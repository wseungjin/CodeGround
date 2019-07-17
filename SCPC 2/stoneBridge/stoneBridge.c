/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <stdlib.h>

long long Answer;

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
	for(test_case = 0; test_case < T; test_case++)
	{
        int num=0;
        int k=0;
        int mnum=0;
        Answer=0;

        scanf("%d %d %d", &num,&k,&mnum);

        printf("%d %d %d", num,k,mnum);
        printf("\n");

        long long **bridge=(long long**)calloc(k,sizeof(long long*));
        int* mine=(int *)calloc(mnum,sizeof(int));

        
        for(int i=0;i<k;i++)
        {
            bridge[i]=(long long*)calloc(num,sizeof(long long));
        }
        for(int i=0;i<mnum;i++)
        {
            scanf("%d",&mine[i]);
            for(int j=0;j<k;j++)
            {
                bridge[j][mine[i]-1]=-1;
            }
        }

         for(int j=0;j<k;j++)
        {
            for(int i=0;i<num;i++)        
            {
                printf("%lld  ",bridge[j][i]);
            }
            printf("\n");
        }
        printf("\n");


        for(int i=0;i<num;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(j==i&&bridge[j][i]!=-1)
                {
                    
                        bridge[j][i]=1;
                    
                }
                else
                {
                    for(int x=0;x<k;x++)
                    {
                        if(x!=j)
                        {
                            if(i-(x+1)>=0&&j+x<k)
                            {
                                if(bridge[j][i-(x+1)]!=-1)
                                {
                                     bridge[j][i]=bridge[j][i]+bridge[j+x][i-(x+1)];
                                }
                            }
                        }
                    }
                }
                
            }
        }
        for(int j=0;j<k;j++)
        {
            for(int i=0;i<num;i++)        
            {
                printf("%lld  ",bridge[j][i]);
            }
            printf("\n");
        }


        for(int i=0;i<k;i++)
        {
            Answer=Answer+bridge[i][num-1];
        }
     

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%lld\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}