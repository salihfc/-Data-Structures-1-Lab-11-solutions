#pragma GCC optimize ("O2")
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
#define LG 22


int n,q;
int d[MAXN+5];
int ST[MAXN+5][LG];

int lg[MAXN+5];

void precalc()
{
	lg[1] = 0;
	lg[2] = 1;

	for (int i = 3; i <= MAXN; ++i)
		lg[i] = lg[i>>1] + 1;
}

void build()
{
	for (int i = 0; i < MAXN; ++i)
		ST[i][0] = d[i];

	for (int i = 1; i < LG; ++i)
		for (int j = 0; j + (1<<i) < MAXN; ++j)
			ST[j][i] = max(ST[j + (1<<(i-1))][i-1], ST[j][i-1]);
}

int range(int l, int r)
{
	int step = lg[r-l+1];
	return max(ST[l][step], ST[r-(1<<step)+1][step]);
}

int main()
{

	ios_base::sync_with_stdio(false);cin.tie(0);
	precalc();

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> d[i];

	build();

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int l,r;
		cin >> l >> r;
		cout << range(l-1,r-1) << endl;
	}
}