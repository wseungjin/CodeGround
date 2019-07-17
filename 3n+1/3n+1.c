/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
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
		unsigned long long n=1;
		unsigned long long i=0;
		unsigned long long max=0;
		
		int k=0;
		int cnt=0;
		scanf("%d", &k);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
        // Print the answer to standard output(screen).
		while(1)
		{
			i=n;
			cnt=0;
			while(1)
			{
				if(i==1)
				{
					break;
				}
				if(i%2==1)
				{
					i=i*3+1;
				}
				else
				{	
					i=i/2;	
				}
				cnt++;
			}			
			if(cnt==k)
			{
				break;
			}

			n++;
		}

		
		max=pow(2,k);
        
		printf("Case #%d\n", test_case+1);
        printf("%llu %llu\n",n,max );
        
	}

	return 0;//Your program should return 0 on normal termination.
}