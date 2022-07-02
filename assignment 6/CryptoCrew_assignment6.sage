from __future__ import print_function
import time
def Copper_smith_( mm, tt, upper_bd_root, N ,beta, degree_poly,mat_val,lattice_B,v, poly_Z,x):
    poly_initialise = 0

    for itr in range(mm):
        for in_itr in range(degree_poly):
            k=(upper_bd_root*x)**in_itr
            u= N**(mm - itr)
            w= poly_Z(x * upper_bd_root)**itr
            v.append(k * u * w)

    for itr in range(tt):
        k_ = (upper_bd_root*x)**itr
        w_ = poly_Z(upper_bd_root*x)**mm
        v.append(k_ * w_)
    # get B
    for itr in range(mat_val):
        for in_itr in range(itr+1):
            lattice_B[itr, in_itr] = v[itr][in_itr]

    lattice_B = lattice_B.LLL()

    for itr in range(mat_val):
        pow_ = x**itr
        y = pow_ * lattice_B[0,itr] / upper_bd_root**itr
        poly_initialise = poly_initialise +  y

    possible_root = poly_initialise.roots()
    roots = []
    for root in possible_root:
        if root[0].is_integer():
            ans = poly_Z(ZZ(root[0]))
            if N^beta <= gcd(ans,N) :
                roots.append(ZZ(root[0]))

    return roots


#Parameters

N = 84364443735725034864402554533826279174703893439763343343863260342756678609216895093779263028809246505955647572176682669445270008816481771701417554768871285020442403001649254405058303439906229201909599348669565697534331652019516409514800265887388539283381053937433496994442146419682027649079704982600857517093

e=5
ZmodN = Zmod(N)
padded_text = "CryptoCrew: This door has RSA encryption with exponent 5 and the password is"
#in hexadecimal
s=padded_text.encode('utf-8')
paddinghexa=s.hex()
#print(s.hex())
#paddinghexa= "43727970746F437265773A205468697320646F6F72206861732052534120656E6372797074696F6E2077697468206578706F6E656E74203520616E64207468652070617373776F7264206973"
# in decimal
padding_deci = int(paddinghexa, 16)
print(padding_deci)
#padding_deci = 279873063386806333571947098515958234285933577484710033693790627649376432394757062420991653579981043001400936289040503730042674610917874525365105021697922593687427470152474868509075827

C = 12277762659714600176188445390938647890016333128657855885501438481194805235227839614318320740163220152225783139223395637701737876364639838146963716201817861240632611254429171640637794190500740474476734856464863762891353901266790565359935230164973503369419635464859026214001863024610493857405398718632386227462

P.<x> = PolynomialRing(ZmodN)
# Copper_smith_
for j in range(0,128):
    #parameters

    beta = 1
    epsilon_ = beta / 20
    poly = (padding_deci*2^j + x)^e -C
    degree_poly = poly.degree()

    mm = ceil(beta**2 /(degree_poly*epsilon_))

    tt = floor(degree_poly * mm * ((1/beta) - 1))
    #upper bound on the root
    upper_bd_root = ceil(N**((beta**2/degree_poly) - epsilon_))
    mat_val = degree_poly * mm + tt
    poly_Z = poly.change_ring(ZZ)
    #lattice B
    lattice_B = Matrix(ZZ, mat_val)
    # vector
    v=[]
    x = poly_Z.parent().gen()
    roots = Copper_smith_(mm, tt, upper_bd_root, N, beta, degree_poly,mat_val,lattice_B,v, poly_Z,x)
    if(str(roots)):
        print("Running iteration",str(j))
        print(" Root obtained:", str(roots))

#num is the possible root found
num=39003064235393346230498905
print('Hexadecimal conversion of', num)
print(hex(num).replace("0x",""))
print('Hexadecimal to text gives:')
#using hexadeimal code found above to get the text
print(bytes.fromhex('2043385950376f4c6f3659').decode('utf-8'))
print('The password is:')
#removing hexadecimal part corresponding one space padded at the starting
print(bytes.fromhex('43385950376f4c6f3659').decode('utf-8'))