import random

x=12345
y=23423

def alice(n,g):
    global x
    print("Taking  a large prime number for alice\n")
    x=random.randint(10**4,10**6)
    A=(g**x)%n
    return(A)
	

def bob(n,g):
    global y
    print("Taking a large prime number for bob\n")
    y=random.randint(10**4,10**6)
    B=(g**y)%n
    return(B)
	
	

print(".........Program for Key Exchange Protocol using Deffie Helman ............\n")
print("Choose the value of n ang g as a large prime number\n")
n=int(input("Enter the value of n as a large prime number\n"))
g=int(input("Enter the value of g\n"))

A=alice(n,g)
B=bob(n,g)

alice_key=(B**x) % n
bob_key=(A**y) % n


print("\nAlice key is :",alice_key)
print("\nBOB key is : ",bob_key)

if(alice_key==bob_key):
    print("\ncommon key is :",alice_key);	


