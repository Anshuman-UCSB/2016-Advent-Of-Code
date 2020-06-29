coord = [0,0]
dir = 0
dirs = [0,1,2,3]
"    up, right, left, down"

with open("day1.txt") as file:
    data = file.read().split(", ")
data[-1] = data[-1][:-1]
# cut last \n off data
visited = []

for instr in data:
    if instr[0] == "L":
        dir -= 1
    else:
        dir += 1
    if dir == -1:
        dir = 3
    if dir == 4:
        dir = 0

    if dir in [0,1]:

        for i in range(int(instr[1:])):
            coord[dir%2]+= 1
            temp = coord.copy()
            if temp in visited:
                print(temp)
            else:
                visited.append(temp)
    else:
        for i in range(int(instr[1:])):
            coord[dir%2]-= 1
            temp = coord.copy()
            if temp in visited:
                print(temp)
            else:
                visited.append(temp)

sum = 0
for val in coord:
    sum+=abs(val)

print(sum)
