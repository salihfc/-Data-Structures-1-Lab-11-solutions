#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define MAXN ((int)1e6+5)
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<int,int>
#define mid ((l+r)/2)

int pre[MAXN];

int gcd(int a, int b){return (a == 0) ? b : gcd(b%a, a);}

int exalted(int a)
{
	int gc = 0;

	while(a > 0)
	{
		gc = gcd(gc, a%10);
		a/=10;
	}

	return (gc>1);
}

void precalc()
{
	pre[0] = 0;
	for (int i = 1; i < MAXN; ++i)
		pre[i] = exalted(i);


	for (int i = 1; i < MAXN; ++i)
		pre[i] += pre[i-1]; 
}

int range(int l, int r)
{
	return pre[r] - pre[l-1];
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	int n;
	cin >> n;
	precalc();

	for (int i = 0; i < n; ++i)
	{
		int a,b;
		cin >> a >> b;
		cout << range(a,b) << endl;
	}
}