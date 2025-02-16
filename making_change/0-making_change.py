#!/usr/bin/python3
"""Determine the fewest number of coins
needed to meet a given amount total."""


def makeChange(coins, total):
    """Determine the fewest number of coins
    needed to meet a given amount total."""
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    num_coins = 0
    remaining = total

    for coin in coins:
        if remaining == 0:
            break
        count = remaining // coin
        num_coins += count
        remaining -= count * coin

    return num_coins if remaining == 0 else -1
