#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int graph[10][10], int color[], int n, int col){

    for(int k=0; k<n; k++){

        if(graph[node][k] == 1 && color[k] == col){
            return false;
        }
    }

    return true;
}

bool graphColoring(int graph[10][10], int m, int color[], int node, int n){
  
    if(node == n){
        return true;
    }

    for(int col=1; col<=m; col++){

        if(isSafe(node, graph, color, n, col)){

            color[node] = col;

            if(graphColoring(graph, m, color, node+1, n)){
                return true;
            }

            color[node] = 0;
        }
    }

    return false;
}

int main(){

    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10];

    cout << "\nEnter adjacency matrix:\n\n";

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            cout << "Enter value for Vertex "
                 << i << " and Vertex "
                 << j << " : ";

            cin >> graph[i][j];
        }
    }

    cout << "\nEnter number of colors: ";
    cin >> m;

    int color[10] = {0};

    if(graphColoring(graph, m, color, 0, n)){

        cout << "\nSolution Exists:\n\n";

        for(int i=0; i<n; i++){

            cout << "Vertex "
                 << i
                 << " ---> Color "
                 << color[i]
                 << endl;
        }
    }
    else{

        cout << "\nSolution does not exist";
    }

    return 0;
}
