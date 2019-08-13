/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int>Point2D; 

int Answer;

int compare(const void *fir, const void *sec)
{
    int x1=((Point2D*)(fir))->second-((Point2D*)(fir))->first;
    int x2=((Point2D*)(sec))->second-((Point2D*)(sec))->first;

    if (x1>x2)
        return 1;
    else if (x1 < x2)
        return -1;
    else 
        return 0;
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
        int tNum;
        int  max;
        int temp;
        int tempx;
        int tempy;
        cin >> tNum;
        vector <Point2D> nList(tNum);

        for(int i=0;i<tNum;i++)
        {
            cin >> nList[i].first >> nList[i].second;
        }
        qsort(&nList[0],nList.size(),sizeof(nList[0]),compare);

        for(int i=0;i<tNum;i++)
        {
            cout << nList[i].first << " " << nList[i].second << endl;
        }

        max=1;
		for(int i=0;i<tNum;i++)
        {
            temp=1;
            tempx=nList[i].first;
            tempy=nList[i].second;
            for(int j=i+1;j<tNum;j++)
            {
                if(tempx>=nList[j].first&&tempy<=nList[j].second)
                {
                    temp++;
                    tempx=nList[j].first;
                    tempy=nList[j].second;
                    // cout << i << " " << j << " " << temp << endl;

                }
            }
            if(temp>max)
            {
                max=temp;
            }
        }
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << max << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}