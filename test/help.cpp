#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> vec;
    
    vector<pair<int, int>> result;
    int l = 0;
    int r = 0;
    
    int temp;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;

        vec.push_back(temp);
        
        if(l != r && temp < vec[r] && l < r)
        {
            result.push_back({l, r});
            l = i;
            r = i;
        }
        
        if(vec[l] > temp)
        {
            l = i;
        }
        else if(vec[r] < temp)
        {
            r = i;
        }
    }
    
    temp = INT_MIN;
    if(l != r && temp < vec[r] && l < r)
        result.push_back({l, r});
    
    
    int sum = 0;
    l = result[0].first;
    r = result[0].second;
    
    for(size_t i = 1; i < result.size(); i++)
    {
        if((r / l) <= result[i].first)
        {
            r = result[i].second;
            continue;
        }
        
        M = round((M / l) * r);
        sum += M;
    }
    
    cout << sum << endl;
    
    return 0;
}q