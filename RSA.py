message=encrypted_message=decrypted_message=[]
n=phi=e=p=q=d=0

def gcd(a,b):
    if (b == 0):
        return a 
    return gcd(b, a % b)  


def decideE():
    global phi
    for i in range(2,phi):
      gcdd=gcd(phi,i)
      if(gcdd==1):
         break
      else:
         continue

    return i	


def inverse():
    global phi,e
    for i in range(0,phi):
        
       if((e*i)%phi==1):
          break
    return i%phi 	


def encrypt_message(length):
    global e,n
    for i in range(0,length):
       encrypted_message[i]=(message[i]**e) % n

	 
    for i in range(0,length):
       print(" ",encrypted_message[i])
	 	 


def decrypt_message(length):
    global d,n
    for i in range(0,length):
       decrypted_message[i]=(encrypted_message[i]**d) % n
	 
    for i in range(0,length):
       print(" ",decrypted_message[i])
	 	 








print("............................Program for RSA cryptosystem..........................\n")
print("Enter Two large prime numbers P and Q \n")
p=int(input("Enter the value of P\n"))
q=int(input("Enter the value of Q\n"))


#calculating n=p*q
n=p*q
#calculating phi(n)=(p-1) * (q-1)
phi=(p-1)*(q-1)

#calculating the public key  e
e=decideE()

#computing private key d
d=inverse()

print(" value of e:  \n",e)
print("value of d is:\n",d)

length=int(input("Enter the length ogf array\n"))

print("Enter the numeric message array\n")

for i in range(0,length):
  message.append(int(input()))


encrypt_message(length)
print("\n")
decrypt_message(length)


