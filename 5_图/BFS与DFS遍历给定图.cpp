#include <iostream>
#include <vector>
#include <queue>

void BFS(std::vector<std::vector<int>>& matrix, int start, std::vector<bool> visited){
    std::queue<int> q;

    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int elem = q.front();
        q.pop();
        std::cout<<elem<<' ';
        for(int v = 0; v < 9; v++){
            if(!visited[v] && matrix[elem][v]){
                q.push(v);
                visited[v] = 1;
            }
        }
    }

}

void DFS(std::vector<std::vector<int>> &matrix, int start, std::vector<bool> &visited){
    visited[start] = 1;
    std::cout<<start<<' ';

    for(int i = 0; i < 9; i++){
        if(!visited[i] && matrix[start][i]){
            DFS(matrix, i, visited);
        }
    }
}

int main(){
    std::vector<bool> visited(9,0);
    int start = 0;
    std::vector<std::vector<int>> matrix(9, std::vector<int>(9,0));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            std::cin>>matrix[i][j];
        }    
    }

    std::cout<<std::endl;
    BFS(matrix, start, visited);
    std::cout<<std::endl;
    DFS(matrix, start, visited);

    return 0;
}