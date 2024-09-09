class Solution {
public:
    typedef long long LL;
    static const int N=1010;
    int w[N]={0};
struct Node
{
    int l, r;
    LL sum, add;
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[r], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
    }
    else    // 一定要分裂
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}


    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
      
        build(1,1,startTime.size());
        for(int i=0;i<endTime.size();i++){
            modify(1,startTime[i],endTime[i],1);
        }
        return query(1,queryTime,queryTime);
    }
};
