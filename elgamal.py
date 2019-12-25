import random

def inverse(e,p):
    for i in range(0,e):
        if((e*i)%p==1):
          break
    return i


def keyGenerate(p):
    d=random.choice(list(range(1,p-1)))
    e1=random.choice(list(range(1,p-1)))
    e2=(e1**d)%p
    return d,e1,e2
 
def encrypt(e1,e2,p,m):
    r=random.choice(list(range(1,p-1)))
    c1=(e1**r)%p
    c2=m*((e2**r) %p)
    return c1,c2
 
def decrypt(c1,c2,d,p):
    m=((c2%p)*inverse(c1**d,p)) % p
    return m

p=int(input("Enter a large prime number P: "))
#key generation process...public key is e1,e2,p   ..private key is d
d,e1,e2=keyGenerate(p)
m=int(input("Enter the plain text:  "))

print("\nPlain Text is :",m)
#encryption
c1,c2=encrypt(e1,e2,p,m)
print("\nEncrypted message are: ",c1," and ",c2)

#decryption
m=decrypt(c1,c2,d,p)
print("\nDecrypted Message is :",m)