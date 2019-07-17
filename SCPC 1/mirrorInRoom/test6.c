/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

#include <stdio.h>
#include <stdlib.h>

int Answer;
int Length;
int **route;
char **map;
int direct;
int x;
int y;
int endFlag;

void moving(int version)
{
    if (version == 1)
    {
        if (direct == RIGHT) //R->U
        {
            route[y][x] = UP;
            direct=UP;
            if (y == 0)
            {
                endFlag = 1;
            }
            else
            {
                y = y - 1;
            }
        }
        else if (direct == DOWN) //D->L
        {
            route[y][x] = LEFT;
            direct=LEFT;
            if (x == 0)
            {
                endFlag = 1;
            }
            else
            {

                x = x - 1;
            }
        }
        else if (direct == LEFT) //L->D
        {
            route[y][x] = DOWN;
            direct=DOWN;
            if (y == Length - 1)
            {
                endFlag = 1;
            }
            else
            {

                y = y + 1;
            }
        }
        else if (direct == UP) //U->R
        {
            route[y][x] = RIGHT;
            direct=RIGHT;
            if (x == Length - 1)
            {
                endFlag = 1;
            }
            else
            {

                x = x + 1;
            }
        }
    }
    else if (version == 2)
    {
        if (direct == RIGHT)
        {
            route[y][x] = DOWN;
            direct=DOWN;
            if (y == Length - 1)
            {
                endFlag = 1;
            }
            else
            {

                y = y + 1;
            }
        }
        else if (direct == DOWN)
        {
            route[y][x] = RIGHT;
            direct=RIGHT;
            if (x == Length - 1)
            {
                endFlag = 1;
            }
            else
            {
                x = x + 1;
            }
        }
        else if (direct == LEFT)
        {
            route[y][x] = UP;
            direct=UP;
            if (y == 0)
            {
                endFlag = 1;
            }
            else
            {
                y = y - 1;
            }
        }
        else if (direct == UP)
        {
            route[y][x] = LEFT;
            direct=LEFT;
            if (x == 0)
            {
                endFlag = 1;
            }
            else
            {
                x = x - 1;
            }
        }
    }
    else
    {

        if (direct == RIGHT)
        {
            route[y][x] = RIGHT;
            if (x == Length - 1)
            {
                endFlag = 1;
            }
            else
            {
                x = x + 1;
            }
        }
        else if (direct == DOWN)
        {
            route[y][x] = DOWN;
            if (y == Length - 1)
            {
                endFlag = 1;
            }
            else
            {
                y = y + 1;
            }
        }
        else if (direct == LEFT)
        {
            route[y][x] = LEFT;
            if (x == 0)
            {
                endFlag = 1;
            }
            else
            {
                x = x - 1;
            }
        }
        else if (direct == UP)
        {
            route[y][x] = UP;
            if (y == 0)
            {
                endFlag = 1;
            }
            else
            {
                y = y - 1;
            }
        }
    }
}

void findExit()
{
    direct = RIGHT;
    x = 0;
    y = 0;
    while (endFlag == 0)
    {
        if (map[y][x] == '0')
        {
            moving(0);
        }
        else if (map[y][x] == '1')
        {
            moving(1);
        }
        else if (map[y][x] == '2')
        {
            moving(2);
        }
    }
}

int countNumber()
{
    int mirNum = 0;
    for (int i = 0; i < Length; i++)
    {
        for (int j = 0; j < Length; j++)
        {
            if (map[i][j] != '0' && route[i][j] != 0)
            {
                mirNum++;
            }
        }
    }
    return mirNum;
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
        Length = 0;
        Answer = 0;
        x = 0;
        y = 0;
        direct =RIGHT;
        endFlag = 0;
        scanf("%d", &Length);
        route = (int **)calloc(Length, sizeof(int*));
        for(int i=0;i<Length;i++)
        {
            *(route+i) = (int *)calloc(Length, sizeof(int));
        }       
        map = (char **)calloc(Length, sizeof(char*));
        for(int i=0;i<Length;i++)
        {
            *(map+i) = (char *)calloc(Length, sizeof(char));
        }       
        for (int i = 0; i < Length; i++)
        {
            scanf("%s",map[i]);
        }

        findExit();
        Answer = countNumber();

        for (int i=0; i<Length; i++) 
        {
            free(route[i]); 
            free(map[i]);
        }
        free(route);
        free(map);


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
