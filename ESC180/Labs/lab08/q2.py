def luckiest_kid(halloween_haul):
    count = []
    kids = []

    houses = list(halloween_haul.keys())
    num = len(list(halloween_haul[houses[0]].keys()))

    for i in range(num):
        count.append(0)
        kids.append("")

    for values in halloween_haul.values():
        i = 0
        for key, vals in values.items():
            count[i] += len(vals)
            kids[i] = key
            i += 1

    luckiest = ""
    max = -1
    for i in range(len(count)):
        if count[i] > max:
            luckiest = kids[i]
            max = count[i]

    return luckiest



halloween_haul = {
                    "house1": {
                    "Annie": ["snickers", "mars"],
                    "Johnny": ["snickers"]
                    },
                    "house2": {
                    "Annie": ["coffee crisp", "mars"],
                    "Jackie": ["coffee crisp"]
                    }
                }

print(luckiest_kid(halloween_haul))