/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	for(test_case = 0; test_case < T; test_case++)
	{
		int N=0;
        scanf("%d", &N);
        int* now =(int*)calloc(N+2,sizeof(int));
        for(int i=1;i<=N;i++)
        {
            scanf("%d", &now[i]);
        }    
        int flag = 0;
        Answer = 1;
        do{
            flag = 0;
            int* next = (int*)calloc(N, sizeof(int));
            for(int i = 1; i<=N; i++){
                if(now[i] != 0){
                    if(now[i] <= now[i-1]){
                        if(now[i] <= now[i+1]){
                            next[i] = now[i]-1;
                        } else{
                            next[i] = now[i+1];
                        }
                    }else{
                        if(now[i] <= now[i+1]){
                            next[i] = now[i-1];
                        } else{
                            next[i] = now[i-1]<now[i+1]?now[i-1]:now[i+1];
                        }
                    }
                }
                if(next[i] == 1 && flag == 0){
                    flag = 1;
                } else if(next[i] >= 2 && flag != 2){
                    flag = 2;
                }
            }
           now = next;
           free(next);
           if(flag != 0){
               Answer++;
           }
        }while(flag == 2);    


		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}