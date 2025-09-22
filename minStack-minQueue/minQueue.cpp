#include <bits/stdc++.h>

using namespace std;

struct minQueue
{

    stack<pair<int, int>> s1, s2;

    int size() {
        return s1.size() + s2.size();
    }

    void add(int new_elem)
    {
        int minimum = s1.empty() ? new_elem : min(new_elem, s1.top().second);
        s1.push({new_elem, minimum});
    }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                int element = s1.top().first;
                s1.pop();
                int minimum = s2.empty() ? element : min(element, s2.top().second);
                s2.push({element, minimum});
            }
        }
        int remove_element = s2.top().first;
        s2.pop();

        return remove_element;
    }

    int find_min()
    {
        int minimun = 0;
        if (s1.empty() || s2.empty())
            minimun = s1.empty() ? s2.top().second : s1.top().second;
        else    
            minimun = min(s1.top().second, s2.top().second);

        return minimun;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    minQueue q;

    return 0;
}