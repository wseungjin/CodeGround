/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <string.h>
#include <cstring>

using namespace std;

#define MAXMAP 1000005

int Answer;


int main(int argc, char** argv)
{
	int T, test_case;
	int numberOfDot = 0;
    int maxLength = 0;
    
	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        numberOfDot = 0;
        maxLength = 0;
        int index=0;

        cin >> numberOfDot;
        Answer=0;
        int *map=new int[MAXMAP];
        int end=0;
        int start=0;
        memset(map,-1,sizeof(int)*MAXMAP);
        map[0] = 0;

        for (int i = 1; i < numberOfDot + 1; i++)
        {
            cin >> map[i];
            end=map[i];
        }

        cin >> maxLength;

        // cout << end << endl;


        while(start<end)
        {
            start=start+maxLength;
            // cout << start << endl;
            int count=0;
            if(start>=end)
            {
                Answer++;
                break;
            }

            // cout << index << endl;
            while(map[index]<=start)
            {
                index++;
            }
            index--;
            // cout << index << endl;
            // cout << index << endl;
            while(start>map[index])
            {
                start--;
                
                count++;
            }
            // cout << start << endl;

            if(count>=maxLength)//되돌아왔다. 값을 못찾음
            {
                Answer=-1;
                break;
            }

            Answer++;

        }



		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}