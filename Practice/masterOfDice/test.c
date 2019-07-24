/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ROUNDING(x, dig)	( floor((x) * pow(float(10), dig) + 0.5f) / pow(float(10), dig) )

double Rounding( double x, int digit )
{
	return ( floor( (x) * pow( 10, digit ) + 0.5f ) / pow(10, digit));
}


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

    // printf("%d\n",T);

    
    for (test_case = 0; test_case < T; test_case++)
    {
        double average = 0;
        char string[12]= {0, };

        scanf("%s", string);
        int saveNum=-1;

       

        if(strcmp(&string[10], "") != 0)
        {
            saveNum=atoi(&string[10]);
        }

        average=atof(string);
        

        long long sum = 0;
        int averageRound = (int)Rounding(average,0);

        // printf("%d\n",averageRound);
        int checkRonud = 0;
        if (average - averageRound < 0)
        {
            checkRonud = 1;
        }

        // printf("%d\n",checkRonud);
        long long divideNum = 1000000000LL;
        long long tempMul=10;
        long long tempDi=(long long)(average*divideNum);

        if(saveNum!=-1)
        {
            while(tempDi%10==0)
            {
                tempDi=tempDi/10;
                divideNum=divideNum/10;
            }
        }
        else
        {
            while((average*tempMul)-(long long)(average*tempMul)!=0)
            {
                tempMul=tempMul*10;
            }
            divideNum=tempMul;
            tempDi=tempMul*average;
        }
        
        


        if(saveNum!=-1 && saveNum!=0)
        {
            // printf("%lld\n",tempDi);

            if(tempDi%10!=saveNum)
            {
                // printf("%lld\n",tempDi);

                tempDi=tempDi+1;
                if(tempDi%10!=saveNum)
                {
                    // printf("%lld\n",tempDi);

                    tempDi=tempDi-2;
                }
            }
        }


       


        long long temp = divideNum;
        long long tempnum = tempDi;

        for(int k=2;k<sqrt((long double)tempnum)*2||k<11;k++)
        {
            if ((tempnum % k == 0) && (temp % k == 0))
            {
                tempnum = tempnum/k;
                temp = temp/k;
                k = 2;
            }
            
        }
        // printf("%lld\n",temp);

        sum = tempnum;
        // printf("%lld\n",sum);

        long long numList[5] = {0, 0, 0, 0, 0};
        long long num1 = (long long)(sum/averageRound); //averageRound
        // printf("%lld\n",num1);   

        int num2 = sum % averageRound;
        // printf("%d\n",num2);

        long long tNum = (int)(num1 / 2);
        // printf("%lld\n",tNum);

        if ((num2 == 0 && averageRound!=1)||temp==1)
        {
            numList[averageRound - 1] = num1;
        }
        else
        {
            if (checkRonud == 0)
            {
                for (long long i = tNum; i < temp; i++)
                {
                    if ((averageRound)*i + (averageRound + 1) * (temp - i) == sum)
                    {
                        numList[averageRound - 1] = i;
                        numList[averageRound] = temp - i;
                        break;
                    }
                }
            }
            else
            {
                for (long long i = tNum; i < temp; i++)
                {
                    if ((averageRound)*i + (averageRound - 1) * (temp - i) == sum)
                    {
                        numList[averageRound - 1] = i;
                        numList[averageRound - 2] = temp - i;
                        break;
                    }
                }
            }
            
        }

        printf("#testcase%d\n", test_case + 1);
        printf("%lld %lld %lld %lld %lld\n",numList[0],numList[1],numList[2],numList[3],numList[4]);
    }

    return 0; //Your program should return 0 on normal termination.
}