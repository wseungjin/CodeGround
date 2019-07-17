'''
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
'''

import sys

'''
	The method below means that the program will read from input.txt, instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and call below method to read from the file when using open() method.
	You may remove the comment symbols(#) in the below statement and use it.
	But before submission, you must remove the open function or rewrite comment symbols(#).
'''
def max(a,b):
    if a>=b:
        return a
    else:
        return b


inf = open('input.txt');
# inf = sys.stdin 

T = inf.readline();



for t in range(0, int(T)):
    
    num=inf.readline()
    line=inf.readline()
    sList=line.split(" ")
    sList.insert(0,"0")
    sList.append("0")
    nList=[]
    Answer=0;
    saveList=[]
    flag=1
    
    
    
    for p in range(0,int(num)+2):
        saveList.append(0)
        nList.append(int(sList[p]))
        
    print(nList)
    
    while(flag!=0):
        for k in range(1,int(num)+1):
            if nList[k-1]>=nList[k] and nList[k+1]>=nList[k]:
                saveList[k]=1
            elif nList[k-1]>=nList[k] and nList[k+1]<nList[k]:
                saveList[k]=nList[k]-nList[k+1]
            elif nList[k-1]<nList[k] and nList[k+1]>=nList[k]:
                saveList[k]=nList[k]-nList[k-1]
            elif nList[k-1]<nList[k] and nList[k+1]<nList[k]:
                saveList[k]=max(nList[k]-nList[k-1],nList[k]-nList[k+1])

        flag=0
        for p in range(0,int(num)+2):
            if nList[p]-saveList[p]>=0:
                nList[p]=nList[p]-saveList[p]
            
            if nList[p]!=0:
                flag=flag+1
        print(nList)
        Answer=Answer+1
    
    
	#############################################################################################
	#
	#  Implement your algorithm here.
	#  The answer to the case will be stored in variable Answer.
	#
	#############################################################################################
	
	# Print the answer to standard output(screen).
    print('Case #%d' %(int(t)+1))    
    print(Answer)
inf.close()