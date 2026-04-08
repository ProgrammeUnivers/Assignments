#include "maze.h"
#include <stdio.h>
#include <stdlib.h>

struct Maze{
    char **grid;
    int cols, rows; 
    int playerX, playerY;
    int startX, startY;
};

struct Maze *readMaze(){
   int Startcount = 0;
   int Goalcount = 0;
   char c;
   int rows = 0;
   int cols = 0;

   struct Maze *newMaze = malloc(sizeof(struct Maze));
   newMaze->grid = NULL;

   while(1){
    int col = 0;
    char *rowBuf = malloc(256);

        while (scanf("%c", &c) == 1 && c != '\n'){
            if(c == 'S'){
                newMaze->playerX = col;
                newMaze->playerY = rows;
                newMaze->startX = col;
                newMaze->startY = rows;
                ++Startcount;
            }
            else if(c == 'G'){
                ++Goalcount;

            }
            rowBuf[col++] = c;
        }
        if (col == 0){
            free(rowBuf);
            break;
        }
        rowBuf[col] = '\0';
        cols = col;

        newMaze->grid = realloc (newMaze->grid, sizeof(char *) * (rows + 1));
        newMaze->grid[rows] = rowBuf;
        rows++;

    }
    newMaze->rows = rows;
    newMaze->cols = cols;

    if(Startcount != 1 || Goalcount < 1){
        for(int i = 0; i < rows; i++){
            free(newMaze->grid[i]);
        }
        free(newMaze->grid);
        free(newMaze);
        return NULL;
    } 

    return newMaze;

}


void printMaze(struct Maze *m) {

    for(int i = 0; i < m->cols + 2; i++){
        printf("=");
    }
    printf("\n");

    for(int i = 0; i < m->rows; i++){
        printf("|");
        for(int j = 0; j < m->cols; j++){
            if(m->playerX == j && m->playerY == i){
                printf("P");
            }
            else{
            printf("%c", m->grid[i][j]); 
            }
        }
        printf("|\n");
    }

    for(int i = 0; i < m->cols + 2; i++){
        printf("=");
    }
    printf("\n");

}

struct Pos makeMove(struct Maze *m, char dir) {
    struct Pos p;
    p.x = m->playerX;
    p.y = m->playerY;
    return p;

    int newX = m->playerX;
    int newY = m->playerY;
    
    if (dir == 'n') newY--;
    else if (dir == 's') newY++;
    else if (dir == 'e') newX++;
    else if (dir == 'w') newX--;

    if (newX < 0 || newX >= m->cols || newY < 0 || newY >= m->rows) {
        p.x = m->playerX;
        p.y = m->playerY;
        return p; 
    }

    char tile = m->grid[newY][newX];

    if (tile == 'X') {
        p.x = m->playerX;
        p.y = m->playerY;
        return p;
    } 
    else if (tile == 'G') {
        m->playerX = newX;
        m->playerY = newY;
        p.x = -1;
        p.y = -1;
        return p;
    } 
    else if (tile >= '0' && tile <= '9') {
        for(int i = 0; i < m->rows; i++){
            for(int j = 0; j < m->cols; j++){
                if(m->grid[i][j] == tile && newY != i && newX != j){
                    newY = i;
                    newX = j;
                    m->playerY = newY;
                    m->playerX = newX;
                }
            }
        }    
    } 
    else if (tile == 'I') {
        int slideX = newX;
        int slideY = newY;

        while (1) {
        
            int nextX = slideX;
            int nextY = slideY;
            if (dir == 'n') nextY--;
            else if (dir == 's') nextY++;
            else if (dir == 'e') nextX++;
            else if (dir == 'w') nextX--;

            
            if (nextX < 0 || nextX >= m->cols || nextY < 0 || nextY >= m->rows) {
                break; 
            }

            
            if (m->grid[nextY][nextX] == 'X') {
                break;
            }

            
            slideX = nextX;
            slideY = nextY;

            
            if (m->grid[slideY][slideX] != 'I') {
                break;
            }
        }
    
        
        newX = slideX;
        newY = slideY;
        
        
        m->playerX = newX;
        m->playerY = newY;
        
        
        if (m->grid[newY][newX] == 'G') {
            p.x = -1; p.y = -1;
            return p;
        
        } 
        else {
            m->playerX = newX;
            m->playerY = newY;
        }

        p.x = m->playerX;
        p.y = m->playerY;
        return p;
    }
}


void reset(struct Maze *m) {
    m->playerX = m->startX;
    m->playerY = m->startY;
}



struct Maze *destroyMaze(struct Maze *m) {
    for(int i= 0; i < m->rows; i++){
        free(m->grid[i]);
    }

    free(m->grid);

    free(m);

    return NULL;
}

