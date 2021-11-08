r = int(input("\n Enter No of buys:"))
price = []
q = []
sum = 0
sumq = 0
for x in range(r):
    price.append(input("\n Enter Price:"))
    q.append(input("\n Enter Quantity:"))
    sum += float(price[x])*float(q[x])
    sumq += float(q[x])
print("\n Average price:", sum/sumq)
print("\n Quantity:", sumq)
print("\n Total Cost:", sum)