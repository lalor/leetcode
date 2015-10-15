#include <iostream>
#include<vector>

using namespace std;

class Solution {
    private:
        vector< vector<int> > result;

        void combination(vector<int> &v, int end, int length) {
            if (v.size() == length) {
                result.push_back(v);
                return;
            } else {
                for (int i = i; i <= end; i++) {
                    v.push_back(i);
                    combination(v,  end, length);
                    v.pop_back();
                }
            }
        }
    public:
        vector< vector<int> > combine(int n, int k) {
            vector<int> v;
            combination(v, n, k);
            return result;
        }


};

void print(vector<vector<int> > &v) {

    cout << "**************************************" << endl;
    vector< vector<int> >::iterator it = v.begin();
    for (; it != v.end(); it++) {
        vector<int>::iterator innerIt = (*it).begin();
        for( ; innerIt != (*it).end(); innerIt++) {
            cout << *innerIt << "\t";
        }
        cout << endl;
    }
    cout << "**************************************" << endl;
}

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int> >v = s.combine(4, 2);
    cout << v.size() << endl;
    print(v);

    return 0;
}
