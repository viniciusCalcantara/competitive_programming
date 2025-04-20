#include <bits/stdc++.h>
#define MAXN 100'000

using namespace std;

/*
-> Cool related problems
https://atcoder.jp/contests/abc401/tasks/abc401_f
*/

vector<vector<int>> tree(MAXN);

int maxDist;
int furthestNode;

/*
-> Trees always have N - 1 edges where N is the
    number of nodes.

-> because of that fact we can traverse using a dfs
    without using an array of visited vertices.

-> It's enough to hol the previous visited vertex.
*/
void dfs(int x, int previous, int depth)
{
    if (depth > maxDist)
    {
        maxDist = depth;
        furthestNode = x;
    }

    for (int c : tree[x])
    {
        if (c != previous)
        {
            dfs(c, x, depth + 1);
        }
    }
}


/*
-> we run two DFS. 
 
-> The first DFS finds the furthest node u
    for some arbitrary vertex.

-> The second DFS finds the furthest node v
    from u.

-> The path from u to v is a possible diameter
    of the tree

-> There is a proof for why that works

-> Another interesting property is: The furthest node j from
    some arbitrary vertex i is always u or v, that is, j is
    always an endpoint of the diameter.
*/
void findDiameter()
{
    maxDist = 0;
    furthestNode = 0;
    dfs(0, 0, 0);
    int u = furthestNode;
    
    maxDist = 0;
    furthestNode = u;
    dfs(u, u, 0);
    int v = furthestNode;
}

int main()
{
    int N;
    cin >> N;

    int u, v;
    // a tree always has n-1 edges
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> u >> v;
        tree[--u].push_back(--v);
        tree[v].push_back(u);
    }

    return 0;
}