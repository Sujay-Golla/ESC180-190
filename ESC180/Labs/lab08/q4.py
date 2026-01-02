def make_schools(file_name):
    lines = []
    try:
        with open(file_name, 'r') as file:
            for line in file:
                lines.append(line.strip())
    except FileNotFoundError:
        print(f"Error: The file '{file_name}' was not found.")
    except Exception as e:
        print(f"An error occurred: {e}")


    with open(file_name, 'r') as file:
        lines = file.readlines()
        for line in lines:
            lines.append(line.strip())

    schools = {}
    isName = False

    for i in range(len(lines)):
        if lines[i].isupper():
            isName = True
        elif isName and lines[i] != "\n":
            school = lines[i]
            if school in schools.keys():
                schools[school] += 1
            else:
                schools[school] = 1
        elif lines[i] == "\n":
            isName = False

    return topschools(schools)



def topschools(schools):
    L = schools.items()
    new_L = []
    for i in L:
        j = list(i)
        j[0], j[1] = j[1], j[0]
        k = tuple(j)
        new_L.append(k)

    return sorted(new_L)


print(make_schools("results.txt")[0])