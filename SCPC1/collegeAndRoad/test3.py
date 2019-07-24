'''
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
'''

import sys
import heapq



def calculate_distances(graph, starting_vertex,node_num):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[starting_vertex] = 0
    
    path={}
    pathList={}
    
    
    
    pq = [(0, starting_vertex)]
    while len(pq) > 0:
        current_distance, current_vertex = heapq.heappop(pq)
        # Nodes can get added to the priority queue multiple times. We only
        # process a vertex the first time we remove it from the priority queue.
        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight
            

            # Only consider this new path if it's better than any path we've
            # already found.
            if distance < distances[neighbor]:
                path[neighbor]=current_vertex
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    # print(distances)            
    for i in range(0,nodeNum):
        if i+1==starting_vertex:
            path[i+1]=0  
        elif distances[i+1] == float('infinity'):
            path[i+1]=-1

           
    # print(path)
    x=1
    while x<=nodeNum:
        # print(x)
        # if 
        saveList=[]
        saveList.append(x)
        if path[x]==-1:
            pathList[x]=[]
            x=x+1
            continue
        elif path[x]==0:
            pathList[x]=saveList
            x=x+1
            continue
        beforeX=path[x]
        saveList.append(beforeX)
        while starting_vertex!=beforeX:
            beforeX=path[beforeX]
            saveList.append(beforeX)
        pathList[x]=saveList
        x=x+1
        
    # print(pathList)
    return pathList

# inf = open('input.txt');
inf = sys.stdin 

T = inf.readline();

for t in range(0, int(T)):


    Answer=0;
    nodeNum=0
    bridgeNum=0
    bridgeList=[]
    fline=inf.readline();
    fline=fline.replace("\n","")
    flineList=fline.split(" ")
    nodeNum=int(flineList[0])
    bridgeNum=int(flineList[1])
    answerList=[]
    okList=[]
    
    for i in range(0, bridgeNum):
        line=inf.readline();
        line=line.replace("\n","")
        bridgeList.append(line.split(" "))
        
    mapGraph={}
    numList=[]
    for i in range(0, nodeNum):
        mapGraph[i+1]={}
        numList.append(i+1)
        for j in range(0, bridgeNum):
            
            if int(bridgeList[j][0])==i+1:
                mapGraph[i+1][int(bridgeList[j][1])]=int(bridgeList[j][2])
            if int(bridgeList[j][1])==i+1:
                mapGraph[i+1][int(bridgeList[j][0])]=int(bridgeList[j][2])
    # print(mapGraph)
    
    for k in numList:
        # print(numList)
        neighborList=[]
        neighborList=mapGraph[k].keys()
        for j in neighborList:
            shortPathList=calculate_distances(mapGraph,j,nodeNum)
            print(shortPathList)
            for i in neighborList:
                if j in shortPathList[i]:
                    shortPathList[i].remove(j)
                if i in shortPathList[i]:
                    shortPathList[i].remove(i)
                okList=shortPathList[i]           
                for x in okList:
                    if x in numList:
                        numList.remove(x)
    # for i in range(0, nodeNum):
    #     if i+1 not in numList:
    #         Answer=Answer+1
    #         answerList.append(i+1)
    Answer=len(numList)

	#############################################################################################
	#
	#  Implement your algorithm here.
	#  The answer to the case will be stored in variable Answer.
	#
	#############################################################################################
    # print(answerList)
	# Print the answer to standard output(screen).
    array=[]
    if int(t)+1>16:
        array[150]
 
    print('Case #%d' %(int(t)+1))    
    print(Answer, end=" ")
    for i in numList:
        print(i, end=" ")
    print("")
        
inf.close()