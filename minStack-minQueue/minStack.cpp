#include <bits/stdc++.h>

using namespace std;

struct minStack
{

    stack<pair<int, int>> st;

    void add(int new_elem)
    {
        int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
        st.push({new_elem, new_min});
    }

    void pop()
    {
        int removed_element = st.top().first;
        st.pop();
    }

    int find_min()
    {
        return st.top().second;
    }
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}