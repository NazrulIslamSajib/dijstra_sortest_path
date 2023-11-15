#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mx=100100+123;
ll i;
vector<pair<ll,ll>>adj[mx];
ll path[mx];
vector<ll>ans;
ll dis[mx];
ll max1=10000000000000000;
ll cnt=0;
void dijstra(ll s,ll n)
{
    for(i=1;i<=n;i++)
    {
        dis[i]=max1;
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        ll u=pq.top().second;
        ll curD=pq.top().first;
        pq.pop();
        if(curD>dis[u])
        {
           continue;
        }
       // cnt++;
        for(auto v:adj[u])
        {
            if(v.second+curD<dis[v.first])
            {
                dis[v.first]=v.second+curD;
                pq.push({dis[v.first],v.first});
                path[v.first]=u;
            }
        }
    }
    if(dis[n]==max1)
    {
        cout<<"-1"<<endl;
    }
    else
    {
    ans.push_back(n);
    ll u=n;
    while(path[u]!=0)
    {
      ans.push_back(path[u]);
      u=path[u];
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    }

}
int main()
{
  ll n,m,j;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
      ll u,v,w;
      cin>>u>>v>>w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
  }
  dijstra(1,n);
  ///cout<<cnt<<endl;

  return 0;

}
