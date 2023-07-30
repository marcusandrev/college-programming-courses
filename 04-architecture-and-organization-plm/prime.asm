section .data
    prompt db "Enter a number (0-9): ", 0
    not_prime db "The number is not prime.", 0
    prime db "The number is prime.", 0
    divisor db "Divisor: ", 0
    newline db 10, 0

section .bss
    number resb 1

section .text
    global _start

_start:
    ; Display prompt and read input
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt
    mov edx, 20
    int 0x80

    ; Read the inputted number
    mov eax, 3
    mov ebx, 0
    mov ecx, number
    mov edx, 1
    int 0x80

    ; Convert ASCII digit to actual number
    sub byte [number], '0'

    ; Check if number is 0 or 1 (not prime)
    cmp byte [number], 0
    je not_prime
    cmp byte [number], 1
    je not_prime

    ; Initialize divisor counter
    mov ecx, 2

    ; Loop to find divisors
divisor_loop:
    ; Check if number is divisible by the current divisor
    mov eax, 0
    mov al, [number]
    xor edx, edx
    div ecx

    ; Check if there is a remainder (not divisible)
    cmp edx, 0
    je not_prime

    ; Increment divisor
    inc ecx

    ; Check if all divisors have been checked
    cmp ecx, 9
    jle divisor_loop

    ; If no divisors found, it is prime
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, prime
    mov edx, 19
    int 0x80

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80

not_prime:
    ; Print "not prime" message
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 2
    int 0x80

    mov eax, 4
    mov ebx, 1
    mov ecx, not_prime
    mov edx, 19
    int 0x80

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80
