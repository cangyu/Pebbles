import matplotlib.pyplot as plt

data=open("test.txt")

t=[]
v=[]
s=[]

for line in data:
    (_t, _v, _s)=line.split()
    t.append(float(_t))
    v.append(float(_v))
    s.append(float(_s))

data.close()

p1=plt.subplot(211)
p1.plot(t, s, label="position")

p2=plt.subplot(212)
p2.plot(t, v, label="speed")

plt.show()
