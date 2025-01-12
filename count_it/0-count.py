#!/usr/bin/python3
import requests


def count_words(subreddit, word_list, after='', word_counts=None):

    if word_counts is None:
        word_counts = {}

    normalized_words = [word.lower() for word in word_list]

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'python:word.count:v1.0 (by /u/yourusername)'}
    params = {'limit': 100, 'after': after}

    response = requests.get(url, headers=headers, params=params)

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    posts = data.get('children', [])
    after = data.get('after')

    for post in posts:
        title = post['data'].get('title', '').lower()
        for word in normalized_words:
            word_counts[word] = word_counts.get(word, 0)
            + title.split().count(word)

    if after is not None:
        count_words(subreddit, word_list, after, word_counts)
    else:
        sorted_counts = sorted(
            word_counts.items(),
            key=lambda x: (-x[1], x[0])
        )
        for word, count in sorted_counts:
            if count > 0:
                print(f"{word}: {count}")
