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
		Answer=0;
        int orginNum=0;
		int cheetNum=0;
        int saveOrg=0;
        int save=0;
        int tempNum=0;
    	scanf("%d", &orginNum);
        if(orginNum>1000000000)
		{
			cheetNum=sqrt(orginNum);
		}
		else
		{
			cheetNum=orginNum;
		}
		
	
        for(int j=2;j<=cheetNum;j++)
        {
            tempNum=orginNum;
            saveOrg=tempNum%j;
            save=tempNum%j;
			if(saveOrg!=0)
			{
            	while (tempNum>0&&saveOrg==save)
            	{       
					
        	        save=tempNum%j;
            	    tempNum=tempNum/j;
                
            	} 
            	if(saveOrg==save)
            	{   
               	 	Answer=j;
                	break;
            	}
			}
                
                
        }
		if(Answer==0)
		{
			Answer=orginNum-1;
		}
        

	

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