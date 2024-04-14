#include <stdio.h>

#define ROWS 6
#define COLS 6

// Function to print the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Flood fill algorithm
// :TODO: 
// - algorithm is insufficient. 
// - keep working on this
void floodFill(char maze[ROWS][COLS], int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] != ' ') {
        return;
    }

    // Mark current cell as visited
    maze[x][y] = '.';

    // Recursive calls to neighboring cells
    floodFill(maze, x + 1, y); // Down
    floodFill(maze, x - 1, y); // Up
    floodFill(maze, x, y + 1); // Right
    floodFill(maze, x, y - 1); // Left
}

int main() {
    char maze[ROWS][COLS] = {
        {' ', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' '},
        {'#', '#', '#', ' ', '#', ' '},
        {'#', ' ', ' ', ' ', ' ', ' '},
    };

    printf("Original maze:\n");
    printMaze(maze);

    // Start flood fill from position (0, 0)
    floodFill(maze, 0, 0);

    printf("\nMaze after flood fill:\n");
    printMaze(maze);

    return 0;
}
