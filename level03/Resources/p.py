s1 = "Q}|u`sfg~sf{}|a3"
s2 = "Congratulations!"
init = 322424845

for i in range(20):
    if ord(s2[1]) == ord(s1[1]) ^ i:
        break
    i = i + 1
print(i)
result = ""
for c1, c2 in zip(s1, s2):
    result += chr(ord(c1) ^ i)
print result
print init - i