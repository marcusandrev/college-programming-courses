// 1

func palindrome (_ word:String) -> Bool {

  let casedWord = String(word.lowercased())
  let reversedString = String(casedWord.reversed())
  return casedWord == reversedString  

}


print(palindrome("rotator")) //true
print(palindrome("Rats live on no evil star")) //true
print(palindrome("Never odd or even")) //false
print(palindrome("Hello, world")) //false



// 2

import Foundation

extension String {

    func fuzzyContains(_ word:String) -> Bool {

        return self.uppercased().localizedStandardRange(of:word) != nil

    }
}

print("Hello, world".fuzzyContains("Hello")) //true
print("Hello, world".fuzzyContains("WORLD"))  //true
print("Hello, world".fuzzyContains("Goodbye"))   //false



print("Hello, world".fuzzyContains("Hello")) //true
print("Hello, world".fuzzyContains("WORLD"))  //true
print("Hello, world".fuzzyContains("Goodbye"))   //false




// Another code



func palindrome(_ word:String) -> Bool {

   return word.lowercased() == String(word.reversed()).lowercased()
  
}


print(palindrome("rotator")) //true
print(palindrome("Rats live on no evil star")) //true
print(palindrome("Never odd or even")) //false
print(palindrome("Hello, world")) //false



