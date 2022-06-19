#define MAXNODES 100009

struct DSU
{
    int parent[MAXNODES];
    int rank[MAXNODES];

    DSU()
    {
        for(int i = 0; i < MAXNODES; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int FindLeader(int i)
    {
        if(parent[i] == i)  return i;

        return parent[i] = FindLeader(parent[i]);
    }

    bool SameGroup(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        return leader1 == leader2;
    }


    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        if(leader1 == leader2)  return;
        if(rank[leader1] < rank[leader2])swap(a,b);
        parent[leader2] = leader1;
        if(rank[leader1] == rank[leader2])
            rank[leader1]++;
    }
};
