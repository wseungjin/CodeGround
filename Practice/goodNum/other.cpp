// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int A[5001];
int MIN[5001];
//int cache[3][600001];
int cache[400001];
int ret;

/*
bool isGoodNumber(int n);
bool isGoodNumber2(int n, int depth, int sum);
bool isGoodNumber3(int n, int depth, int needs, int min);
bool isGoodNumber4(int n, int depth, int needs, int min);
bool isGoodNumber5(int n, int depth, int needs);
*/
bool isGoodNumber6(int n);
bool isGoodNumber7(int n);

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	// setbuf(stdout, NULL);

	int TC;
	int test_case;
    
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
        memset( cache, -1, sizeof(cache) );
        ret = 0;
        int N;
        cin >> N;
        
        // 입력부
        for(int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        
        //A[1]부터 A[n-1]의 배열 중 최소값을 찾아 기록해둔다. (2 <= n <= N)
        // min[1] 은 서브배열이 정의가 안됨.
        MIN[2] = A[1];
        int minVal = A[1];
        // A[1]부터 A[N-1]까지 최소값을 계속 구해나가면서 따로 저장해둔다.
        for(int n = 2; n < N; n++) {
            minVal = min(minVal, A[n]);
            MIN[n+1] = minVal;
        }
        
        //int ret = 0;
        // n = 2 부터 시작
        //for(int n = 2; n <= N; n++) { 
            //if( isGoodNumber(n) ) ret++;
            //if( isGoodNumber2(n, 0, 0) ) ret++;
            //if( isGoodNumber3(n, 0, A[n], min[n]) ) ret++;
            //if( isGoodNumber4(n, 0, A[n], min[n]) ) ret++;
            //if( isGoodNumber5(n, 0, A[n]) )ret++;
            //if( isGoodNumber6(n) )ret++;
        //    if( isGoodNumber7(n) )ret++;
        //}
        
        
        for( int n = 1; n <= N; n++ ) {
        //if( isGoodNumber6(n) )ret++;
            //if( isGoodNumber7(n) )ret++;
            
            if( isGoodNumber7(n) ) ret++;
        }
        
        
        
        
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
        printf("%d\n", ret);	// cout 사용 가능
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}

/*
bool isGoodNumber(int n)
{
    // 시간초과를 예상할 수 있는 방법도 구비해놔야함.
    // 제한시간에 걸리므로 가지치기가 필요함.
    // 1. sort했을 때 최소원소가 A[n]보다 큰 경우는 제외함.
    
    // 현재 false여도 끝까지 무조건 다 계산하는 형태.
    for(int fir = 1; fir < n; fir++) {
        for(int sec = 1; sec < n; sec++) {
            for(int thd = 1; thd < n; thd++) {
                if( A[fir] + A[sec] + A[thd] == A[n]) return true;
            }                    
        }
    }
    
    return false;
}

// isGoodNumber를 재귀함수로 바꾼 함수.
bool isGoodNumber2(int n, int depth, int sum)
{   
	//cout << "(" << A[n] << ", "<< n << ", " << depth << ", " << sum << ")" <<endl;
	// if( depth > 3) return false; -> 남은 분기를 없애버리는 구문
    if( depth == 3 && sum == A[n]) return true;        
    
    for(int cur = 1; cur < n; cur++) { 
    	// pruning
        if(depth < 3 && isGoodNumber2(n, depth+1, sum + A[cur])) return true;   
        // if(depth < 3 ) return isGoodNumber2(n, depth+1, sum + A[cur]); -> 이렇게 써버리면 A[1]+A[1]+A[1]에서 결과가 바로 결정되고
        // A[1]+A[1]+A[2] 로 분기하지 못한다.
    }
    
    // 모든 경우에서 true에 걸리지 않으면 false를 리턴해야함.
    return false;
}

// isGoodNumber2에서 pruning 조건을 추가한 함수.
bool isGoodNumber3(int n, int depth, int needs, int min)
{   
    //if( depth == 3) return (needs == 0) ? true : false;      
    // pruning1 : A1부터 An-1까지의 서브배열 기준으로 구한 최소값 > A[n]을 만들기 위해 필요한 숫자 라면 분기할 필요가 없다.
    if( min <= needs ) {
        for(int cur = 1; cur < n; cur++) {            
            // pruning2 : 남은 숫자보다 현재 더하려는 숫자가 크면 분기 x
            if( A[cur] > needs ) continue;
    	    // pruning3 : depth = 2에서 정답을 판단한다.
            if( depth == 2 && needs - A[cur] == 0 ) return true;             
            // depth는 2보다 작아야 depth = 2인 함수를 마지막으로 호출한다. 굳이 depth = 3까지 가서 판단하지 않도록 한다.
            if( depth < 2 && isGoodNumber3(n, depth+1, needs - A[cur], min) ) return true;                     
        }
    }
    return false;
}


// isGoodNumber3에서 동적계획법으로 변환한 함수.
bool isGoodNumber4(int n, int depth, int needs, int min)
{   
    if( cache[depth][needs+300000] != -1 )
    {
    	//cout << "depth : " << depth << " needs : " << needs << "에서 캐시 활용" << endl;
    	return (cache[depth][needs+300000] == 1) ? true : false;
    }
    
    //if( depth == 3) return (needs == 0) ? true : false;      
    // pruning1 : A1부터 An-1까지의 서브배열 기준으로 구한 최소값 > A[n]을 만들기 위해 필요한 숫자 라면 분기할 필요가 없다.
    if( min <= needs ) {
        for(int cur = 1; cur < n; cur++) { 
        	//cout << "depth : " << depth << " needs : " << needs << " A[cur] : " << A[cur] << endl;
            // pruning2 : 남은 숫자보다 현재 더하려는 숫자가 크면 분기 x -> 음수일 경우가 있으므로 제외
            // if( A[cur] > needs ) continue;
    	    // pruning3 : depth = 2에서 정답을 판단한다.
            if( depth == 2 && needs - A[cur] == 0 ) {
                //cout << " needs : " << needs << " A[cur] : " << A[cur] << "에서 정답" << endl;
                cache[depth][needs+300000] = 1;
                return true; }            
            // depth는 2보다 작아야 depth = 2인 함수를 마지막으로 호출한다. 굳이 depth = 3까지 가서 판단하지 않도록 한다.
            if( depth < 2 && isGoodNumber4(n, depth+1, needs - A[cur], min) ) { cache[depth][needs+300000] = 1; return true; }                     
        }
    }
    
    // n번째 수열마다 안되는것에 대한 캐시는 적용이 안됨. 4를 만들기 위해 1을 두번선택하면 depth = 2, needs = 2 -> false지만
    // 5를 만들기 위해 1과 2를 선택했을때 나오는 depth = 2, needs = 2는 계산을 해봐야 알 수 있다.
    // true인 것만 계산 안하고 바로 넘어갈 수 있는 동적계획법이다.
    //cache[depth][needs+300000] = 0;
    return false;
}

// isGoodNumber4를 수정.
bool isGoodNumber5(int n, int depth, int needs)
{   
    int &ret = cache[depth][needs+300000];
    if( ret != -1 )
    {
    	//cout << "depth : " << depth << " needs : " << needs << "에서 캐시 활용" << endl;
    	return true;
    }
    // pruning1 : A1부터 An-1까지의 서브배열 기준으로 구한 최소값 > A[n]을 만들기 위해 필요한 숫자 라면 분기할 필요가 없다.
    if( MIN[n] <= needs ) {
        for(int cur = 1; cur < n; cur++) { 
        	//cout << "depth : " << depth << " needs : " << needs << " A[cur] : " << A[cur] << endl;
    	    // depth = 2에서 정답을 판단한다.
            if( depth == 2 && needs - A[cur] == 0 ) {
                //cout << " needs : " << needs << " A[cur] : " << A[cur] << "에서 정답" << endl;
                ret = 1;
                return true;
            }            
            // depth는 2보다 작아야 depth = 2인 함수를 마지막으로 호출한다. 굳이 depth = 3까지 가서 판단하지 않도록 한다.
            if( depth < 2 && isGoodNumber5(n, depth+1, needs - A[cur]) ) { ret = 1; return true; }                     
        }
    }
    return false;
}
*/

// A[a] + A[b] + A[c] = A[n] 일 경우 좋은 수이다.
// cache를 n이 바뀔때마다 초기화 -> 70점만 나옴.
bool isGoodNumber6(int n)
{       
    //cout << "n : " << n << endl;
    // A[n] - A[c] (1 <= c <= n-1) 을 계산한다.
    for( int c = 1; c < n; c++ ) {
    	if( cache[ A[n] - A[c] + 200000 ] != -1) continue;        
        cache[ A[n] - A[c] + 200000 ] = 1;
        //cout << "cache[ " << A[n] - A[c] << "(A[" << n << "] - A[ " << c << "]) ] = " << cache[ A[n] - A[c] +200000] << endl;
    }
    // A[a] + A[b] = A[n] - A[c] 이므로 cache[ A[a]+A[b] ] 가 존재하면 정답이다.
    for( int a = 1; a < n; a++ ) {
        for( int b = 1; b < n; b++ ) {
            if( cache[ A[a] + A[b] + 200000 ] == 1) {
            	//cout << "cache[ " <<  A[a] + A[b] << "(A[" << a << "] + A[ " << b << "]) ] = " << cache[ A[a] + A[b] + 200000] << endl;
            	return true;
            }
        }
    }
    
    return false;
}

// A[a] + A[b] + A[c] = A[n] 일 경우 좋은 수이다.
// cache를 제대로적용해줘야 한다! (캐시의 기준을 A[a] + A[b] 로 둠)
// 반복문 갯수도 줄이고 (n번째 수열의 차례마다 0~n까지의 A[a] + A[b]를 만들며 캐시를 생성한다.


bool isGoodNumber7(int n)
{   
    //cout << "n : " << n << endl;
    
    bool isThereAnswer = false;
    // A[n] - A[c] (1 <= c <= n-1) 이 존재하면 정답이다.
    for( int c = 1; c < n; c++ ) {
    	if( cache[ A[n] - A[c] + 200000 ] == 1)
    	{
    		//cout << "cache[ " << A[n] - A[c] << "(A[" << n << "] - A[ " << c << "]) ] = " << cache[ A[n] - A[c] +200000] << endl;
    		
    		isThereAnswer = true;
    		break;
    		//return true; 
    	}
        
    }
    
    // A[a] + A[b] = A[n] - A[c] 이므로 cache[ A[a]+A[b] ] 를 계산해놓는다.
    // n+1번째를 계산하기 전에 계산한다.
    int a = n;
    for( int b = 1; b <= n; b++ ) {
        //if( cache[ A[a] + A[b] + 200000 ] != -1) continue;
        cache[ A[a] + A[b] + 200000 ] = 1;
        //cout << "cache[ " <<  A[a] + A[b] << "(A[" << a << "] + A[ " << b << "]) ] = " << cache[ A[a] + A[b] + 200000] << endl;
    }
    
    // 캐시를 빠짐없이 계산해야 정답을 찾을 수 있으므로 위에서 return true 하지 않는다.
    return ( isThereAnswer )? true : false;
}