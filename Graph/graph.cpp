// Find if path exists
https://leetcode.com/problems/find-if-path-exists-in-graph/description/



// Minimum steps by knight
https://www.naukri.com/code360/problems/minimum-steps-to-reach-target-by-a-knight_893050


Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure to hold knight position and distance
struct Cell {
    int x, y, dist;
};

// All 8 possible moves for a knight
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Function to check if position is valid on board
bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int minKnightMoves(int N, pair<int, int> start, pair<int, int> target) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Cell> q;

    q.push({ start.first, start.second, 0 });
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        if (current.x == target.first && current.y == target.second) {
            return current.dist;
        }

        for (int i = 0; i < 8; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (isValid(nx, ny, N) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny, current.dist + 1 });
            }
        }
    }

    return -1; // Target not reachable
}

int main() {
    int N;
    cout << "Enter board size N: ";
    cin >> N;

    int sx, sy, tx, ty;
    cout << "Enter start position (x y): ";
    cin >> sx >> sy;
    cout << "Enter target position (x y): ";
    cin >> tx >> ty;

    int result = minKnightMoves(N, {sx, sy}, {tx, ty});
    if (result != -1)
        cout << "Minimum steps required: " << result << endl;
    else
        cout << "Target is not reachable." << endl;

    return 0;
}



//  Reorder Routes to Make All Paths Lead to the City Zero
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/


//4. Eventual safe states
https://www.geeksforgeeks.org/problems/eventual-safe-states/1

//5. Longest Cycle in a Graph
https://leetcode.com/problems/longest-cycle-in-a-graph/description/

// Shortest Cycle in a graph
https://leetcode.com/problems/shortest-cycle-in-a-graph/description/


//6. 
https://www.geeksforgeeks.org/problems/topological-sort/1

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u to v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u to v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

Examples:

Input: adj = [[], [0], [0], [0]] 

Output: 1
Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]

//7. Course Schedule
https://leetcode.com/problems/course-schedule-ii/description/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

// 8. Largest Color Value in a Directed Graph
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

// 9.
// Flood Fill
https://leetcode.com/problems/flood-fill/description/


//10.
// Number oF islands

https://leetcode.com/problems/number-of-islands/description/


// 11.
Rotting Oranges
https://leetcode.com/problems/rotting-oranges/description/



//12 Geeks Village and Wells
https://www.geeksforgeeks.org/problems/geeks-village-and-wells--170647/1

// 13. Number of operations to make network connected
https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

// Dijkstra algorithm coverage


// 13.
https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


14. https://leetcode.com/problems/network-delay-time/description/

15.
https://leetcode.com/problems/path-with-maximum-probability/description/

16.
https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/description/


