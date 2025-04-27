#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct maze {
    int object;
    int visited;
} maze;
#define R 10
#define C 12
maze map[R][C] = {
    {{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0}},
    {{1,0},{-1,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{1,0}},
    {{1,0},{0,0},{1,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{1,0}},
    {{1,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{1,0},{0,0},{0,0},{0,0},{1,0}},
    {{1,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{1,0}},
    {{1,0},{1,0},{0,0},{1,0},{0,0},{1,0},{0,0},{1,0},{1,0},{0,0},{0,0},{1,0}},
    {{1,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{1,0},{1,0}},
    {{1,0},{0,0},{1,0},{0,0},{1,0},{0,0},{0,0},{1,0},{0,0},{1,0},{0,0},{3,0}},
    {{1,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{1,0},{0,0},{0,0},{0,0},{1,0}},
    {{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0},{1,0}}
};

void generateRandomMap() {
    srand(time(NULL)); 
    for (int i = 1; i < R-1; i++) {
        for (int j = 1; j < C-1; j++) {
            int randValue = rand() % 10; 
            if (randValue < 7) {
                map[i][j].object = 0; 
            } else {
                map[i][j].object = 1; 
            }
        }
    }
    printf("Generated map:\n");
    char visualMap[10][12];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            if (map[i][j].object == 1) {
                visualMap[i][j] = '#'; 
            } else if (map[i][j].object == 3) {
                visualMap[i][j] = 'E'; 
            }else if (map[i][j].object == -1) {
                visualMap[i][j] = 'S'; 
            } 
            else{
                visualMap[i][j] = ' '; 
            }
        }
    }
    visualMap[1][1] = 'S';
    visualMap[R-3][C] = 'E';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            printf("%c ", visualMap[i][j]);
        }
        printf("\n");
    }
}


typedef struct {
    int x, y;
} Point;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int minstep = 0;
void printMap(Point path[], int step) {
    char visualMap[10][12];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            if (map[i][j].object == 1) {
                visualMap[i][j] = '#'; 
            } else if (map[i][j].object == 3) {
                visualMap[i][j] = 'E'; 
            }else if (map[i][j].object == -1) {
                visualMap[i][j] = 'S'; 
            } 
            else{
                visualMap[i][j] = ' '; 
            }
        }
    }
    visualMap[path[0].x][path[0].y] = 'S';
    for (int i = 1; i <= step; i++) {
        visualMap[path[i].x][path[i].y] = 'O'; 
    }
    visualMap[path[step].x][path[step].y] = 'E';
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            printf("%c ", visualMap[i][j]);
        }
        printf("\n");
    }
}

int dfs(Point start, int step, Point path[]) {
    map[start.x][start.y].visited = 1;
    path[step] = start;
    
    if (map[start.x][start.y].object == 3) {
        printf("Path found:\n");
        printMap(path, step);
        minstep= step;
        return 1; 
    }

    for (int i = 0; i < 4; i++) {
        Point next;
        next.x = start.x + dx[i];
        next.y = start.y + dy[i];
        if (next.x >= 0 && next.x < 10 && next.y >= 0 && next.y < 12 &&
            !map[next.x][next.y].visited &&
            (map[next.x][next.y].object == 0 || map[next.x][next.y].object == 3)) {
            if (dfs(next, step + 1, path)) {
                return 1; 
            }
        }
    }

    map[start.x][start.y].visited = 0;
    return 0; 
}

int main() {
    generateRandomMap();
    Point start = {1, 1};
    Point path[120]; 
    if (!dfs(start, 0, path)) {
        printf("No way out\n");
    }else{
        printf("A good map, you need %d step out\n", minstep);
    }

    return 0;
}