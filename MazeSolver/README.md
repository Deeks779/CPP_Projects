# Algorithmic Maze Solver

A C++ application that solves complex mazes by implementing the Depth-First Search (DFS) algorithm. This tool not only finds a path from an entry to an exit but also reconstructs the single, direct path, providing a clean visual solution.

![Maze Demo]

## 🚀 Features

* **Algorithmic Solver**: Implements the Depth-First Search (DFS) algorithm with a stack to find a path through any valid maze layout.
* **Path Reconstruction**: After finding the exit, the program backtracks to engineer and display only the single, correct path from start to finish.
* **Console Visualization**: Provides clear, text-based feedback in the console, showing the final path through the maze.
* **Dynamic Input**: Accepts custom maze layouts directly from user input in the terminal.

## 🛠️ Tech Stack

* **Language**: C++
* **Key Data Structures**: `std::vector`, `std::string`, `std::stack`
* **Core Algorithm**: Depth-First Search (DFS)

## 🧠 Algorithm Explained

This project uses **Depth-First Search (DFS)**, a classic graph traversal algorithm. The maze is treated as a grid (a type of graph), and DFS explores as far as possible down each branch before backtracking.

1.  A **`std::stack`** is used to keep track of the cells to visit.
2.  Starting from the entry point **'m'**, the algorithm pushes adjacent, unvisited passages onto the stack.
3.  It always explores the most recently added cell, going deeper and deeper into the maze.
4.  If it hits a dead end, it backtracks by popping from the stack until it finds a cell with other unvisited neighbors.
5.  This process continues until the exit **'e'** is found.

## ⚙️ Getting Started

### Prerequisites

You will need a C++ compiler installed on your system, such as **g++**.

### Installation & Usage

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/Deeks779/algorithmic-maze-solver.git](https://github.com/Deeks779/algorithmic-maze-solver.git)
    cd algorithmic-maze-solver
    ```
2.  **Compile the code:**
    ```sh
    g++ main.cpp -o maze_solver
    ```
3.  **Run the executable:**
    ```sh
    ./maze_solver
    ```
4.  **Provide Input:** The program will prompt you to enter the maze. Paste or type your maze layout in the terminal.

    **Input Format:**
    * `m` - entry
    * `e` - exit
    * `1` - wall
    * `0` - passage

    **Example Input:**
    ```
    111111111111
    m0001000100e
    111010101111
    100000100001
    111111111111
    ```
5.  **End Input:** After entering your maze, press `Ctrl+D` (on Linux/macOS) or `Ctrl+Z` then `Enter` (on Windows) to signal the end of the input. The solution will then be displayed.

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page.

## 📜 License

This project is licensed under the MIT License. See `LICENSE` for more details.