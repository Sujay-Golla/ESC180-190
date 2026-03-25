import random
import numpy as np

class Node:
    def __init__(self, data):
        self.data = data
        self.neighbours = []
    
    def add_neighbour(self, node2):
        self.neighbours.append(node2)

class Graph:
    def __init__(self):
        self.nodes = []

    def add_node(self, node):
        self.nodes.append(node)
        
        
def random_step(graph, current):
    for node in graph.nodes:
        if node.data == current:    
            return random.choice(node.neighbours).data

# def random_walk(graph, start, steps):
#     cur = start
#     for i in range(steps):
#         cur = random_step(graph, cur)
#     return cur

# def transition_matrix(graph):
#     n = len(graph.nodes)
#     matrix = np.zeros((n, n))
    
#     for i in range(len(graph.nodes)):
#         node = graph.nodes[i]
#         prob = 1.0 / len(node.neighbours)
#         for neighbour in node.neighbours:
#             j = graph.nodes.index(neighbour)
#             matrix[i][j] = prob

#     return matrix

# def pagerank(matrix, v, n, k):
#     for i in range(k):
#         v = matrix @ v
    
#     return v

if __name__ == "__main__":
    g = Graph()
    for i in range(4):
        g.add_node(Node(i))
    
    g.nodes[0].add_neighbour(g.nodes[1])
    g.nodes[0].add_neighbour(g.nodes[2])
    g.nodes[1].add_neighbour(g.nodes[2])
    g.nodes[2].add_neighbour(g.nodes[0])
    g.nodes[2].add_neighbour(g.nodes[3])
    g.nodes[3].add_neighbour(g.nodes[0])
    
    arr = [0] * 4
    end = random_step(g, 0)
    for i in range(10000):
        end = random_step(g, end)
        arr[int(end)] += 1

    for i in range(4):
        print(f"Node {i}: {arr[i]}")