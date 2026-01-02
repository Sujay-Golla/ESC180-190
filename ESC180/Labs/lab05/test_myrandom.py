import myrandom as m

if __name__ == "__main__":
    counter = 1
    first = m.myrandom()
    for i in range(10000):
        temp = m.myrandom()
        if temp != first:
            counter += 1
        else:
            break
    if counter > 10000:
        print(-1)
    else:
        print(counter)
