#include<bits/stdc++.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
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

ll credits(string s)
{
  ll n = s.size();
  ll ans=0;
  REP(i,0,n-1)
  ans+=int(char(s[i]-'0'))*pow(10,n-i-1);
  return ans;
}

ll point(string s)
{
  if(s=="AA")
  return 10;
  if(s=="AB")
  return 9;
  if(s=="BB")
  return 8;
  if(s=="BC")
  return 7;
  if(s=="CC")
  return 6;
  if(s=="CD")
  return 5;
  if(s=="DD")
  return 4;


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

ll st = open("students03.csv",O_RDONLY);

REP(i,0,18)
{
  char *buff=(char*)malloc(sizeof(char)*34);
  string n="",r="";
  ll t=read(st,buff,34);
  ll j=0;
  while(buff[j]!=',')
  {n.PB(buff[j]);j++;}
  j++;
  while(buff[j]!='\n'&&buff[j]!='\0')
  {r.PB(buff[j]);j++;}

  ll fd = open((r+".txt").c_str(),O_CREAT|O_WRONLY|O_TRUNC,0600);
  string ans="Name: ";
  ans+=n;
  ans+='\n';
  ans+="Roll Number: ";
  ans+='\n';
  ll fd1,fd2;
  ld cpi[8],spi[8];
  ll total=0,score=0;
  REP(s,1,8)
  {
    ll ctotal=0,cscore=0;
    ans+="SEMESTER: ";
    ans.PB(char(48+s));
    ans+='\n';
    ans+="Course Number | Course Name | C | Grade\n";

    fd1 = open("courses03.csv",O_RDONLY);
    REP(c,1,20)
    {
      string sem="",cname1="",cnum1="",cred="";
      char *buff1 = (char*)malloc(sizeof(char)*56);
      ll r2 = read(fd1,buff1,56);

      ll mi1=0;
      while(buff1[mi1]!=',')
      {sem.PB(buff1[mi1]);mi1++;}
      mi1++;
      while(buff1[mi1]!=',')
      {cnum1.PB(buff1[mi1]);mi1++;}
      mi1++;
      while(buff1[mi1]!=',')
      {cname1.PB(buff1[mi1]);mi1++;}
      mi1++;
      while(buff1[mi1]!=',')
      mi1++;
      mi1++;
      while(buff1[mi1]!=',')
      mi1++;
      mi1++;
      while(buff1[mi1]!=',')
      mi1++;
      mi1++;
      while(buff1[mi1]!='\n'&&buff1[mi1]!='\0')
      {cred.PB(buff1[mi1]);mi1++;}
      mi1++;
      fd2 = open("grades03.csv",O_RDONLY);
      REP(x,1,20)
      {

        char *buff2 = (char*)malloc(sizeof(char)*20);
        string roll="",cnum="",grd="";
        ll r1 = read(fd2,buff2,20);
        ll mi=0;
        while(buff2[mi]!=',')
        {roll.PB(buff2[mi]);mi++;}
        mi++;
        while(1)
        {
          if(buff2[mi]==' ')
          {
            mi+=2;
            break;
          }
          else
          if(buff2[mi]==',')
          {
            mi++;
            break;
          }
          else
          {cnum.PB(buff2[mi]);mi++;}
        }

        while(buff2[mi]!='\n'&&buff2[mi]!='\0')
        {grd.PB(buff2[mi]);mi++;}


        if(cnum1==cnum&&roll==r&&s==int(sem[0]-'0'))
        {

          ans+=cnum;
          ans+="            ";
          ans+=cname1;
          ans+="        ";
          ans+=cred;
          ans+="     ";
          ans+=grd;
          ans+="\n";
          ctotal+=credits(cred);
          cscore+=point(grd)*credits(cred);

        }
      }
      close(fd2);

    }
    close(fd1);
    score+=cscore;
    total+=ctotal;
    spi[s-1]=double(cscore)/double(ctotal);
    cpi[s-1]=double(score)/double(total);

  }
  ans+="\n";
ans+="         ";
ans+="1        ";
ans+="2        ";
ans+="3        ";
ans+="4        ";
ans+="5        ";
ans+="6        ";
ans+="7        ";
ans+="8        \n";
ans+="SPI      ";
REP(y,0,7)
{ans+=to_string(spi[y]);ans+="    ";}
ans+="\n";
ans+="CPI      ";

REP(y,0,7)
{ans+=to_string(cpi[y]);ans+="    ";}
ans+="\n";
ans+="\n";

  ll temp=write(fd,ans.c_str(),ans.size());

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
