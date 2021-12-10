#!/usr/bin/python3
""" 0-count """
import requests
import sys


def count_words(subreddit, word_list, after="", word_dict={}):
    """ Parses reddit """
    url = "https://reddit.com/r/" + subreddit + "/hot.json"

    if after:
        url = url + "?&after=" + after

    data = requests.get(url, headers={'User-agent': 'product'}, allow_redirects=False)

    if 'error' in data:
        return None

    if word_dict == {}:
        for word in word_list:
            word_dict[word] = word_list.count(word)

    for post in data.json().get('data').get('after').get('children'):
        title = post['data']['title'].split()
        for index in title:
            for kindex in word_dict:
                if index.upper() == kindex.upper():
                    word_dict[kindex] += 1

    after = data['data']['after']

    if after:
        count_words(subreddit, word_list, after="", word_dict={})
    else:
        sorted_list = sorted(word_list)
        for key, value in word_dict.items():
            if value > 0 and key in sorted_list:
                print('{}: {}'.format(key, value))
