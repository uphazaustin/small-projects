"""
Program reenacts a simple game of rock, papers and scissors
Best to three
"""
import random

moves = ["r", "p", "s"]

user_wins = 0
while True:
    playing = input("Do you want to play a game of Rock, Papers and Scissors?(yes/no)\n")
    if playing.strip().lower() == "no":
        quit()
    if playing.strip().lower() == "yes":
        print("Let's Play!")
        break
    else:
        print("Invalid Response!")

games = 0
while games < 3:
    user = input("r for rock, p for paper and s for scissor. Best of three\n")
    comp = random.choice(moves)
    if user.strip().lower() == comp:
        print("Tie")
        continue
    if user.strip().lower() == "r" and comp == "s":
        print("Rock beats scissors! You won this round.\n")
        user_wins += 1
        games += 1
        continue
    if user.strip().lower() == "r" and comp == "p":
        print("Paper beats Rock! You lost this round.\n")
        games += 1
        continue
    if user.strip().lower() == "p" and comp == "s":
        print("Scissors beat paper! You lost this round.\n")
        games += 1
        continue
    if user.strip().lower() == "p" and comp == "r":
        print("Paper beats Rock! You won this round.\n")
        games += 1
        user_wins += 1
        continue
    if user.strip().lower() == "s" and comp == "p":
        print("Scissors beat paper! You won this round.\n")
        games += 1
        user_wins += 1
        continue
    if user.strip().lower() == "s" and comp == "r":
        print("Rock beats scissors! You lost this round.\n")
        games += 1
        continue
    else:
        print("Invalid move\n")
        print("r for rock, p for paper and s for scissor. Best of three\n")

if user_wins >= 2:
    print(f"You won the best of three with {user_wins} wins!")
else:
    print("You lost!")

