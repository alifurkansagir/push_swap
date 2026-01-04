#!/usr/bin/env python3
import sys
from collections import deque

if len(sys.argv) < 2:
    print("Usage: check_moves.py <initial stack a values...>")
    sys.exit(1)

# initial stack a from argv
init_a = [int(x) for x in sys.argv[1:]]
A = deque(init_a)
B = deque()

moves = [line.strip() for line in sys.stdin if line.strip()]

for m in moves:
    if m == 'sa':
        if len(A) >= 2:
            A[0], A[1] = A[1], A[0]
    elif m == 'sb':
        if len(B) >= 2:
            B[0], B[1] = B[1], B[0]
    elif m == 'ss':
        if len(A) >= 2:
            A[0], A[1] = A[1], A[0]
        if len(B) >= 2:
            B[0], B[1] = B[1], B[0]
    elif m == 'pa':
        if B:
            A.appendleft(B.popleft())
    elif m == 'pb':
        if A:
            B.appendleft(A.popleft())
    elif m == 'ra':
        if A:
            A.append(A.popleft())
    elif m == 'rb':
        if B:
            B.append(B.popleft())
    elif m == 'rr':
        if A:
            A.append(A.popleft())
        if B:
            B.append(B.popleft())
    elif m == 'rra':
        if A:
            A.appendleft(A.pop())
    elif m == 'rrb':
        if B:
            B.appendleft(B.pop())
    elif m == 'rrr':
        if A:
            A.appendleft(A.pop())
        if B:
            B.appendleft(B.pop())
    else:
        # ignore unknown lines
        pass

# print result
final_a = list(A)
print('Final A:', ' '.join(str(x) for x in final_a))

is_sorted = all(final_a[i] <= final_a[i+1] for i in range(len(final_a)-1))
print('SORTED' if is_sorted else 'NOT SORTED')
