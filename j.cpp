#include <bits/stdc++.h>

using namespace std;

int get_index_point(string s, int n, int init)
{
    for (int i = init; i < n; i++)
        if (s[i] == '.')
            return i;
    
    return -1;
}

int get_index_not_point(string s, int n, int init)
{
    for (int i = init; i < n; i++)
    {
        if (s[i] != '.')
        {
            while (s[i] != '\0' && s[i] == '#' && s[i] == 'o')
                i++;

            return i;
        }
    }
    
    return -1;
}
int main ()
{
    int n, k;
    cin >> n >> k;
    string s;
    
    cin >> s;
    
    for (int i = 0; i < k; i++)
    {
        int id = get_index_point(s, n, i);
        int aux = i;


        while (aux < id)
        {
            swap(s[aux], s[id]);
            aux++;
        }
    }

    cout << s << '\n';

    return 0;
}