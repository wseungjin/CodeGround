/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;
#define MAX 100000
#define MOD 1000000007

long long Answer;
long long route[2][MAX+1];

class Obsta
{
public:

    int x;
    int y;

	Obsta()
    {  
		x=0;
        y=0;
    }
    Obsta(int x1,int y1)
    {
        x=x1;
        y=y1;
    }

	Obsta& operator=(const Obsta &p) 
	{
		y=p.y;
		x=p.x;

    return *this;  // 자기 자신을 참조를 반환합니다.
	}

    bool operator==(const Obsta &other) const 
	{
		return y==other.y;
    }   

    bool operator!=(const Obsta &other) const 
	{
    return !(*this == other);
    }

	

};


int main(int argc, char** argv)
{
	
    int save=1;
    for(int i=0; i<100000;i++)
    {
        for(int j=0;j<100000;j++)
        {   
            save=save+1;
        }
    }
    

	return 0;//Your program should return 0 on normal termination.
}