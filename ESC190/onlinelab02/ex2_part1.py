"""
Part 1: Python Max-Priority Queue

This module implements a Max-Priority Queue in Python.

A priority queue is a data structure that allows elements to be inserted with an associated priority,
and supports efficient retrieval and removal of the element with the highest priority. In a max-priority queue,
the element with the largest priority value is always served before others.

Typical operations include:
- Insertion of elements with a priority
- Retrieval of the maximum-priority element
- Removal of the maximum-priority element

Priority queues are commonly used in scheduling, graph algorithms (like Dijkstra's and Prim's), and other applications
where ordering by priority is required.

You will now implement a simple priority that stores only the integer keys. 
The priority queue will be implemented using a max-heap, which is a binary tree 
where each parent node is greater than or equal to its children.

You are not allowed to use the built-in heapq.
"""

class MaxHeap:
    def __init__(self):
        self.heap = []

    def insert(self, key):
        if not self.heap:
            self.heap.append(key)
            return
        for i in range(len(self.heap)):
            if self.heap[i] < key:
                self.heap.insert(i, key)
                return
        self.heap.append(key)

    def pop(self):
        if self.heap:
            return self.heap.pop(0)
        return None
    
    def __repr__(self):
        return f"MaxHeap({self.heap})"
        

if __name__ == "__main__":
    max_heap = MaxHeap()
    
    max_heap.insert(27)
    max_heap.insert(89)
    max_heap.insert(-29)
    max_heap.insert(13)
    max_heap.insert(83)
    max_heap.insert(-48)
    max_heap.insert(-9)
    max_heap.insert(-50)
    max_heap.insert(2)
    max_heap.insert(26)
    
    print(max_heap)

    print(max_heap.pop())