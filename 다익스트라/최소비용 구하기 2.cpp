#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int N, M, start_point, end_point;
vector<pair<int,int>> edge[1001];

void dijkstra(){
    vector<int> distance(N+1,1e9);
    distance[start_point]=0;
    vector<int> parent(N+1,1e9);
    parent[start_point]=0;
    priority_queue<pair<int,int>> q;
    q.push({0,start_point});
    while(!q.empty()){
        int past_d = -q.top().first;
        int past_e = q.top().second;
        q.pop();
        if(distance[past_e] < past_d){
            continue;
        }
        for(int i=0; i<edge[past_e].size(); i++){
            int now_e = edge[past_e][i].first;
            int now_d = edge[past_e][i].second;
            if(distance[now_e] > distance[past_e]+now_d){
                distance[now_e]=distance[past_e]+now_d;
                parent[now_e]=past_e;
                q.push({-distance[now_e],now_e});
            }
        }
    }
    cout << distance[end_point] << "\n";
    stack<int> answer;
    int i=end_point;
    answer.push(end_point);
    while(parent[i]!=0){
        if(parent[i]==1e9){
            return;
        }
        answer.push(parent[i]);
        i=parent[i];
    }
    cout << answer.size() << "\n";
    while(answer.empty()==0){
        cout << answer.top() << " ";
        answer.pop();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int x, y, money;
        cin >> x >> y >> money;
        edge[x].push_back({y,money});
    }
    cin >> start_point >> end_point;
    dijkstra();
}