import urllib.request

import requests

def choose_variant(variants):
    num_results = []
    for i in variants:

        url = 'https://ca.search.yahoo.com/search?p="' + urllib.parse.quote(i) + '"'
        headers = {
            'User-Agent': 'MyPythonApp/1.0',
            'Accept-Language': 'en-US,en;q=0.9',
            'Authorization': 'Bearer YOUR_AUTH_TOKEN'
        }

        response = requests.get(url, headers=headers)
        page = response.text


        list = page.split()


        for i in range(len(list)):
            if list[i] == 'class="fz-14 lh-22">About':
                num_results.append(int(list[i+1].replace(',','')))
                break

    i = 0
    max = 0
    for j in range(len(num_results)):
        if num_results[j] > max:
            max = num_results[j]
            i = j

    return variants[i]

print(choose_variant(["top ranked school uoft", "top ranked school waterloo"]))


