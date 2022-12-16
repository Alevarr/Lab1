import matplotlib.pyplot as plt

f = open("graph.txt", "r");

info = f.readline().replace('\n', "").split(' ')
print(info)

maxRange = int(info[1])
minRange = int(info[0])
print(minRange, maxRange)
step = int(info[2])
lengthsArray = []
c = minRange
ba = []
while(c <= maxRange):
    lengthsArray.append(c)
    c += step

for i in range(10, 15):
    ba.append(2**i)
print(lengthsArray)
bubble = list(map(float, f.readline().replace(' \n', "").split(' ')))
shell = list(map(float, f.readline().replace(' \n', "").split(' ')))
print(bubble, shell)
bitonic = f.readline().replace(' \n', "").split(' ')

# plt.plot(lengthsArray, bubble, label = "Bubble sort")
plt.plot(lengthsArray, shell, label = "Shell sort")
plt.plot(ba, bitonic, label = "Bitnoc sort")

plt.xlabel("Sequence length")
plt.ylabel("Sorting time")
plt.title("Sorting algorythm complexity.")

plt.legend()
plt.show()