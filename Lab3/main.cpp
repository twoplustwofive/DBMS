    #include<bits/stdc++.h>
     
     
    using namespace std;
    #define IOS { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
     
    typedef unsigned long long ull;
    typedef long long int ll;
    typedef long double ld;
     
    #define REP(i,a,b) for(ll i=a;i<=b;++i)
    #define REV(i,a,b) for(ll i=a;i>=b;i--)
    #define pll pair<ll,ll>
    #define vll vector<ll>
    #define sll set<ll>
    #define vpll vector<pll>
    #define F first
    #define S second
    #define PB push_back
    #define MP make_pair
    #define min_pq priority_queue <ll, vector<ll>, greater<ll> >
    #define max_pq priority_queue <ll>
    #define deci(n) fixed << setprecision(n)
    #define INF 1e18
     
    ll mod=1000000007;
    ////__RANGE__UPDATE___///
    vector<ll> initializeDiffArray(vector<ll>& A);
    void update(vector<ll>& D, ll l, ll r, ll x);
    void getArray(vector<ll>& A, vector<ll>& D);
    ////__RANGE__UPDATE___///
    ll min(ll a,ll b);
    ll max(ll a,ll b);
    ll gcd(ll a, ll b);
    void swap(ll *a,ll *b);
    ll lcm(ll a, ll b);
    ll modpower(ll x, ll y, ll p);
     
    //Only for integer y's
    ll power(ll x, ll y);
    ll modulo( ll value, ll m);
    ll myXOR(ll x, ll y) ;
    ll diff(ll a,ll b);
     
	string students[158][2];
	string courses[63][4];
	string grades[9955][3];
	map<string,vector<pair<string,string> > > m1;

	int check(string s,string t)
	{
	ll flag=1;
	for(ll i=8;i>=8;i--)
	if(s[i]!=t[i])
	flag=0;
	return flag;
	}
void merge(string arr[],int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 


	string L[n1], R[n2]; 


	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 


	i = 0;  
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 


	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 


void mergeSort(string arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		 
		int m = l+(r-l)/2; 

	 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 



int partition (string arr[], int low, int high) 
{ 
	string pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{ 

		if (arr[j] < pivot) 
		{ 
			i++; 
			string s = arr[i];
			arr[i]=arr[j];
			arr[j]=s;	

		} 
	} 
	string s = arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=s;

	return (i + 1); 
} 


void quickSort(string arr[], int low, int high) 
{ 
	if (low < high) 
	{ 

		int pi = partition(arr, low, high); 


		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 














    int main()
    {
      /*  #ifdef DEBUG
        freopen("std.in", "r", stdin);
        freopen("std.out", "w", stdout);
        #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif */
    ll rep=1;
    //cin>>rep;
    while(rep--)
    {
	fstream io;
	
	io.open("students01.csv",std::fstream::in | std::fstream::out | std::fstream::app);

	ll i=0;
	while(!io.eof())
	{
	string roll="",name="",line;
	getline(io,line);
	if(line.size())
	{
	ll j=0;
	while(line[j]!=',')
	{
	name.PB(line[j]);j++;
        }
	j+=1;
	while(line.size()>=j)
	{
	roll.PB(line[j]);j++;
        }
	students[i][0]=name;students[i][1]=roll;i++;
 	}
	
	}
	
	
	i=0;
	io.close();
	io.open("grades01.csv",std::fstream::in | std::fstream::out | std::fstream::app);
	
	while(!io.eof())
	{
	string roll="",cnum="",grade="",line;
	getline(io,line);
	if(line.size())
	{
	ll j=0;
	while(line[j]!=',')
	{
	roll.PB(line[j]);j++;
        }
	j++;
	while(line[j]!=',')
	{
	cnum.PB(line[j]);j++;
        }
	j++;
	while(line.size()>=j)
	{
	grade.PB(line[j]);j++;
        }
	
 	}
	grades[i][0]=roll;grades[i][1]=cnum;grades[i][2]=grade;i++;
	}

		i=0;
	io.close();
	io.open("courses01.csv",std::fstream::in | std::fstream::out | std::fstream::app);
	
	while(!io.eof())
	{
	string sem="",cid="",cname="",credits="",line;
	getline(io,line);
	if(line.size())
	{
	ll j=0;
	while(line[j]!=',')
	{
	sem.PB(line[j]);j++;
        }
	j++;
	while(line[j]!=',')
	{
	cid.PB(line[j]);j++;
        }
	j++;
	while(line[j]!=',')
	{
	cname.PB(line[j]);j++;
        }
	j++;
	while(line[j]!=',')
	j++;
	j++;
	while(line[j]!=',')
	j++;
	j++;
	while(line[j]!=',')
	j++;
	j++;
	credits.PB(line[j]);
 	}
	courses[i][0]=sem;courses[i][1]=cid;courses[i][2]=cname;courses[i][3]=credits;i++;
	}
	


	REP(i,0,157)
	{

	REP(j,0,9953)
	{
	
	
	REP(k,0,62)
	{
	if((courses[k][1]==grades[j][1])&&(check(students[i][1],grades[j][0])))
	{
	map<string,vector<pair<string,string> > > :: iterator x=m1.find(students[i][0]);
	if(x!=m1.end())
	x->S.PB(MP(courses[k][2],grades[j][2]));
	else
	{
	vector<pair<string,string> > vec;
	vec.PB(MP(courses[k][2],grades[j][2]));
	m1.insert(MP(students[i][0],vec));
	}


	}

	}


	}


	}



	map<string,vector<pair<string,string> > > :: iterator x;
	fstream file;
	file.open("grades-sorted-M.csv",std::fstream::in | std::fstream::out | std::fstream::app);
	for(x=m1.begin();x!=m1.end();x++)
	{

	map<string,vector<string> > m;
	vector<pair<string,string> > v = x->S;
	vector<pair<string,string> > :: iterator it;
	for(it = v.begin();it!=v.end();it++)
	{

	map<string,vector<string> > :: iterator it1=m.find(it->F);
	if(it1!=m.end())
	{
	it1->S.PB(it->S);
	}
	else
	{
	vector<string> v;
	v.PB(it->S);
	m.insert(MP(it->F,v));
	}

	}
	map<string,vector<string> > :: reverse_iterator y;
	
	for(y=m.rbegin();y!=m.rend();y++)
	{

	vector<string> v = y->S;
	ll n= v.size();
	string a[n];

	REP(k,0,n-1)
	{
	a[k]=v[k];
	}
	mergeSort(a,0,n-1);

	REP(k,0,n-1)
	{
	file<<x->F<<','<<y->F<<','<<a[k]<<'\n';
	}	

	}
	
	
	}
	file.close();
	file.open("grades-sorted-Q.csv",std::fstream::in | std::fstream::out | std::fstream::app);
	for(x=m1.begin();x!=m1.end();x++)
	{

	map<string,vector<string> > m;
	vector<pair<string,string> > v = x->S;
	vector<pair<string,string> > :: iterator it;
	for(it = v.begin();it!=v.end();it++)
	{

	map<string,vector<string> > :: iterator it1=m.find(it->F);
	if(it1!=m.end())
	{
	it1->S.PB(it->S);
	}
	else
	{
	vector<string> v;
	v.PB(it->S);
	m.insert(MP(it->F,v));
	}

	}
	map<string,vector<string> > :: reverse_iterator y;
	
	for(y=m.rbegin();y!=m.rend();y++)
	{

	vector<string> v = y->S;
	ll n= v.size();
	string a[n];

	REP(k,0,n-1)
	{
	a[k]=v[k];
	}
	quickSort(a,0,n-1);

	REP(k,0,n-1)
	{
	file<<x->F<<','<<y->F<<','<<a[k]<<'\n';
	}	

	}
	
	
	}


    }


    }
     
   
     
     
     
    ll myXOR(ll x, ll y)
    {
       return (x | y) & (~x | ~y);
    }
     
    ll min(ll a,ll b)
    {
      if(a>b)
      return b;
      return a;
    }
     
    ll max(ll a,ll b)
    {
      if(a<b)
      return b;
      return a;
    }
     
    ll gcd(ll a, ll b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
     
    ll diff(ll a,ll b)
    {
      if(a>b)
      return a-b;
      return b-a;
    }
     
    void swap(ll *a,ll *b)
    {
      ll t=*a;
      *a=*b;
      *b=t;
    }
     
    ll lcm(ll a, ll b)
    {
        if(a==0)
        return b;
        if(b==0)
        return a;
        return (a*b)/gcd(a, b);
    }
     
    ll modpower(ll x, ll y, ll p)
    {
        ll res = 1;      // Initialize result
     
        x = x % p;  // Update x if it is more than or
                    // equal to p
     
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;
     
            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
     
    ll power(ll x, ll y)
    {
        ll temp;
        if( y == 0)
            return 1;
        temp = power(x, y/2);
        if (y%2 == 0)
            return temp*temp;
        else
            return x*temp*temp;
    }
     
    ll modulo( ll value, ll m)
    {
        ll mod = value % m;
        if (value < 0) {
            mod += m;
        }
        return mod;
    }
     
    vector<ll> initializeDiffArray(vector<ll>& A)
    {
        ll n = A.size();
     
        // We use one extra space because
        // update(l, r, x) updates D[r+1]
        vector<ll> D(n + 1);
     
        D[0] = A[0], D[n] = 0;
        for (ll i = 1; i < n; i++)
            D[i] = A[i] - A[i - 1];
        return D;
    }
     
    // Does range update
    void update(vector<ll>& D, ll l, ll r, ll x)
    {
        D[l] += x;
        D[r + 1] -= x;
    }
     
    // Prints updated Array
    void getArray(vector<ll>& A, vector<ll>& D)
    {
        for (ll i = 0; i < A.size(); i++) {
            if (i == 0)
                A[i] = D[i];
     
            // Note that A[0] or D[0] decides
            // values of rest of the elements.
            else
                A[i] = D[i] + A[i - 1];
        }
    }

