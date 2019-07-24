'''
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
'''
import math
import sys

'''
	The method below means that the program will read from input.txt, instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and call below method to read from the file when using open() method.
	You may remove the comment symbols(#) in the below statement and use it.
	But before submission, you must remove the open function or rewrite comment symbols(#).
'''

inf = open('input.txt');
# inf = sys.stdin 

T = inf.readline();

for t in range(0, int(T)):
    
    Answer=0
    floatNum=0
    line = []
    line.append(inf.readline());
    line.append("X")
    newline=" ".join(line)
    # print(line)
    # print(newline)
    floatNum=int(newline.find(" "))-2
    average=float(line[0])
    sum=0
    averageRound=int(round(average))
    checkRonud=0
    if average-averageRound<0:
        checkRonud=1
    divideNum=int(1)
    while (average*divideNum)%1!=0 and floatNum!=0:
        # print(average*divideNum)
        divideNum=(int)(divideNum*10)
        floatNum=floatNum-1
    
    k=2
    temp=divideNum
    # print(temp)
    tempnum=int(round(average*divideNum))  
    # print(tempnum)
       
    while k<math.sqrt(temp):
        if tempnum%k==0 and temp%k==0:
            divideNum=divideNum//k
            temp=temp//k
            k=2
        
        k=k+1
    sum=int(round(average*divideNum))
    # print(sum)
    # print(divideNum)
    numList=[0,0,0,0,0]
    num1=sum//averageRound
    num2=sum%averageRound
    # print(num1)
    tNum=num1 // 2
    # print(tNum)
    if num2==0:
        numList[averageRound-1]=num1
    else:
        if checkRonud==0:
            
            for i in range(tNum,divideNum,1): 
                if (averageRound)*i+(averageRound+1)*(divideNum-i)==sum:
                    # print(i)
                    numList[averageRound-1]=i
                    numList[averageRound]=divideNum-i
                    break                               
        else:
            for i in range(tNum,divideNum,1): 
                if (averageRound)*i+(averageRound-1)*(divideNum-i)==sum:
                    # print(i)
                    numList[averageRound-1]=i
                    numList[averageRound-2]=divideNum-i    
                    break                         
                    

    print('#testcase%d' %(int(t)+1))
    for i in numList:
        print(i,end=" ")
    print("")
    
    # array=[]
    # if int(t+1)>10:
    #     array[150]=0
        

inf.close()