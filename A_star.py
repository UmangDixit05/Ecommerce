import heapq

# 0 = free path
# 1 = obstacle

grid = [
    [0, 0, 0],
    [1, 0, 1],
    [0, 0, 0]
]

# Start and Goal positions
start = (0, 0)
goal = (2, 2)

# Heuristic Function (Manhattan Distance)
def heuristic(a, b):

    return abs(a[0] - b[0]) + abs(a[1] - b[1])


# A* Algorithm
def astar():

    # Priority Queue
    pq = []

    heapq.heappush(pq, (0, start))

    visited = set()

    while pq:

        cost, current = heapq.heappop(pq)

        # Goal reached
        if current == goal:

            print("Goal Reached")
            return

        # Skip visited nodes
        if current in visited:
            continue

        visited.add(current)

        x, y = current

        # Possible movements
        directions = [
            (-1, 0),  # Up
            (1, 0),   # Down
            (0, -1),  # Left
            (0, 1)    # Right
        ]

        for dx, dy in directions:

            nx = x + dx
            ny = y + dy

            # Check boundaries
            if nx >= 0 and ny >= 0 and nx < 3 and ny < 3:

                # Ignore obstacles
                if grid[nx][ny] == 0:

                    new_cost = cost + 1 + heuristic((nx, ny), goal)

                    heapq.heappush(pq, (new_cost, (nx, ny)))

    print("No Path Found")


# Run A*
astar()