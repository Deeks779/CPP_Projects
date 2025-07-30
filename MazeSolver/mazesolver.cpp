#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Cell {
public:
    int x, y;
    Cell(int i = -1, int j = -1) : x(i), y(j) {}
    bool operator==(const Cell& c) const {
        return x == c.x && y == c.y;
    }
};

class Maze {
public:
    Maze();
    void solve();

private:
    Cell currentCell, exitCell, entryCell;
    const char exitMarker = 'e';
    const char entryMarker = 'm';
    const char passage = '0';
    const char pathMarker = '*';

    vector<string> store;
    vector<vector<Cell>> parentGrid;

    void readMazeData();
    void findEntryAndExit();
    void reconstructAndPrintPath();

    friend ostream& operator<<(ostream& out, const Maze& maze);
};

Maze::Maze() {
    readMazeData();
    findEntryAndExit();
    parentGrid.assign(store.size(), vector<Cell>(store[0].size()));
}

void Maze::readMazeData() {
    string line;
    cout << "Enter a rectangular maze using the following characters:\n"
          << "m - entry\ne - exit\n1 - wall\n0 - passage\n"
          << "Enter one line at a time; end with Ctrl-Z (Windows) or Ctrl-D (Unix):\n";

    while (getline(cin, line) && !line.empty()) {
        store.push_back(line);
    }
}

void Maze::findEntryAndExit() {
    for (int r = 0; r < store.size(); r++) {
        for (int c = 0; c < store[r].size(); c++) {
            if (store[r][c] == entryMarker) {
                entryCell = Cell(r, c);
            } else if (store[r][c] == exitMarker) {
                exitCell = Cell(r, c);
            }
        }
    }
}

void Maze::solve() {
    stack<Cell> s;
    s.push(entryCell);
    parentGrid[entryCell.x][entryCell.y] = Cell(entryCell.x, entryCell.y); 

    bool exitFound = false;
    while (!s.empty()) {
        currentCell = s.top();
        s.pop();

        if (currentCell == exitCell) {
            exitFound = true;
            break;
        }

        int r = currentCell.x;
        int c = currentCell.y;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];

            if (newR >= 0 && newR < store.size() && newC >= 0 && newC < store[0].size() &&
                (store[newR][newC] == passage || store[newR][newC] == exitMarker) &&
                parentGrid[newR][newC].x == -1) 
            {
                parentGrid[newR][newC] = currentCell; 
                s.push(Cell(newR, newC));
            }
        }
    }

    if (exitFound) {
        cout << "\nSuccess: Exit found!\n";
        reconstructAndPrintPath();
    } else {
        cout << "\nFailure: No path found.\n";
    }
}

void Maze::reconstructAndPrintPath() {
    vector<string> displayMaze = store;
    Cell current = exitCell;

    while (!(current == entryCell)) {
        if (!(current == exitCell)) { 
            displayMaze[current.x][current.y] = pathMarker;
        }
        current = parentGrid[current.x][current.y];
    }
    displayMaze[entryCell.x][entryCell.y] = pathMarker; 

    for (const auto& row : displayMaze) {
        std::cout << row << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Maze& maze) {
    for (const auto& row : maze.store) {
        out << row << std::endl;
    }
    return out;
}

int main() {
    Maze maze;
    maze.solve();
    return 0;
}