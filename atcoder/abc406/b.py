n, k = input().split(' ')
v = input().split(' ')

x = 1
for i in range(int(n)):
    x  = x * int(v[i])
    aux = str(x)
    if (len(aux) > int(k)):
        x = 1

print(x)