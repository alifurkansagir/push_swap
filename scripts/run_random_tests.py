#!/usr/bin/env python3
import random
import subprocess
import statistics

TRIALS = 10
N = 500
results = []

for t in range(1, TRIALS+1):
    nums = random.sample(range(1, 10000), N)
    args = [str(n) for n in nums]
    proc = subprocess.run(['./push_swap'] + args, capture_output=True, text=True)
    moves = [line for line in proc.stdout.splitlines() if line.strip()]
    move_count = len(moves)
    check = subprocess.run(['./scripts/check_moves.py'] + args, input=proc.stdout, text=True, capture_output=True)
    sorted_ok = 'SORTED' in check.stdout
    results.append((move_count, sorted_ok))
    print(f'Run {t}: moves={move_count}, sorted={sorted_ok}')

counts = [r[0] for r in results]
print('\nSummary:')
print(f'  min: {min(counts)}')
print(f'  max: {max(counts)}')
print(f'  avg: {statistics.mean(counts):.2f}')
print(f'  median: {statistics.median(counts)}')
