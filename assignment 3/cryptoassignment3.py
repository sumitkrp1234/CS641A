def binexp(a,b,mod):
    #binary exponentitation to calculate power
    if(b==0):
        return 1
    val=binexp(a,b//2,mod)%mod
    val=(val*val)%mod
    if(b%2):
        return ((a*val)%mod)
    else:
        return val


# prime number p
mod=455470209427676832372575348833            

# 3 pairs given 
y1=431955503618234519808008749742                  
y2=176325509039323911968355873643
y3= 98486971404861992487294722613
a1=429
a2=1973
a3=7596

y1_inv=binexp(y1,mod-2,mod)      # calculating modoulo Inverse using binary exponentiation
print("y1_inv =",y1_inv)
y2_inv=binexp(y2,mod-2,mod)      # calculating modoulo Inverse using binary exponentiation
print("y2_inv =",y2_inv)

A=(y2*y1_inv)%mod
print("A = ",A)
A_inv=binexp(A,mod-2,mod)        # calculating modoulo Inverse using binary exponentiation
B=(y3*y2_inv)%mod
print("B = ",B)

U=binexp(A_inv,2298,mod)
V=binexp(B,631,mod)
g=(U*V)%mod
print("g = ",g)

g1=binexp(g,429,mod)            # g raise to power a1 
g1_inv=binexp(g1,mod-2,mod)     # calculating modoulo Inverse using binary exponentiation
print("g1_inv = ",g1_inv)
pass1= (y1*g1_inv)%mod
g2=binexp(g,1973,mod)           # g raise to power a2
g2_inv=binexp(g2,mod-2,mod)     # calculating modoulo Inverse using binary exponentiation
print("g2_inv = ",g2_inv)
pass2= (y2*g2_inv)%mod
g3=binexp(g,7596,mod)           # g raise to power a3
g3_inv=binexp(g3,mod-2,mod)     # calculating modoulo Inverse using binary exponentiation
print("g3_inv = ",g3_inv)
pass3= (y3*g3_inv)%mod          
print("Passwords from 3 pairs are respectively : ",pass1, pass2, pass3)