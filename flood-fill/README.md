# Flood fill

## Overview

- Maze Solving
  - Maze Design
  - Maze Solving Algorithms
- Flood fill
  - High-level Principles
  - Demo
  - Implementation

## Maze Solving

- 16 x 16 cells, each cell is 18 cm x 18 cm.
- Start is in the lower left corner.
- Goal is the center: 4 cells total, entering any one of them is considered finishing.
- We need to navigate the maze with no prior knowledge of the walls contained in it.

## Maze solving approaches

1. Dead reckoning - Works for __paths__, not __branched mazes__. Goes straight 
    until a wall is hit, choose to either take left of right.
2. Wall follower - Works for __simply connected__ mazes. Always takes the 
    left turn. Won't work if goal is in the middle of the maze.
3. Random - At each __intersection__, choose __randomly__ with direction
    to go. Would take a very long time.
4. Tremaux's Algorithm - Mark __paths__ you've visited and prefer the
    unvisited ones. Does __not__ guarantee the __shortest path__.
5. Flood fill - guarantees the __shortest path__ after several run.

## Floodfill

#### High level idea

> Heard of Noah's Ark?

* __Goal__: find a path between start and end point. 
* __Working principle__: is to imagine pouring out a bucket of water at the goal. The water will flow around walls and eventually reach the starting point.
Intuitively, the path the water takes is the shortest valid path between the two points. 

### Manhattan Distance

- You can't travel through walls.
- Number of cells from a given cell to the goal.
- The number of moves to get to the goal from a given cell.
- Move towards cell that have smaller Manhatan distances from the goal.

### Flood fill for solving maze

1. Assume maze has no walls to start. Use floodfill to calculate initial    
    Manhattan distances.
2. Travel towards __decreasing numbers__.
3. If you stuck (surrounded by walls and larger numbers) then use floodfill to 
    __recalculate__ true Manhattan distances.

As we learn about the maze, we __re-simulate__ the fluid pour from the goal to 
see what the true Manhattan distances should be.

#### Traversing the Maze

*Draw maze calculation progression*

## Floodfill Pseudocode

1. Set all cells except goal to "*blank state*"
2. Set goal cell(s) value to 0 and add to queue.
3. While queue is not empty:
  a. Take front cell in queue "out of line" for consideration
  b. Set all __blank__ and __accessible__ neighbors to front cell's value + 1.
  c. Add cells we just process to the queue.
  d. ELse, continue!

## Demo

maze:
- start: [4,0]
- goal: [2,2]

queue: (circular array)
- [0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]
- [2,1],[1,2],[2,3],[3,2],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]
- [0,0],[1,2],[2,3],[3,2],[2,0],[1,1],[3,1],[0,0],[0,0],[0,0],[0,0],[0,0]
- [0,0],[0,0],[2,3],[3,2],[2,0],[1,1],[3,1],[0,2],[1,3],

> 4,0
 -  4,  3,  2,  3,  4
 -  3,  2,  1,  2,  3
 -  2,  1,  0,  1,  2
 -  3,  4,  1,  2,  3
 -  4,  3,  2,  3,  4

> 2,1 
 -  4,  3,  2,  3,  4
 -  3,  2,  1,  2,  3
 -  4,  3,  0,  1,  2
 -  5,  2,  1,  2,  3
 -  6,  3,  2,  3,  4

 > 1,2
 -  4,  3,  2,  3,  4
 -  5,  4,  5,  2,  3
 -  4,  3,  0,  1,  2
 -  5,  2,  1,  2,  3
 -  6,  3,  2,  3,  4

 > 3,1
 -  6,  5,  4,  3,  4
 -  7,  6,  7,  2,  3
 -  6,  5,  0,  1,  2
 -  7,  4,  1,  2,  3
 -  8,  3,  2,  3,  4

> 4,2
 -  6,  5,  4,  3,  4
 -  7,  8,  9,  2,  3
 -  8,  7,  0,  1,  2
 -  9,  6,  1,  2,  3
 - 10,  5,  4,  3,  4

 > 4,3
 -  6,  5,  4,  3,  4
 -  7,  8,  9,  2,  3
 - 10,  9,  0,  1,  2
 - 11,  8,  1,  2,  3
 - 12,  7,  6,  5,  4

struct:
- horizontal walls
- vertical walls
- manhattan distances