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
flag=0

for t in range(1,int(T)+1):
    flag=0
    for k in range(0,int(len(str(t)))):
        if str(t)[k]=="3" or str(t)[k]=="6" or str(t)[k]=="9":
            flag=1
            print("-",end="")
    if flag==0:
        print(str(t),end="")
    print(" ",end="")
    