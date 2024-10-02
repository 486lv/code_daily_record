import numpy as np
import matplotlib.pyplot as plt
from tqdm import tqdm

def prime_list(num):
    prime = []
    st = [False] * (num+1)
    for i in range(2, num):
        if not st[i]:prime.append(i)
        for j in prime:
            if i*j>num: break
            st[i*j] = True
            if i%j==0: break
    return prime

def is_prime_list(n):
    st=[0]*(n+1)
    num=prime_list(n)
    for i in num:
        st[i]=1
    return st

def generate_square(n):
    x, y = 0, 0
    direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    spiral = [(x, y)]
    step_length = 1
    dir_index = 0
    matrix =[]
    matrix.append([0,0])
    cnt=0
    for num in range(1, n+1):
        for _ in range(step_length):
            cnt+=1
            if cnt==n:
                return matrix
            x += direction[dir_index][0]
            y += direction[dir_index][1]
            matrix.append([x,y])
        dir_index = (dir_index + 1) % 4
        if dir_index % 2 == 0:
            step_length += 1
    return matrix

while(1):
    n=int(input("请输入一个数,小于0结束："))
    if(n<=0): break
    st=is_prime_list(n)
    square=generate_square(n)
    plt.figure(figsize=(8, 8))
    plt.axis('equal')


    for i, (x, y) in tqdm(enumerate(square), total=len(square)):
        if st[i] == 1:
            plt.plot(x, y, 'ks',markersize=2)
        else:
            plt.plot(x, y, '')

    plt.autoscale()
    plt.show()
