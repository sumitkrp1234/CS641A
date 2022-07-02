import numpy as np

def modInverse(num, m):     
    for x in range(1, m):
        if (((num%m)*(x%m))%m == 1):
            return x
    return -1
 
p = [24, 84, 39, 70, 43, 111, 9, 20, 94, 93, 13, 95, 118, 31 ,125, 124, 5 ,1 ,52, 124, 90, 54 ,67, 79, 14, 88, 35, 13, 32, 35, 39, 59]
e = []
#print(p[0])
e.append(1)
#e.append(2)
#print(e[1])

for i in range (1,25):
  sum=0
  for j in range (1,i+1):
    sum = sum + pow(-1,j-1)* e[i-j] * p[j]
  sum = sum * modInverse(i,127)
  sum%=127
  e.append((sum))

print("e vector is",e)

# writing coefficients of poly(x)
poly= [1, -84, 16, -99, 112, -49, 32, -82, 6, -124, 109, -61, 23, -96, 113, -46, 34, -7, 122, -89, 103, -83, 51, -124, 80]

roots= []
cnt=0
# checking the roots
for k in range(127):
  x = k
  n = len(poly)
  ans = 0
  for i in range(n):
    add = poly[i]
    for j in range(n-i-1):
        add *= x
    ans +=add  
  print(k ,ans%127)
  if ans%127 ==0 :
    cnt+=1
    roots.append(k)

print("Roots of poly(x) over the given field: ", roots)
print ("Number of roots we get here:",cnt)


roots_first_der=[]
# writing coefficients of first derivative of poly(x)
poly_first_der = [0,24,-84*23,16*22,-99*21,112*20,-49*19,32*18,-82*17,6*16,-124*15,109*14,-61*13,23*12,-96*11,113*10,-46*9,34*8,-49,122*6,-89*5,103*4,-83*3,102,-124]
cnt=0
# checking the roots
for k in range(127):
  x = k
  n = len(poly_first_der)
  ans = 0
  for i in range(n):
    add = poly_first_der[i]
    for j in range(n-i-1):
        add *= x
    ans +=add  
  print(k ,ans%127)
  if ans%127 ==0 :
    cnt+=1
    roots_first_der.append(k)
print("Roots of first derivative of poly(x) over the given field: ", roots_first_der)
print ("Number of repeated roots we get from first derivative  :",cnt)


# writing coefficients of second derivative of poly(x)
poly_second_der = [0,0,24*23,-84*23*22,16*22*21,-99*21*20,112*20*19,-49*19*18,32*18*17,-82*17*16,6*16*15,-124*15*14,109*14*13,-61*13*12,23*12*11,-96*11*10,113*10*9,-46*9*8,34*8*7,-49*6,122*6*5,-89*5*4,103*4*3,-83*3*2,102*1]
cnt=0
roots_second_der=[]
# checking the roots
for k in range(127):
  x = k
  n = len(poly_second_der)
  ans = 0
  for i in range(n):
    add = poly_second_der[i]
    for j in range(n-i-1):
        add *= x
    ans +=add  
  print(k ,ans%127)
  if ans%127 ==0 :
    cnt+=1
    roots_second_der.append(k)
print("Roots of second derivative of poly(x) over the given field: ", roots_second_der)
print ("Number of repeated roots we get from second derivative  :",cnt)


