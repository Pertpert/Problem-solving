#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  vector<int> vec{10, 20, 4, 24, 1, 2, 43, -1, 23};
  stack<pair<int, int>> stack_min;

  for(int i : vec) {
    int new_min = stack_min.empty() ? i : min(i, stack_min.top().second);
    stack_min.push(make_pair(i, new_min));
  }

  while(!stack_min.empty()) {
    stack_min.pop();
    cout << stack_min.top() << 
  }

  return 0;
}
