/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <memory.h>
#include <list>
#include <string.h>


using namespace std;

int Answer;




int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}


int main(int argc, char** argv)
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
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        int num;
        cin >> num;
        int temp;
        vector <int> numList;
                int found[400001];

        memset(found,0,400000*sizeof(int));
        for(int i=0;i<num;i++)
        {
            cin >> temp;
            numList.push_back(temp);
            // cout << numList[i] << endl;
        }

        
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(found[200000+numList[i]-numList[j]]==1)
                {          
                    Answer++;
                    break;
                }
            }
            for(int j=0;j<=i;j++)
            {
                found[200000+numList[i]+numList[j]]=1;
            }
        }

        // cout <<endl;

        

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}