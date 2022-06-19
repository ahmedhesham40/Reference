#define MAXNODES 100009

struct DSU
{
    int parent[MAXNODES];
    int rank[MAXNODES];
    int GroupSize[MAXNODES];

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

    // merge by rank
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
    
    //merge by size
    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        if(leader1 == leader2)  return;

        if(GroupSize[leader1] > GroupSize[leader2])
        {
            parent[leader2] =  leader1;
            GroupSize[leader1] += GroupSize[leader2];
        }

        else
        {
            parent[leader1] =  leader2;
            GroupSize[leader2] += GroupSize[leader1];
        }
    }
};
