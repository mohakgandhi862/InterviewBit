#include<iostream>
#include <vector>
#include <map>
using namespace std;

int f(vector<int> A) {

    int n = A.size();
    map<int,int> m;
    map<int, int> :: iterator itr;
    int i, ans=0,tmp;

    for (i = 0; i < n; i++) {
        
        itr = m.find(A[i] + 1);
        if (itr == m.end()) {
            ans++;
        }
        else {
            tmp = itr->second;
            m.erase(itr);
            if(tmp>1) m.insert(make_pair(A[i]+1,tmp-1));
        }
        
        itr = m.find(A[i]);
        if (itr != m.end()) {
            tmp = itr->second+1;
            m.erase(itr);
        }
        else tmp = 1;
        m.insert(make_pair(A[i], tmp));
    }

    return ans;
}

int main() {

    vector<int> v = { 5, 4, 3, 3, 2, 2, 1, 1, 1 };
    int ans = f(v);
    cout << ans << endl;  // Answer is 3

    return 0;
}
