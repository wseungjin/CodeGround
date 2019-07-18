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

char_list = ["H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
             "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
             "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
             "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
             "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
             "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
             "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
             "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
             "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
             "No", "Lr"]

for i in range(0,len(char_list)):
    char_list[i]=char_list[i].lower()

char_list.sort()

# print(char_list)



def searchChe(sentence):
    flag=0
    leng=len(sentence)-1
    cur=leng-1;
    saveList=[]
    x=-1
  
        
    while cur>0:
        x=-1
        flag=0
        print(cur)
        for i in range(0,leng):
            if cur>1:            
                if sentence[cur-2:cur]==char_list[i]:
                    print("2 "+sentence[cur-2:cur])
                    flag=2
                    
        if flag!=2 and :
            for i in range(0,leng):
                if sentence[cur-1:cur]==char_list[i]:
                    print("1 "+sentence[cur-1:cur])
                    flag=1
        if x==-1:
            x=cur
            cur=cur-1
        else:
            if flag==2:
                cur=cur-2
            elif flag==1:
                cur=cur-1
            elif flag==0:
                break
    
    
    if flag ==0:
        return 1
    else:
        return 0

    # print(saveList)
    
    

inf = open('input.txt');
# inf = sys.stdin 

T = inf.readline();
# print(T)



for t in range(0, int(T)):
    
    Answer=0;
    sentence = inf.readline();
    
    # print(sentence)
    Answer=searchChe(sentence)
	
	
	# Print the answer to standard output(screen).
    print('Case #%d' %(int(t)+1))    
    if Answer==0:
        print("YES")
    else:
        print("NO")
inf.close()