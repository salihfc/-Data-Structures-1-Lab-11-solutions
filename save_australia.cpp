#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define MAXN ((int)2e5+5)
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

int n;

int d[105][105];
int pre[105][105]; // for rows
int mat[105][105];

void precalc()
{
	for (int i = 0; i < n; ++i)
		pre[i][0] = d[i][0];

	for (int i = 0; i < n; ++i)
		for (int j = 1; j < n; ++j)
			pre[i][j] = pre[i][j-1] + d[i][j];

	for (int i = 0; i < n; ++i)
		mat[0][i] = pre[0][i];

	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			mat[i][j] = mat[i-1][j] + pre[i][j];
}

int rectangle(int x1, int y1, int x2, int y2)
{
	return mat[x2][y2] - 
			(x1 ? mat[x1-1][y2] : 0) - 
			(y1 ? mat[x2][y1-1] : 0) + 
			((x1&&y1) ? mat[x1-1][y1-1] : 0);
}

int size(int a, int b, int c, int d)
{
	return (c-a+1) * (d-b+1);
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> d[i][j];

	precalc();

	int a,b,c,d;
	int mx = -1e9;
	for (int x1 = 0; x1 < n; ++x1)
	{
		for (int y1 = 0; y1 < n; ++y1)
		{
			for (int x2 = x1; x2 < n; ++x2)
			{
				for (int y2 = y1; y2 < n; ++y2)
				{
					int t = rectangle(x1,y1,x2,y2); 
					if((t > mx) 
						|| 
						(t==mx && (size(x1,y1,x2,y2) < size(a,b,c,d)))
					)
					{
						mx = t;

						a = x1;
						b = y1;
						c = x2;
						d = y2;
					}
				}
			}
		}
	}

	cout << (a+1) _ (b+1) _ (c+1) _ (d+1) << endl;
}