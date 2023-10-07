# Mouse Maze Solver

This C++ program, `mouse_maze_solver.cpp`, is a simple maze-solving simulation where a mouse (represented by 'M') attempts to find its way to a piece of cheese (represented by '$') in a maze. The program uses a basic pathfinding algorithm to navigate through the maze while avoiding walls (represented by 'X'). The mouse can move in four directions: up, down, left, and right. 

## Maze Representation

The maze is represented as a 2D grid of characters, with the following symbols:
- `'+'`: Boundary of the maze
- `'X'`: Wall or obstacle
- `'O'`: Empty cell that the mouse can traverse
- `'M'`: Current position of the mouse
- `'*$'`: Location of the cheese

## Program Workflow

The program's main components and workflow are as follows:

- The initial maze layout is defined as a 15x15 grid within the `main` function.
- The mouse's starting position (`M`) is set at `(13, 13)` within the maze, and the cheese (`$`) is placed at `(1, 1)`.
- The `printmaze` function is responsible for displaying the maze on the console.
- The `runmouse` function controls the mouse's movement by checking adjacent cells and making decisions based on the following rules:
  - If the mouse encounters the cheese ('`$`') or the exit ('`O`'), it moves in that direction.
  - If none of the above conditions are met, the `stuck` function is called, and the mouse attempts to backtrack or find an alternative path.
- The `stuck` function is used to handle situations where the mouse is stuck and has to backtrack or choose a different path.

## Running the Program

The program enters a loop that iterates up to 1000 times or until the mouse reaches the cheese (`(1, 1)`). During each iteration, the maze is printed to the console, and the mouse's movement is updated.

The `system("clear")` function is used to clear the console screen for a smoother display.

Once the mouse finds the cheese, the program exits and displays a message indicating the success of the mouse in finding the cheese.

## Usage

To run the program, compile it using a C++ compiler and execute the compiled binary. The mouse's pathfinding and maze-solving process will be displayed on the console. This may not work on online compilers

Enjoy exploring the maze-solving adventure of the mouse!
