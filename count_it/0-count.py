#!/usr/bin/python3
import requests


def count_words(subreddit, word_list, after = None,  sum_dict=None):

    if sum_dict is None:
        sum_dict = {}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "python:word.count:v1.0 (by /u/yourusername)"}
    params = {"after": after, "limit": 100} if after else {"limit": 100}
    response = requests.get(url, headers=headers, params=params)

    if response.status_code != 200:
        return

    data = response.json()
    posts = data["data"]["children"]
    after = data["data"]["after"]
    for found in posts:
        list1 = found["data"]["title"].lower()
        list1 = list1.split()
        for i in word_list:
            i = i.lower()
            sum_dict[i] = sum_dict.get(i, 0) + list1.count(i)

    if after is None or not posts:
        myKeys = list(sum_dict.keys())
        myKeys.sort()
        print(myKeys)
        sd = {i: sum_dict[i] for i in myKeys}
        sorted_items = sorted(sd.items(), key=lambda x: (-x[1], x[0]))

        for word, count in sorted_items:
            if count > 0:
                print(f"{word}: {count}")
        return
    
    print(sum_dict)
    count_words(subreddit, word_list, after, sum_dict)
