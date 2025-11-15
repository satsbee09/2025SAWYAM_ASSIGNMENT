#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
    vector<int> st, lazy;
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

    void push(int l, int r, int idx) {
        if (lazy[idx] != 0) {
            st[idx] += (r - l + 1) * lazy[idx];
            if (l != r) {
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    int rangeQuery(int l, int r, int idx, int ql, int qr) {
        push(l, r, idx);
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return st[idx];
        int m = (l + r) / 2;
        return rangeQuery(l, m, 2*idx+1, ql, qr) + rangeQuery(m+1, r, 2*idx+2, ql, qr);
    }

    void rangeUpdate(int l, int r, int idx, int ul, int ur, int val) {
        push(l, r, idx);
        if (ul > r || ur < l) return;
        if (ul <= l && r <= ur) {
            lazy[idx] += val;
            push(l, r, idx);
            return;
        }
        int m = (l + r) / 2;
        rangeUpdate(l, m, 2*idx+1, ul, ur, val);
        rangeUpdate(m+1, r, 2*idx+2, ul, ur, val);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }

public:
    LazySegmentTree(const vector<int>& arr) {
        n = arr.size();
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(arr, 0, n-1, 0);
    }
    int rangeSum(int l, int r) {
        return rangeQuery(0, n-1, 0, l, r);
    }
    void rangeAdd(int l, int r, int val) {
        rangeUpdate(0, n-1, 0, l, r, val);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    LazySegmentTree st(arr);
    cout << "Sum [1,3] = " << st.rangeSum(1, 3) << endl; // Output: 15
    st.rangeAdd(1, 4, 10); // add 10 to arr[1..4]
    cout << "Sum [1,3] after range update = " << st.rangeSum(1, 3) << endl; // Output: 45
    return 0;
}
