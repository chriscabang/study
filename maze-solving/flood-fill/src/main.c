#include <stdio.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};

int visited[ROWS][COLS] = {0};

// Structure to represent a cell in the maze
struct Cell {
    int row;
    int col;
};

// Function to check if a cell is valid
int isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

// Function to perform flood fill
void floodFill(int startRow, int startCol) {
    int rowOffset[] = {-1, 0, 0, 1};
    int colOffset[] = {0, -1, 1, 0};

    // Create a stack for DFS
    struct Cell stack[ROWS * COLS];

    // Push the starting cell
    int top = 0;
    stack[top].row = startRow;
    stack[top].col = startCol;
    visited[startRow][startCol] = 1;

    // Perform DFS
    while (top >= 0) {
        struct Cell current = stack[top--];

        // Check if current cell is the goal
        if (maze[current.row][current.col] == 2) {
            printf("Maze solved!\n");
            return;
        }

        // Visit all neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + rowOffset[i];
            int newCol = current.col + colOffset[i];

            // If the neighbor is a valid path and not visited, mark it as visited and push to stack
            if (isValid(newRow, newCol) && maze[newRow][newCol] == 0 && !visited[newRow][newCol]) {
                visited[newRow][newCol] = 1;
                stack[++top].row = newRow;
                stack[top].col = newCol;
            }
        }
    }

    printf("Maze cannot be solved!\n");
}

int main() {
    floodFill(0, 0);
    return 0;
}
