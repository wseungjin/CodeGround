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


long long gcd(long long a, long long b) {
	return (b == 0) ? a : gcd(b, a % b);
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
        char string[15];
        long long a,b;
        int bLeng=0;
        
        

        scanf("%lld.%s", &a,string);
        b=atoll(string);
        

        bLeng=strlen(string);

        // printf("%lld\n",a);
        // printf("%lld\n",b);

        long long m =a , n =1;


        for(int i=1;i<bLeng;i++,m=m*10,n=n*10)
        {

        }
        m=m*10+b;
        n=n*10;
        // printf("%lld\n",m);
        // printf("%lld\n",n);

        long long g=gcd(n,m);

        m=m/g;
        n=n/g;

        // printf("%lld\n",g);
        // printf("%lld\n",n);
        // printf("%lld\n",m);
        
        
        long long numList[6] = {0,0, 0, 0, 0, 0};


        long long ans= a *n + n -m;
        numList[a]=ans;
        numList[a+1]=n-ans;
  
       

        printf("#testcase%d\n", test_case + 1);
        printf("%lld %lld %lld %lld %lld\n",numList[1],numList[2],numList[3],numList[4],numList[5]);
    }

    return 0; //Your program should return 0 on normal termination.
}