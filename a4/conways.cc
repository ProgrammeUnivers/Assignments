#include <iostream>
#include <string>
using namespace std;

int countNeighbors(string *grid, int numRows, int numCols, int row, int col){
    int count = 0;
    for(int i = -1; i <= 1 ; i++){
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            int newRow = row + i;
            int newCol = col + j;
            

            if(newCol < 0 || newCol >= numCols) continue;
            if(newRow < 0 || newRow >= numRows) continue;

            if(grid[newRow][newCol] == 'O') count++;


        }
    }
    return count;

}


void step(string *&grid, int numRows, int numCols){
    string *newGrid = new string[numRows];
    for(int i = 0; i < numRows; i++){
        newGrid[i] = grid[i];
    }
    
    
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            int count = countNeighbors(grid, numRows, numCols, i, j);
            
            if(grid[i][j] == 'O'){
                if(count < 2 || count > 3){
                    newGrid[i][j] = '.';
                }
            }
            else{
                if(count == 3){
                    newGrid[i][j] = 'O';
                }
            }

        }
    }
    delete [] grid;
    grid = newGrid;
}

void Gridprint(string *grid, int numRows, int numCols){
    for(int i = 0; i < numCols; i++) cout << '|';
    cout << endl;

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++) cout << grid[i][j];   
        cout << endl;
    }

    for(int i = 0; i < numCols; i++) cout << '|';
    cout << endl;

}


int main() {
    int capacity = 4;
    int numRows = 0;
    int numCols = 0;
    char cmd;
    string *grid = new string[capacity];

    string line;
    while (cin >> line && line != "x"){
        if (numRows == capacity){
            capacity *= 2;
            string *newGrid = new string[capacity];
            for (int i = 0; i < numRows; i++){
                newGrid[i] = grid[i];
            }
            delete[] grid;
            grid = newGrid;
        }
        grid[numRows] = line;
        numRows++;
    }
    numCols = grid[0].length();

    while(cin >> cmd){
        if(cmd == 's'){
            step(grid, numRows, numCols);
        }
        else if(cmd == 'p'){
            Gridprint(grid, numRows, numCols);
        }
    }
    delete [] grid;
}