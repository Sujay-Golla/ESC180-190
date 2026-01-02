temp = ""
list = []
while temp != "END":
    temp = input("Enter a name: ")
    if temp != "END":
        list.append(temp)

print("The names are: ", end="")
if len(list) != 0:
    for i in range(0,len(list)-1):
        print(list[i] + ",", end=" ")
    print(list[len(list)-1], end=" ")
else:
    print("", end="")