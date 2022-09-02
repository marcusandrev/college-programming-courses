var x = 1
var y = 10

print(x < y)
print(x > y)
print(x <= y)
print(x >= y)
print(x == y)
print(x != y)

for value in x ..< y {
	print(value, " <-- Half-closed range operator")
}

for value in x ... y {
	print(value, " <-- Closed range operator")
}
