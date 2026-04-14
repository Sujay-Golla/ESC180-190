def best_study_schedule(prog, prax, calc, linalg):
    n = len(prog)
    dp = []
    for i in range(5):
        dp.append([float('-inf')] * n)
    
    dp[0][0] = prog[0]
    dp[1][0] = prax[0]
    dp[2][0] = calc[0]
    dp[3][0] = linalg[0]
    dp[4][0] = 0
    
    for i in range(1, n):
        # Programming
        for j in range(5):
            if dp[j][i-1] + prog[i] > dp[0][i]:
                dp[0][i] = dp[j][i-1] + prog[i]
        
        # Praxis
        for j in range(5):
            if dp[j][i-1] + prax[i] > dp[1][i]:
                dp[1][i] = dp[j][i-1] + prax[i]
        
        # Calculus
        for j in [0, 1, 4]:
            if dp[j][i-1] + calc[i] > dp[2][i]:
                dp[2][i] = dp[j][i-1] + calc[i]
        
        # Lin alg
        for j in [0, 1, 4]:
            if dp[j][i-1] + linalg[i] > dp[3][i]:
                dp[3][i] = dp[j][i-1] + linalg[i]
        
        # Nothing
        for j in range(5):
            if dp[j][i-1] > dp[4][i]:
                dp[4][i] = dp[j][i-1]
    
    best_end = 0
    for i in range(5):
        if dp[i][n-1] > dp[best_end][n-1]:
            best_end = i
            
    total = dp[best_end][n-1]
    
    initial = [prog, prax, calc, linalg, [0]*n]
    dict = {0:"prog", 1:"prax", 2:"calc", 3:"linalg", 4:"None"}
    path = [dict[best_end]]
    total -= initial[best_end][n-1]
    
    for i in range(n-2, -1, -1):
        for j in range(5):
            if dp[j][i] == total:
                path.insert(0, dict[j])
                total -= initial[j][i]
                break
    
    return path

class Node:
    def __init__(self, id, weight):
        self.id = id
        self.weight = weight
        
    def __repr__(self):
        return f"Node({self.id}, {self.weight})"
    
    def __lt__(self, other):
        return self.weight < other.weight
    
    def get_neighbors(self, maze):
        neighbors = []
        directions = [(0,1), (0,-1), (1,0), (-1,0)]
        for d in directions:
            new_i = self.id[0] + d[0]
            new_j = self.id[1] + d[1]
            if 0 <= new_i < len(maze) and 0 <= new_j < len(maze[new_i]) and maze[new_i][new_j] != 'X':
                neighbors.append(Node((new_i, new_j), maze[new_i][new_j]))
        return neighbors

def create_nodes(maze):
    nodes = [[] for _ in range(len(maze))]
    for i in range(len(maze)):
        for j in range(len(maze[i])):
            nodes[i].append(Node((i,j), maze[i][j]))
    return nodes

def djikstra(maze, start):
    import heapq
    heap = [(0, start)]
    distances = {}
    for i in range(len(maze)):
        for j in range(len(maze[i])):
            distances[(i,j)] = float('inf')
    distances[start.id] = 0
    
    visited = set()
    
    while heap:
        current_distance, current_node = heapq.heappop(heap)
        
        if current_distance > distances[current_node.id]:
            continue
        
        if current_node.id in visited:
            continue
        visited.add(current_node.id)

        for neighbor in current_node.get_neighbors(maze):
            distance = current_distance + neighbor.weight
            
            if neighbor.id in visited:
                continue
            
            if distance < distances[neighbor.id]:
                distances[neighbor.id] = distance
                heapq.heappush(heap, (distance, neighbor))
    
    return distances

def find_shortest_path(maze, start, end):
    distances = djikstra(maze, start)
    return (distances[end.id] + start.weight) if end.id in distances else float('inf')

def a_star(maze, start, end):
    import heapq
    def h(node):
        return abs(node.id[0] - end.id[0]) + abs(node.id[1] - end.id[1])
    
    came_from = {}
    g_score = {}
    f_score = {}
    for i in range(len(maze)):
        for j in range(len(maze[i])):
            g_score[(i,j)] = float('inf')
            f_score[(i,j)] = float('inf')
    g_score[start.id] = 0
    f_score[start.id] = h(start)
    heap = [(f_score[start.id], start)]
    
    visited = set()
    
    while heap:
        current_f, current_node = heapq.heappop(heap)
        
        if current_node.id == end.id:
            # reconstruct path
            path = []
            while current_node.id in came_from:
                path.insert(0, current_node.id)
                current_node = Node(came_from[current_node.id], maze[came_from[current_node.id][0]][came_from[current_node.id][1]])
            path.insert(0, start.id)
            return path
        
        if current_node.id in visited:
            continue
        visited.add(current_node.id)

        for neighbor in current_node.get_neighbors(maze):
            tentative_g = g_score[current_node.id] + neighbor.weight
            
            if tentative_g < g_score[neighbor.id]:
                came_from[neighbor.id] = current_node.id
                g_score[neighbor.id] = tentative_g
                f_score[neighbor.id] = tentative_g + h(neighbor)
                heapq.heappush(heap, (f_score[neighbor.id], neighbor))
    
    return None  # no path

def star(maze, start, end):
    path = a_star(maze, start, end)
    return path

def one_nearest_neighbor(training_data, new_image):
    min_distance = float('inf')
    nearest_label = None
    for image, label in training_data:
        distance = 0
        for i in range(len(image)):
            for j in range(len(image[i])):
                distance += (image[i][j] - new_image[i][j]) ** 2
        distance = distance ** 0.5
        if distance < min_distance:
            min_distance = distance
            nearest_label = label
    return nearest_label



maze = [
    [2,3,1],
    [6,'X',2],
    [1,4,3]
]
start = Node((0,0), maze[0][0])
end = Node((2,2), maze[2][2])
print(find_shortest_path(maze, start, end))
print(star(maze, start, end))