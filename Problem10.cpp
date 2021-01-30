//Silalak Kaewjanpet 610510670 sec001
#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int t;

//Adjacency list node
struct AdjListNode
{
    int vertex_no;
    struct AdjListNode*next;
};

//Adjacency list
struct AdjList
{
    struct AdjListNode*head;
};


struct Graph{
    int noofvertex;
    struct AdjList*array;
};


struct  AdjListNode*newAdjListNode(int v)
{
    struct AdjListNode*newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode -> vertex_no = v;
    newNode -> next = NULL;
    return newNode;
};


struct Graph*createGraph(int n)
{
    int i;
    struct Graph*graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> noofvertex = n;

    graph -> array = (struct AdjList*)malloc(n* sizeof(struct AdjList));

    for(i=0; i<n; i++)
    {
        graph -> array[i].head = NULL;
    }
    return graph;
};


void addEdge(struct Graph*graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode -> next = graph -> array[src].head;
    graph -> array[src].head = newNode;
}


void printGraph(struct Graph* graph)
{
    int v;
    for(v=0; v<graph -> noofvertex; v++){
        struct AdjListNode* p = graph -> array[v].head;
        cout << "\n Adjacency list of vertex" << v << "\n head";

        while(p != NULL)
        {
            cout << "->" << p -> vertex_no;
            p = p -> next;
        }
        cout << "\n";
    }
}


int isAdjecent(struct Graph*graph, int src, int dest){
    struct AdjListNode*p = graph -> array[src].head;
    while(p != NULL)
    {
        if(p -> vertex_no == dest)
        {
            return 1;
        }
        p = p -> next;
    }
    return 0;
}


void dfsvisit(struct Graph*graph, int d[], int f[], int v)
{
    int i;
    int n = graph -> noofvertex;
    t = t + 1;
    d[v] = t;
    cout << v + 1 << " ";

    for(i = 0; i < n; i++)
    {
        if(isAdjecent(graph, v, i) and d[i] == 0)
        {
            dfsvisit(graph, d, f, i);
        }
    }
    t = t + 1;
    f[v] = t;
}


void dfs(struct Graph*graph, int d[], int f[] , int s)
{
    t = 0;
    dfsvisit(graph, d, f, s);
}


void bfs(struct Graph*graph, int d[], int s)
{
    int u;
    int n = graph -> noofvertex;
    queue <int> Q;
    Q.push(s);
    d[s]++;

    while(!Q.empty())
    {
        u = Q.front();
        cout << u + 1 << " ";
        Q.pop();

        for(int i=0; i<n; i++)
        {
            if(isAdjecent(graph, u, i) and d[i] == 0)
            {
                d[i]++;
                Q.push(i);
            }
        }
    }
}


int main()
{
    int v, e, up, vp, s;
    cin >> v;
    cin >> e;
    int d[v], f[v], f2[v];
    Graph*graph = createGraph(v);
    for(int k = 0; k < v; k++)
    {
        d[k] = 0;
        f[k] = 0;
        f2[k] = 0;
    }
    for(int i = 0; i < e; i++)
    {
        cin >> up >> vp;
        addEdge(graph , up - 1 , vp - 1);
    }
    cin >> s;
    bfs(graph, f2, s-1);
    cout << endl;
    dfs(graph, d, f, s-1);

}
