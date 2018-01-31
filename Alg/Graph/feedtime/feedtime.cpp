#include<iostream>
#include<queue>
using namespace std;
const int MAX=760;

struct node
{
    int x,y;
    char gr;
};

int counts;
node nod[MAX][MAX];
int visit[MAX][MAX];
int bfs(int a,int b)
{
    queue<node>que;
    node nod2;
    int i,j;
    que.push(nod[a][b]);
    visit[a][b]=1;
    counts++;
    while(!que.empty())
    {
        nod2=que.front();
        que.pop();
        i=nod2.x;
        j=nod2.y;
        if(nod[i-1][j].gr=='.' && visit[i-1][j]==0)
        {
            que.push(nod[i-1][j]);
            visit[i-1][j]=1;
            counts++;
        }
        if(nod[i+1][j].gr=='.' && visit[i+1][j]==0)
        {
            que.push(nod[i+1][j]);
            visit[i+1][j]=1;
            counts++;
        }
        if(nod[i][j-1].gr=='.' && visit[i][j-1]==0)
        {
            que.push(nod[i][j-1]);
            visit[i][j-1]=1;
            counts++;
        }
        if(nod[i][j+1].gr=='.' && visit[i][j+1]==0)
        {
            que.push(nod[i][j+1]);
            visit[i][j+1]=1;
            counts++;
        }
        if(nod[i-1][j-1].gr=='.' && visit[i-1][j-1]==0)
        {
            que.push(nod[i-1][j-1]);
            visit[i-1][j-1]=1;
            counts++;
        }
        if(nod[i+1][j+1].gr=='.' && visit[i+1][j+1]==0)
        {
            que.push(nod[i+1][j+1]);
            visit[i+1][j+1]=1;
            counts++;
        }
        if(nod[i-1][j+1].gr=='.' && visit[i-1][j+1]==0)
        {
            que.push(nod[i-1][j+1]);
            visit[i-1][j+1]=1;
            counts++;
        }
        if(nod[i+1][j-1].gr=='.' && visit[i+1][j-1]==0)
        {
            que.push(nod[i+1][j-1]);
            visit[i+1][j-1]=1;
            counts++;
        }
    }
    return counts;
}

int main()
{
    int i,j;
    int w,h;
    int large=0;
    cin>>w>>h;
    for(i=1;i<=h;i++)
        for(j=1;j<=w;j++)
        {
            cin>>nod[i][j].gr;
            nod[i][j].x=i;
            nod[i][j].y=j;
            visit[i][j]=0;
        }
    for(i=1;i<=h;i++)
        for(j=1;j<=w;j++)
        {
            if(nod[i][j].gr=='.' && visit[i][j]==0)
            {
                counts=0;
                counts=bfs(i,j);
                if(counts>large)large=counts;
            }
        }
    cout<<large<<endl;
    return 0;
}
