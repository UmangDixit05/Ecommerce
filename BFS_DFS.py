graph = {}

v = int(input("Enter number of vertices: "))
e = int(input("Enter number of edges: "))

# Create graph
for i in range(e):

    u = int(input("Enter first vertex: "))
    vtx = int(input("Enter second vertex: "))

    if u not in graph:
        graph[u] = []

    if vtx not in graph:
        graph[vtx] = []

    graph[u].append(vtx)
    graph[vtx].append(u)


def dfs(start):
    
    visited = []
    
    stack = []
    
    stack.append(start)
    
    while (len(stack)>0):
       
       node = stack.pop()
       
       if node not in visited:
          
          visited.append(node)
          
          print(node, end=" ")
          
          for neighbour in reversed(graph[node]):
          
             if  neighbour not in visited:
             
                stack.append(neighbour)

# BFS
def bfs(start):

    visited = []

    queue = []

    visited.append(start)

    queue.append(start)

    while len(queue) > 0:

        node = queue[0]

        queue.pop(0)

        print(node, end=" ")

        for neighbor in graph[node]:

            if neighbor not in visited:

                visited.append(neighbor)

                queue.append(neighbor)


start = int(input("Enter starting vertex for DFS: "))

print("DFS Traversal:")
dfs(start)

start = int(input("\nEnter starting vertex for BFS: "))

print("BFS Traversal:")
bfs(start)
