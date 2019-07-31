/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <string>

using namespace std;

long long Answer;

long long getNumber(int x, int y,int length)
{
    int sum = x + y + 1;
    int flag=0;
    long long num;

    if(sum>length)
    {
        flag=1;
        x=length-1-x;
        y=length-1-y;
        sum = x + y + 1;
    
    }
    num = (sum) * (sum + 1) / 2;


    if (sum % 2 == 0)
    {
        num = num - x;
    }
    else
    {
        num = num - (sum - x) + 1;
    }

    if(flag==1)
    {
        num = (length*length+1)-num;
    }
    
    // cout << num << endl;
    return num;
}

void direction(int *x, int *y, char di)
{
    char DRUL[4] = {'D', 'R', 'U', 'L'};

    if (di == DRUL[0])
    {
        *y = *y + 1;
        // cout << "D" << endl;
    }
    else if (di == DRUL[1])
    {
        *x = *x + 1;
        // cout << "R" << endl;
    }
    else if (di == DRUL[2])
    {
        *y = *y - 1;
        // cout << "U" << endl;
    }
    else if (di == DRUL[3])
    {
        *x = *x - 1;
        // cout << "L" << endl;
    }

    return;
}

int main(int argc, char **argv)
{
    int T, test_case;
    /*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

    freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {

        Answer = 0;
        int length = 0;
        int num = 0;
        int x = 0;
        int y = 0;

        string line;

        cin >> length;
        cin >> num;
        cin >> line;

        // cout << length << endl;
        // cout << num << endl;
        // cout << line << endl;

        Answer = Answer + getNumber(x, y,length);

        for (int i = 0; i < num; i++)
        {
            // cout << x << y << endl;
            direction(&x, &y, line.at(i));
            Answer = Answer + getNumber(x, y,length);
        }

        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}