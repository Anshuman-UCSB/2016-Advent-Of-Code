with open("day2.txt") as file:
    data = file.read().splitlines()

grid = [[1,2,3]
       ,[4,5,6]
       ,[7,8,9]]

password = []
loc = [1,1]

def getVal(loc):
    return grid[loc[1]][loc[0]]

def move(loc, move):
    if move == "U":
        loc[1] = max(0, loc[1]-1)

    if move == "D":
        loc[1] = min(2, loc[1]+1)

    if move == "R":
        loc[0] = min(2, loc[0]+1)

    if move == "L":
        loc[0] = max(0, loc[0]-1)

for instr in data:
    for char in instr:
        move(loc, char)
        print(loc)
    password.append(getVal(loc))
print(password)
