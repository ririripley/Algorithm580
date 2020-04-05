//
// Created by 黄紫君 on 18/03/2020.
//
#define  LEN    100
#define  INF 10000
#include <queue>
#include <iostream>
using namespace std;

struct EData{
    int _start;
    int _end;
    int _dis;

    void setEData(int start, int end, int dis) {
        _start = start;
        _end = end;
        _dis = dis;

        if(start > end){
        _start = end;
        _end = start;
    } }

    bool operator > (const EData& second) const {
        return this->_dis > second._dis;
    }
};


struct Graph{
    Graph(int vexnum, int edgnum) : vexnum(vexnum), edgnum(edgnum) {};

    int vexnum;  // number of vertex
    int edgnum;  // number of edges
    int matrix[LEN][LEN];  // whether 2 vertices are connected or not
//    int vexs[LEN]; // STORE INFO ABOUT VERTICES

};

priority_queue<EData, vector<EData>, greater<EData> > sorted_edges(EData *pData, int edgnum);


/**
 * based on the matrix, we can get the edge info stored in an edge array based on the matrix
 * 2 points, and the distance bewteen 2 points
 */
EData* get_edges(Graph G){
    int edgnum = G.edgnum;
    EData *edges = new EData[edgnum];
    int number = 0;
    for(int i = 0; i < G.vexnum; i++){
        for(int j = i + 1; j < G.vexnum; j++){
            if(G.matrix[i][j] != INF){
                (edges[number]).setEData(i,j,G.matrix[i][j]);

                //cout << " start: " << edges[number]._start << "   " << edges[number]._end << "  " << edges[number]._dis << endl;
                number++; // 外加的number及其容易忘记更新导致结果出错！！！！！！
            }
        }
    }
    return edges;
}

/**
 * build a priority queue to store the info of edges
 * a priority queue will return the edge with the shortest distance every time
 */
priority_queue<EData, vector<EData>, greater<EData> > sorted_edges(EData *pData, int edgnum) {
    priority_queue< EData, vector<EData>, greater<EData> > myque;
    for (int i =0; i  < edgnum; i++){
        myque.push(pData[i]);
    }
    return myque;
}

int find_vex_fin(int vex, int vex_fin[]){
  while(vex_fin[vex] != vex){
      vex = vex_fin[vex];
  }
    return vex;
}

void Kruskal(Graph G){
    int vex_num = G.vexnum;

    int vex_fin[LEN];

    for(int i = 0; i < vex_num; i++){
        vex_fin[i] = i;
    }

    EData result[LEN]; // store the picked edges
    EData* edges = get_edges(G);


    priority_queue< EData, vector<EData>, greater<EData> > que = sorted_edges(edges, G.edgnum);

    int index = 0;
    int total_dis = 0;

    while(!que.empty()){
        //pick out the shortest edge, judge whether it will lead to as internal circle in the current network
        EData edge = que.top();
        que.pop();


        int start = edge._start;
        int end = edge._end;


        int start_fin = find_vex_fin(start, vex_fin);
        int end_fin = find_vex_fin(end, vex_fin);



        if(start_fin != end_fin){

            result[index] = edge;
            total_dis += edge._dis;

            index++;
            vex_fin[start] = end;

            if(start_fin < end_fin){
                vex_fin[start_fin] = end_fin;
            }
            else{
                vex_fin[end_fin] = start_fin;
            }
        }
    }
    delete []edges;
    cout << total_dis << endl;
    for (int i = 0; i < index; i++){
        cout << result[i]._start << " end :  "  <<  result[i]._end << endl;
    }

}




int main(){

    Graph G(7, 12);

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            G.matrix[i][j] =INF;
        }
    }

    G.matrix[0][0] = 0;
    G.matrix[1][1] = 0;
    G.matrix[3][3] = 0;
    G.matrix[2][2] = 0;
    G.matrix[4][4] = 0;
    G.matrix[5][5] = 0;
    G.matrix[6][6] = 0;



    G.matrix[0][1] = 12;G.matrix[0][2] = 14;G.matrix[0][3] = 16;
    G.matrix[1][3] = 7;G.matrix[1][4] = 10;
    G.matrix[4][6] = 3;G.matrix[4][5] = 5;G.matrix[5][6] = 4;
    G.matrix[2][3] = 9;G.matrix[2][5] = 8;
    G.matrix[3][4] = 6;G.matrix[3][5] = 2;
    Kruskal(G);


}