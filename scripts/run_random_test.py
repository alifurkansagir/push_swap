#!/usr/bin/env python3
import random
import subprocess
import sys

# generate 500 unique integers
nums = random.sample(range(1, 10000), 500)
args = [str(n) for n in nums]

# run push_swap
proc = subprocess.run(['./push_swap'] + args, capture_output=True, text=True)
moves_output = proc.stdout
moves = [line for line in moves_output.splitlines() if line.strip()]
move_count = len(moves)

# verify with checker
check = subprocess.run(['./scripts/check_moves.py'] + args, input=moves_output, text=True, capture_output=True)
check_out = check.stdout.strip()

print(f'Move count: {move_count}')
print(check_out)
