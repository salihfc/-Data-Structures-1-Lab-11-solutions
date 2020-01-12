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

map <char,char> rev;

bool balanced(string s)
{
	stack <char> st;

	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '{' or s[i] == '[' or s[i] == '(')
			st.push(s[i]);
		else
		{
			if(st.size() && st.top() == rev[s[i]])
				st.pop();
			else
				return 0;
		}
	}
	return st.empty();
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	rev['}'] = '{';
	rev[']'] = '[';
	rev[')'] = '(';

	int q;
	cin >> q;
	while(q--)
	{
		string s;
		cin >> s;
		cout << ((balanced(s)) ? "YES":"NO") << endl;
	}
}