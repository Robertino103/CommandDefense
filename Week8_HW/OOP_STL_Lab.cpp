#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    struct cmp {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        }
    };

    ifstream fin("input.in");
    string s;
    string delim = ".,?! ";
    vector<string> v;

    getline(fin, s);

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    char ch;
    bool ok;
    int poz = 0;

    for (int i = 0; i < s.length(); i++)
    {
        ch = s.at(i);
        ok = false;
        for (int j = 0; j < delim.length(); j++)
        {
            if (ch == delim.at(j)) ok = true;
        }
        if (ok == true) {
            string substring = s.substr(poz, i - poz);
            poz = i + 1;
            if (substring.length() > 0) v.push_back(substring);
        }
    }

    map<string, int> mp;

    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }
    
    vector<pair<string, int>> freq;

    for (auto str : mp)
    {
        freq.push_back(make_pair(str.first, str.second));
    }

    priority_queue <pair<string, int>, vector<pair<string, int>>, cmp> pq;
    for (auto i : freq)
    {
        pq.push(i);
    }

    while (!pq.empty())
    {
        cout << pq.top().first << " => " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}