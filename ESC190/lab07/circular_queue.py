class CircularQueue:
    def __init__(self, sz, start):
        self.sz = sz
        self.queue = [None] * sz
        self.start = start
        self.end = start
        self.cur_size = 0
        
    def enqueue(self, item):
        if self.queue[self.start] is None:
            self.queue[self.start] = item
            self.cur_size += 1
            self.end = self.start
        elif self.cur_size != self.sz:    
            ind = -1
            if self.end + 1 != self.sz:
                self.queue[self.end+1] = item
                ind = self.end + 1
            else:
                for i in range(0, self.start):
                    if self.queue[i] is None:
                        self.queue[i] = item
                        ind = i
                        break
            self.end = ind
            self.cur_size += 1
        else:
            print("Queue is full")
    
    def dequeue(self):
        if self.cur_size != 0:
            item = self.queue[self.start]
            self.queue[self.start] = None
            if self.start + 1 != self.sz:
                self.start += 1
            else:
                self.start = 0
            self.cur_size -= 1
            return item
        else:
            print("Queue is empty")
    
    def __repr__(self):
        out = "Current Queue: ["
        for i in range(0, self.sz-1):
            out += str(self.queue[i]) + ", "
        out += str(self.queue[self.sz-1]) + "]"
        # out += "\tCircularQueue: ["
        # for i in range(self.start, self.sz):
        #     if i == self.end:
        #         out += str(self.queue[i]) + "]"
        #     elif self.queue[i] is not None:
        #         out += str(self.queue[i]) + ", "
        
        # for i in range(0, self.end):
        #     if i == self.end:
        #         out += str(self.queue[i]) + "]"
        #     elif self.queue[i] is not None:
        #         out += str(self.queue[i]) + ", "
        
        return out
    
    def __lt__(self, other):
        for i in range(0, min(self.cur_size, other.cur_size)):
            if self.queue[(self.start + i) % self.sz] < other.queue[(other.start + i) % other.sz]:
                return True
            elif self.queue[(self.start + i) % self.sz] > other.queue[(other.start + i) % other.sz]:
                return False
        return False
        

if __name__ == "__main__":
    q = CircularQueue(5, 1)
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    print(q)
    q.dequeue()
    print(q)
    q.enqueue(4)
    print(q)
    q.enqueue(5)
    print(q)
    q.enqueue(6)
    print(q)
    
    m = CircularQueue(5, 2)
    m.enqueue(1)
    m.enqueue(2)
    m.enqueue(3)
    print(q, m)
    print(q < m)