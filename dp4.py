N = 1000
A = np.ones(N,dtype=np.float32)
B = np.ones(N,dtype=np.float32)

def dp(N, A, B):
    R = 0.0;
    for j in range(0,N):
        R += A[j]*B[j]
    return R

for i in range(0, 10):
    dp(N, A, B)

