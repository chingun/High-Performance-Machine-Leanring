import time
import numpy as np
import sys


N = 1000000
R = 1000

A = np.ones(N,dtype=np.float32)
B = np.ones(N,dtype=np.float32)
t_start = 0
t_end = 0
t = 0

def dp(N, A, B):
    R = 0.0;
    for j in range(0,N):
        R += A[j]*B[j]
    return R

for i in range(0, (int)(R/2)):
    np.dot(A, B)

t_start=time.monotonic()
for i in range(0, (int)(R/2)):
    np.dot(A, B)
t_end=time.monotonic()

t = (t_end - t_start) * 1.0 / (R / 2.0)
flops = (2 * N) / (t * 1000000000.0)
bandwidth = (2 * N * sys.getsizeof(float)) / (t * 1000000000.0)
print("N: ", N, " T: ", t , " sec B: " , bandwidth, " GB/sec F: ", flops, " GFLOPS/sec \n")