# The visited variable keeps a record of the nodes explored
def dfs(graph,start,goal,stack,visited):
    stack.append(start)
    visited.append(start)
    print('The path traversed is:')
    while stack:
        # Pop from stack to set current element
        element=stack.pop()
        print(element,end=" ")
        if(element==goal):
            break
        for neighbor in graph[element]:
            if neighbor not in visited:
                stack.append(neighbor)
                visited.append(neighbor)
# A dictionary representing the illustrated graph
graph={
    'A':['C','B'],
    'B':['E','D'],
    'C':['G','F'],
    'D':[],
    'E':['I','H'],
    'F':[],
    'G':['J'],
    'H':[],
    'I':[],
    'J':[]
}
start='A'
goal='J'
visited=[]
stack=[]

dfs(graph,start,goal,visited,stack)


