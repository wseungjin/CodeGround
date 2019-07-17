/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#define PI 3.1415926535

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Answer;
int a;
int b;
int c;
int d;
int e;
int num = 0;
int temp = 0;

double getDegree(int x, int y)
{

    return atan2(y, x) * 180 / PI;
}
int getDetailScore(double degree)
{
    if ((degree >= 0 && degree < 9) || degree >= 351)
    {
        return 6;
    }
    else if (degree >= 9 && degree < 27)
    {
        return 13;
    }
    else if (degree >= 27 && degree < 45)
    {
        return 4;
    }
    else if (degree >= 45 && degree < 63)
    {
        return 18;
    }
    else if (degree >= 63 && degree < 81)
    {
        return 1;
    }
    else if (degree >= 81 && degree < 99)
    {
        return 20;
    }
    else if (degree >= 99 && degree < 117)
    {
        return 5;
    }
    else if (degree >= 117 && degree < 135)
    {
        return 12;
    }
    else if (degree >= 135 && degree < 153)
    {
        return 9;
    }
    else if (degree >= 153 && degree < 171)
    {
        return 14;
    }
    else if (degree >= 171 && degree < 189)
    {
        return 11;
    }
    else if (degree >= 189 && degree < 207)
    {
        return 8;
    }
    else if (degree >= 207 && degree < 225)
    {
        return 16;
    }
    else if (degree >= 225 && degree < 243)
    {
        return 7;
    }
    else if (degree >= 243 && degree < 261)
    {
        return 19;
    }
    else if (degree >= 261 && degree < 279)
    {
        return 3;
    }
    else if (degree >= 279 && degree < 297)
    {
        return 17;
    }
    else if (degree >= 297 && degree < 315)
    {
        return 2;
    }
    else if (degree >= 315 && degree < 333)
    {
        return 15;
    }
    else
    {
        return 10;
    }
}

int getScore(int x, int y)
{
    double degree = getDegree(x, y);
    if (degree < 0)
    {
        degree = degree + 360;
    }
    if (pow(x, 2) + pow(y, 2) <= pow(a, 2))
    {
        return 50;
    }
    else if ((pow(x, 2) + pow(y, 2) >= pow(b, 2)) && (pow(x, 2) + pow(y, 2) <= pow(c, 2)))
    {
        return getDetailScore(degree) * 3;
    }
    else if ((pow(x, 2) + pow(y, 2) >= pow(d, 2)) && (pow(x, 2) + pow(y, 2) <= pow(e, 2)))
    {
        return getDetailScore(degree) * 2;
    }
    else if (pow(x, 2) + pow(y, 2) > pow(e, 2))
    {
        return 0;
    }
    else
    {
        return getDetailScore(degree);
    }
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
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        num = 0;
        temp = 0;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        scanf("%d", &num);
        int *numArrayX = (int *)calloc(num, sizeof(int));
        int *numArrayY = (int *)calloc(num, sizeof(int));

        for (int i = 0; i < num; i++)
        {
            scanf("%d %d", &numArrayX[i], &numArrayY[i]);
        }
        for (int i = 0; i < num; i++)
        {
            temp = temp + getScore(numArrayX[i], numArrayY[i]);
        }
        Answer = temp;

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