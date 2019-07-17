/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <stdlib.h>

int Answer;
char input[10000];

int main(void)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	https://cdn.codeground.org/resources/67f9d6abf7/AVyPwPVNGtswjMxx.png   and use freopen function to read from the file when using scanf function.
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
        scanf("%s",input);
		int h=0;
        int e=0;
        int l=0;
        int o=0;

        for(int i=0; i<10000;i++)
        {
            if(input[i]=='h')
            {
                h++;
            }
            if(input[i]=='e')
            {
                e++;
            }
            if(input[i]=='l')
            {
                l++;
            }
            if(input[i]=='o')
            {
                o++;
            }
        }
        int temp=2*h;
        for(int k=0;k<10000;k++)
        {
            if(temp>h*2)
            {
                temp=2*h;
            }
            if(temp>e*2)
            {
                temp=2*e;
            }
            if(temp>l)
            {
                temp=l;
            }
            if(temp>o*2)
            {
                temp=2*o;
            }
        }
        Answer=temp/2;

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