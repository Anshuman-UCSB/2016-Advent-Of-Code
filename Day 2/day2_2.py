with open("day2.txt") as file:
    data = file.read().splitlines()

grid = [[0,0,0,0,0,0,0]
       ,[0,0,0,1,0,0,0]
       ,[0,0,2,3,4,0,0]
       ,[0,5,6,7,8,9,0]
       ,[0,0,"A","B","C",0,0]
       ,[0,0,0,"D",0,0,0]
       ,[0,0,0,0,0,0,0]]

password = []
loc = [1,3]

def getVal(loc):
    return grid[loc[1]][loc[0]]

def move(loc, move):
    temp = loc.copy()
    if move == "U":
        temp[1]-=1
        if getVal(temp) != 0:
            loc = temp
    if move == "D":
        temp[1]+=1
        if getVal(temp) != 0:
            loc = temp
    if move == "R":
        temp[0]+=1
        if getVal(temp) != 0:
            loc = temp
    if move == "L":
        temp[0]-=1
        if getVal(temp) != 0:
            loc = temp
    #print("returning",loc)

    return loc


for instr in data:
    for char in instr:
        loc = move(loc, char)

    print(getVal(loc))
    password.append(getVal(loc))
print(password)
for val in password:
    print(val,end="")
print()
