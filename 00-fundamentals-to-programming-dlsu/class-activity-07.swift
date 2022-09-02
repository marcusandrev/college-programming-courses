// 1.

func fizzbuzz(number:Int) -> String {

  switch (number % 3 == 0, number % 5 == 0) {
    case(true, false):
    return "Fizz"

    case (false, true):
    return "Buzz"

    case (true, true):
    return "FizzBuzz"

    case (false, false):
    return String (number)
  }
}

print(fizzbuzz(number:15))
print(fizzbuzz(number:9))
print(fizzbuzz(number:10))
print(fizzbuzz(number:11))




// 2.  

let name: String? = "Andre Villanueva"
let password: String? = "Password123"

switch (name, password) {

  case let (.some(name), .some(password)):
  print("Hello, \(name)")

  case (.some(_), .none):
  print("Please enter a password.")

  default:
  print("Who are you?")
}




// 3  

let name: String? = "Andre Villanueva"
let password: String? = "Password123"

switch (name, password) {

  case let (name?, _?):
  print("Hello, \(name)")

  case (name?, nil):
  print("Please enter a password.")

  default:
  print("Who are you?")
}





// 4 

var ages = [17, 36, 71]

for age in ages {
  if (0 ..< 18 ~= age) {
    print("\(age) years of age = You have the energy and time, but not the money \n")
  }

  else if (18 ..< 70 ~= age) {
    print("\(age) years of age = You have the energy and money, but not the time \n")
  }

  else {
    print("\(age) years of age = You have the time and money, but not the energy \n")
  }
}





// 5

var ages = [16, 28, 75]

for age in ages {
  if (0 ..< 18).contains(age) {
    print("\(age) years of age = You have the energy and time, but not the money \n")
  }

  else if (18 ..< 70).contains(age) {
    print("\(age) years of age = You have the energy and money, but not the time \n")
  }

  else {
    print("\(age) years of age = You have the time and money, but not the energy \n")
  }
}




// 6 


enum WeatherType {
  case Cloudy(coverage:Int)
  case Sunny(coverage:Int)
  case Windy(coverage:Int)
}

let today = WeatherType.Cloudy(coverage:100)
let phrase = "in the area of Dasmariñas."

switch today {
  case .Cloudy(let coverage) where coverage <= 100:
  print("It's Cloudy with \(coverage) % coverage \(phrase)")

  case .Windy:
  print("It's windy \(phrase)")

  default:
  print("It's sunny \(phrase)")
}




enum WeatherType {
  case Cloudy(coverage:Int)
  case Sunny(coverage:Int)
  case Windy(coverage:Int)
}

let today = WeatherType.Cloudy(coverage:1)

switch today {
  case .Cloudy(let coverage) where coverage == 0:
  print("You must live in Dasmariñas")

  case .Cloudy(let coverage) where (1...99).contains(coverage):
  print("It's Cloudy with \(coverage) % coverage")

  case .Cloudy(let coverage) where coverage == 100:
  print("You must live in Manila")

  case .Windy:
  print("It's windy")

  default:
  print("It's sunny")
}





// 7

// import Foundation
// import Swift

// class President {
//   let name: String

//   init(name: String) {
//     self.name = name
//   }

//   func reversedName() {
//     let reversed = String(name.reversed())
//     print ("\(name.uppercased()) backwards is \(reversed.uppercased())")
//   }
// }

// let richard = President (name: "Richard Uy")
// richard.reversedName()




 