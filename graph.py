class Node:
    def __init__(self,data):
        self.data = data
        self.next_element = None

class LinkedList:
    def __init__(self):
        self.head_node = None
    
    def get_head(self):
        return self.head_node
    
    def is_empty(self):
        if(self.head_node is None):
            return True
        else:
            return False
        
    def insert_at_head(self,dt):
        temp_node = Node(dt)
        if(self.is_empty()):
            self.head_node = temp_node
            return self.head_node
        temp_node.next_element = self.head_node
        self.head_node = temp_node
        return self.head_node
    
    def insert_at_tail(self,dt):
        new_node = Node(dt)
        if self.get_head() is None:
            self.head_node = new_node
            return
        wh = self.get_head()
        while wh.next_element is not None:
            wh = wh.next_element
        wh.next_element = new_node
        return 
    
    def length(self):
        wh = self.get_head()
        len=0
        while wh is not None:
            wh=wh.next_element
            len+=1
        return len

    def print_len(self):
        wh = self.get_head()
        while wh is not None:
            print(wh.data)
            wh=wh.next_element

    def delete_at_head(self):
        fe = self.get_head()
        if fe is not None:
            self.head_node = fe.next_element
            fe.next_element = None
        return
    
class MyQueue:
    def __init__(self):
        self.queue_list = []
        self.queue_size = 0

    def is_empty(self):
        return self.queue_size == 0

    def front(self):
        if self.is_empty():
            return None
        return self.queue_list[0]

    def rear(self):
        if self.is_empty():
            return None
        return self.queue_list[-1]

    def size(self):
        return self.queue_size
    
    def enqueue(self, value):
        self.queue_size += 1
        self.queue_list.append(value)

    def dequeue(self):
        if self.is_empty():
            return None
        front = self.front()
        self.queue_list.remove(self.front())
        self.queue_size -= 1
        return front
    
class MyStack:
    def __init__(self):
        self.stack_list = []
        self.stack_size = 0

    def is_empty(self):
        return self.stack_size == 0

    def peek(self):
        if self.is_empty():
            return None
        return self.stack_list[-1]

    def size(self):
        return self.stack_size
    
    def push(self, value):
        self.stack_size += 1
        self.stack_list.append(value)

    def pop(self):
        if self.is_empty():
            return None
        self.stack_size -= 1
        return self.stack_list.pop()

class Graph1:
    def __init__(self,vertices):
        self.vertices = vertices
        self.array = []
        for i in range(vertices):
            self.array.append(list())
        
    def add_edge(self,source,destination):
        self.array[source].append(destination)
        self.array[destination].append(source)
    
    def print_graph(self):
        print(">>Adjacency List of Directed Graph<<")
        for i in range(self.vertices):
            print("|", i, end=" | => ")
            for j in range(len(self.array[i])):
                print("[",self.array[i][j], end=" ] -> ")
            print("None")

class Graph:
    def __init__(self,vertices):
        self.vertices = vertices
        self.array = []
        for i in range(vertices):
            self.array.append(LinkedList())
    
    def add_edge(self,source,destination):
        self.array[source].insert_at_head(destination)

    def print_graph(self):
        print(">>Adjacency List of Directed Graph<<")
        for i in range(self.vertices):
            print("|", i, end=" | => ")
            temp = self.array[i].get_head()
            while temp is not None:
                print("[", temp.data, end=" ] -> ")
                temp = temp.next_element
            print("None")

def bfs_traversal(graph, source):
    que = MyQueue()
    lst = list()
    l1 = list()
    for i in range(graph.vertices):
        l1.append(0)
    que.enqueue(source)
    l1[source] = 1
    while que.is_empty()==False:
        temp = que.dequeue()
        # l1[temp] = 1
        lst.append(temp)
        temp1 = graph.array[temp].head
        while temp1 is not None:
            if l1[temp1.data]==0:
                que.enqueue(temp1.data)
                l1[temp1.data] = 1
            temp1 = temp1.next
    return lst

def dfs_traversal(graph, source):
    res = []
    verti = graph.vertices
    visited = [False] * verti
    stack = MyStack()
    stack.push(source)
    visited[source]=True
    while not stack.is_empty():
        cv = stack.pop()
        res.append(cv)
        temp = graph.array[cv].head
        while temp is not None:
            if not visited[temp.data]:
                stack.push(temp.data)
                visited[temp.data]=True
            temp = temp.next
    return res

def detect_cycle(g):
    visited = [False] * g.vertices
    rec_node_stack = [False] * g.vertices
    for node in range(g.vertices):
        # DFS recursion call
        if detect_cycle_rec(g, node, visited, rec_node_stack):
            return True
    return False

def detect_cycle_rec(g, node, visited, rec_node_stack):
    if rec_node_stack[node]:
        return True
    if visited[node]:
        return False
    visited[node] = True
    rec_node_stack[node] = True
    head_node = g.array[node].head_node
    while head_node is not None:
        adjacent = head_node.data
        if detect_cycle_rec(g, adjacent, visited, rec_node_stack):
            return True
        head_node = head_node.next_element
    rec_node_stack[node] = False
    return False

def dfs_traversal1(g,source):
    st = MyStack()
    lst = list()
    l1 = list()
    for i in range(g.vertices):
        l1.append(0)
    st.push(source)
    l1[source]=1
    while st.is_empty()==False:
        temp = st.pop()
        lst.append(temp)
        temp1 = g.array[temp].head_node
        while temp1 is not None:
            if l1[temp1.data]==0:
                st.push(temp1.data)
                l1[temp1.data]=1
            temp1=temp1.next_element
    return len(lst)==g.vertices
def find_mother_vertex(g):
    for i in range(g.vertices):
        lst_ans = dfs_traversal1(g,i)
        if(lst_ans==1):
            return i

    return -1

def count_edges(graph):
    sum = 0
    for i in range(graph.vertices):
        sum += len(graph.adjacency[i])
    return sum//2

def dfs_travseral2(g,visited,source,destination):
    if source==destination:
        return True
    visited[source]=True
    for i in range(len(g.array[source])):
        if visited[g.array[source][i]]==False:
            if (dfs_travseral2(g,visited,g.array[source][i],destination)==True):
                return  True
    return False

def check_path(n, edges, source, destination):
    g = Graph1(n)
    for i in range(len(edges)):
        g.add_edge(edges[i][0],edges[i][1])
    visited = [False]*n
    return dfs_travseral2(g,visited,source,destination)

def is_tree(graph):
    visited = [False]*graph.vertices
    par = -1
    if rec1(graph,0,visited,par)==True:
        return False
    for i in range(len(visited)):
        if not visited[i]:
            return False
    return True

def rec1(g,node,visited,par):
    visited[node]=True
    h_node = g.array[node].head
    while h_node :
        ad = h_node.data
        if visited[ad]==False:
            if rec1(g,ad,visited,node):
                return True
        elif(ad!=par):
                return True
        h_node = h_node.next
    return False

def find_min(g, src, dest):
    if src==dest:
        return 0
    vert = g.vertices
    que = MyQueue()
    visited = [False]*vert
    dis = [0]*vert
    que.enqueue(src)
    visited[src]=True
    while que.is_empty()==False:
        temp = que.dequeue()
        temp1 = g.array[temp].head_node
        while temp1 is not None:
            if visited[temp1.data]==False:
                que.enqueue(temp1.data)
                visited[temp1.data]=True
                dis[temp1.data] = dis[temp] + 1
            if temp1.data==dest:
                return dis[temp1.data]
            temp1=temp1.next_element
    return -1

def remove_edge(graph, source, destination):
    for i in range (len(graph.adjacency[source])):
        if graph.adjacency[source][i]==destination:
            graph.adjacency[source].pop(i)
            break
    return graph

