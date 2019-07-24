/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <stdlib.h>

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
    //setbuf(stdout, NULL);

    scanf("%d", &T);
    int numberOfDot = 0;
    int *map;
    int *distanceFromDot;
    int maxLength = 0;
    int sum = 0;
    int sumNumber = 0;
    for (test_case = 0; test_case < T; test_case++)
    {
        numberOfDot = 0;
        maxLength = 0;
        sum = 0;
        sumNumber = 0;
        Answer = 0;

        scanf("%d", &numberOfDot);

        map = (int *)calloc(numberOfDot + 1, sizeof(int));
        distanceFromDot = (int *)calloc(numberOfDot, sizeof(int));

        map[0] = 0;
        for (int i = 1; i < numberOfDot + 1; i++)
        {
            scanf("%d", &map[i]);
        }
        scanf("%d", &maxLength);

        for (int i = 0; i < numberOfDot; i++)
        {
            distanceFromDot[i] = map[i + 1] - map[i];
        }

        for (int j = 0; j < maxLength; j++)
        {

            for (int i = 0; i < numberOfDot; i++)
            {
                if (maxLength < distanceFromDot[i]) // if distance is bigger than length . it is impossible to walk through
                {
                    Answer = -1;
                    break;
                }

                sum = 0;       //value of sum
                sumNumber = 0; //how many did I sum
                for (int k = 0; k < numberOfDot - i; k++)
                {
                    if (distanceFromDot[i + k] == -1)
                    {
                        break;
                    }
                    else
                    {
                        sum = sum + distanceFromDot[i + k];
                        sumNumber++;
                        if ((maxLength - j) == sum&&(sum=!0)) // greedy algo
                        {
                            Answer++;
                            for (int l = 0; l < sumNumber; l++)
                            {
                                distanceFromDot[i + l] = -1;
                            }
                        }
                        else if (maxLength - j < sum) //escape
                        {
                            break;
                        }
                    }
                }
            }
        }
        printf("Case #%d\n", test_case + 1);
        printf("%d\n", Answer);
    }
    // Print the answer to standard output(screen).

    

    return 0; //Your program should return 0 on normal termination.
}