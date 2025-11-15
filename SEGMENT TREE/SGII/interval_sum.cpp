#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> st;
    int n;

    void build(const vector<int>& arr, int l, int r, int idx) {
        if (l == r) {
            st[idx] = arr[l];
            return;
        }
        int m = (l + r) / 2;
        build(arr, l, m, 2*idx+1);
        build(arr, m+1, r, 2*idx+2);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }

    int query(int l, int r, int idx, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return st[idx];
        int m = (l + r) / 2;
        return query(l, m, 2*idx+1, ql, qr) + query(m+1, r, 2*idx+2, ql, qr);
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        st.assign(4*n, 0);
        build(arr, 0, n-1, 0);
    }
    int sumOfInterval(int l, int r) {
        return query(0, n-1, 0, l, r);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    SegmentTree st(arr);
    cout << "Sum of [2,5]: " << st.sumOfInterval(2, 5) << endl; // Output: 3+4+5+6=18
    cout << "Sum of [0,6]: " << st.sumOfInterval(0, 6) << endl; // Output: 28
    return 0;
}
