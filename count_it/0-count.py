#!/usr/bin/python3
import requests

def count_words(subreddit, word_list, after='', word_counts=None):
    """
    Recursively counts occurrences of keywords in the titles of hot articles
    from a given subreddit.

    Args:
        subreddit (str): The name of the subreddit.
        word_list (list): A list of keywords to count (case-insensitive).
        after (str): The "after" parameter for pagination in the Reddit API.
        word_counts (dict): A dictionary to store counts of words.

    Returns:
        None
    """
    if word_counts is None:
        word_counts = {}

    # Normalize word_list to lowercase
    normalized_words = [word.lower() for word in word_list]

    # Define the Reddit API URL
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'python:word.count:v1.0 (by /u/yourusername)'}
    params = {'limit': 100, 'after': after}

    # Make the request to the Reddit API
    response = requests.get(url, headers=headers, params=params)

    # Check if the subreddit is valid
    if response.status_code != 200:
        return

    # Parse the response JSON
    data = response.json().get('data', {})
    posts = data.get('children', [])
    after = data.get('after')

    # Process the titles of the posts
    for post in posts:
        title = post['data'].get('title', '').lower()
        for word in normalized_words:
            # Count exact matches for the word
            word_counts[word] = word_counts.get(word, 0) + title.split().count(word)

    # If there's more data to process, recursively call the function
    if after is not None:
        count_words(subreddit, word_list, after, word_counts)
    else:
        # Sort and print the results
        sorted_counts = sorted(
            word_counts.items(),
            key=lambda x: (-x[1], x[0])  # Sort by count (desc), then alphabetically
        )
        for word, count in sorted_counts:
            if count > 0:
                print(f"{word}: {count}")
