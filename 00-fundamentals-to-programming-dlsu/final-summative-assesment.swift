// 1    

let names = ["Pilot": "Wash", "Doctor": "Simon"]
let doctor = names["doctor"] ?? "Bones"

print(doctor)


// i. "Bones"
// Explanation: 
// The "doctor" element is not set in the names dictionary. This will cause it to return nil. Because a nil coalescing operator is present, it will return the value on the right which is "Bones".



// 2

func sum(numbers: Int...) -> Int {
    var result = 0

    for number in numbers {
        result += number
    }

    return result
}

let result = sum(numbers: [1, 2, 3, 4, 5])


// d. The Code will not compile

//Explanation:
//The code will not compile because the inputted number in the sum() function is an array. The sum () function takes an Intenger parameter and not an array. This can be solved with the code "let result = sum(numbers: 1, 2, 3, 4, 5)".


// 3   

func greet(names: String...) {
  print ("Criminal masterminds:", names.joined(separator: ",")) }

greet(names: "Malcolm", "Kaylee", "Zoe")


// E. "Criminal masterminds: Malcolm, Kaylee, Zoe" 
// Explanation:
// The greet() method accepts and takes the array given (names: "Malcolm", "Kaylee", "Zoe"). The array then joins using commas to the string written before ("Criminal masterminds:"). Thus printing out "Criminal masterminds: Malcolm, Kaylee, Zoe".


// 4     

let names = ["Simon", "River", "Book"]
 names.forEach { print($1)
} 

// A. The code will not compile
// Explanation: 
// Functions like "forEach" take closure as an argument. Similarly, these closures also have arguments, and the default for the "forEach" function is $0. The code uses $1 which will cause it to not compile. Using $0 will make the code compile as this is the first parameter.


// 5    

var foo: Float = 32
var bar: Double = 32

// B. Neither variable can be assigned to the other
// Explanation: 
// Swift is a type-safe language. It means that you cannot assign either variable to the other without type casting. 


// 7    

//Given
let bigNumber = Int.max
let biggerNumber = bigNumber + 1 print(biggerNumber)


// Based on the given, "print(biggerNumber)"" should be separated on the second line, or by ';'. 

let bigNumber = Int.max
let biggerNumber = bigNumber + 1
print(biggerNumber)

// E. This code will compile but crash 
//Explanation:
//Aside from the "print(biggerNumber)" to be separated from the second line, when it is already put in the proper places, the code will compile but crash. In Swift, if you add 1 to the largest possible integer, it will cause an integer overflow. 
//Additionally, if you're using a signed integer type in some architectures or languages, you'll end up with the minimum value which is  basically just binary counting.


//8   

let possibleNumber = "1701"
let convertedNumber = Int(possibleNumber)

print(convertedNumber)


//D. Int?
//Explanation:
// The question mark in Swift means optional which lets you indicate the possibility that a value might be absent for any type at all, without the need for special constants. In the code, converting a string to an integer - with using  only the code above - will result to an optional integer which will give you either a number (on success) or nil (on failure.) 


//In order to force a value (without the question mark), you should use nil coalescing. This will result to an Int value

let possibleNumber = "1701"
let convertedNumber = Int(possibleNumber) ?? 0

print(convertedNumber)



//9

//Given
var crew = ["Captain": "Malcolm", "Doctor": "Simon"] crew =
[:]
print(crew.count 

      
//Based on the given, "crew =" should be together with the "[:]". Also, there should be a close parenthesis in the end of "print(crew.count "

var crew = ["Captain": "Malcolm", "Doctor": "Simon"]
crew = [:]
print(crew.count)


//C. 0 
//Explanation
//To create a dictionary with no key-value pairs, we use the empty dictionary literal "[:]". This will caused the crew dictionary to be wiped thus resulting to 0.


//10

let number = 5
switch number { case 0..<5:
print("First group") case 5...10:
print("Second group") case 0...5:
print("Third group") default:
print("Fourth group") } 


//E. "Second group"
//Explanation:
//Second group is returned because it is the first case block that matches with the given/switch value. Despite the overlapping with the third case block, the second case block matched first so it is the one which got returned.


//11

// Given
let point = (556, 0) switch point {
case (let x, 0):
print("X was \(x)") case (0, let y):
print("Y was \(y)") case let (x, y):
print("X was \(x) and Y was \(y)") } 


//Based on the given, "switch point {" should be separated from the first line or be separated by ';'.

let point = (556, 0) 
switch point {
case (let x, 0):
 print("X was \(x)") case (0, let y):
 print("Y was \(y)") case let (x, y):
 print("X was \(x) and Y was \(y)") }

//B. X was 556 
//Explanation
//The first case block was executed because it matches the given/switch value.


//12
 
//Given
var names = [String]() names.reserveCapacity(2)
names.append("Amy") names.append("Rory") names.append("Clara")


//Based on the given, all the names values should be separated

var names = [String]()
names.reserveCapacity(2)
names.append("Amy")
names.append("Rory")
names.append("Clara")

print(names)

//D. 3
//Explanation
//There will be 3 names in the array. The .reserveCapacity() method reserves enough space to store your intended number of elements, but it does not mean that it is the limit elements that can be placed.


//13   
      
//Given
let point = (556, 0) switch point {
case (let x, 0):
print("X was \(x)") case (0, let y):
print("Y was \(y)") case let (x, y):
print("X was \(x) and Y was \(y)") } 

//Based on the given, "switch point {" should be separated from the first line

let point = (556, 0)
switch point {
case (let x, 0):
 print("X was \(x)")
case (0, let y):
 print("Y was \(y)")
case let (x, y):
 print("X was \(x) and Y was \(y)")
}

let point = (556, 0) 
switch point {
case (let x, 0):
 print("X was \(x)") case (0, let y):
 print("Y was \(y)") case let (x, y):
 print("X was \(x) and Y was \(y)") }

//B. X was 556 
//Explanation
//The first case block was executed because it matches the given/switch value.



//14    

let userLoggedIn: Bool? = false
if !userLoggedIn! { print("Message one")
} else {
print("Message two")
} 

//B. "Message one"
//Explanation
//Bool? is an optional data type that can have values: nil/true/false.  In order to use this type, we need to unwrap it using unwrapping optionals such as if else syntax. The code !userLoggedIn! means to invert the Boolean value then unwrap it. This will result the userLoggedIn boolean value to be true which will print out "Message one".



//15    


//Given
var names = [String]() names.reserveCapacity(2)
names.append("Amy") names.append("Rory") names.append("Clara")

//Based on the given, all the names values should be separated

var names = [String]()
names.reserveCapacity(2)
names.append("Amy")
names.append("Rory")
names.append("Clara")

print(names)

//D. 3
//Explanation
//There will be 3 names in the array. The .reserveCapacity() method reserves enough space to store your intended number of elements, but it does not mean that it is the limit elements that can be placed.