#include <iostream>
#include <queue>

#define N 10
using namespace std;

void iniMatAdj(bool matAdj[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matAdj[i][j] = false;
        }
    }
}

void leeMatAdj(bool matAdj[N][N], int e)
{
    int origen, destino;
    for (int i = 0; i < e; i++)
    {
        cin >> origen >> destino;
        matAdj[origen - 1][destino - 1] = matAdj[destino - 1][origen - 1] = true;
    }
}

void printMat(bool matAdj[N][N], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << (matAdj[i][j] ? "T" : "F") <<"\t";
        }
        cout<<endl;
    }
}

void BFS(bool madAdj[N][N], int v){
    queue<int> fila;
    vector<bool> status(v, false);
    int data;

    fila.push(0);
    status[0] = true;

    while (!fila.empty()){
        data = fila.front();
        fila.pop();
        cout<< (data+1)<<" ";
        for (int i=0;i<v;i++){
            if (!status[i] && madAdj[data][i]){
                status[i] = true;
                fila.push(i);
            }
        }
    }
    cout<<endl;
}

int main()
{
    bool matAdj[N][N];
    int v, e;

    cin >> v >> e;

    iniMatAdj(matAdj);
    leeMatAdj(matAdj, e);
    printMat(matAdj, v);

    BFS(matAdj, v);
    return 0;
}