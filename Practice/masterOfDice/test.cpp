#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char bstr[100];
int cnt[6];

long long gcd(long long a, long long b) {
	return (b == 0) ? a : gcd(b, a % b);
}

void proc(int caseidx) {
	long long a = 0, b = 0;
	scanf("%lld.%s", &a, bstr);
	int blen = strlen(bstr);
	b = stoll(bstr);

	for (int i = 1; i <= 5; ++i) cnt[i] = 0;

	long long n = a, m = 1;
	for (int i = 0; i < blen; ++i, n *= 10, m *= 10);
	n += b;
    printf("%lld\n",n);
	long long g = gcd(n, m);
	n /= g;  m /= g;
    printf("%lld\n",g);
    printf("%lld\n",n);
    printf("%lld\n",m);


	long long acnt = a * m + m - n;
	cnt[a] = acnt;
	cnt[a + 1] = m - acnt;

	printf("#testcase%d\n", caseidx);
	for (int i = 1; i <= 5; ++i) printf("%d ", cnt[i]);
	putchar('\n');
}

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		proc(i);
	}
	return 0;
}