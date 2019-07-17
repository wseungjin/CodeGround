# '''
# You should use the standard input/output

# in order to receive a score properly.

# Do not use file input and output

# Please be very careful. 
# '''



# '''
# 	The method below means that the program will read from input.txt, instead of standard(keyboard) input.
# 	To test your program, you may save input data in input.txt file,
# 	and call below method to read from the file when using open() method.
# 	You may remove the comment symbols(#) in the below statement and use it.
# 	But before submission, you must remove the open function or rewrite comment symbols(#).
# '''

# #inf = open('input.txt');


T = input()
profit=0
max=0
curLoF=0
curLoL=0
for t in range(0,int(T)):
	line1=input()
	line2=input()
	profit=0
	max=0
	curLoF=0
	curLoL=0
	numList=line2.split(" ")

	while curLoF!=int(line1):
		max=int(numList[curLoF])
		for k in range(curLoF,int(line1)):
			if int(numList[k])>=max:
				max=int(numList[k])
				curLoL=k
		for j in range(curLoF,curLoL):
			profit=profit+max-int(numList[j])
			curLoF=j
		curLoF=curLoF+1
	
	print("#%d "%int(t+1)+str(profit))
