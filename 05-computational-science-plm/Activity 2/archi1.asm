.model small
.stack 100h
.data
msg1 db "Input any lower case letter: $"
msg2 db 0DH, 0AH, " Equivalent upper case letter: $"
msg3 db 0DH, 0AH, "Invalid input $"
.code
.startup
    mov ah, 9h
    lea dx, msg1
    int 21h
    
    mov ah, 1h 
    int 21h
    
    mov bl, al
    sub bl, 32
    
    cmp bl, 65 ; condition: check if the value of bl is below 65 (65 is A in ASCII)
    jb invalid ; jumps to invalid when true
    
    cmp bl, 90 ; condition: check if the value of bl is above 90 (90 is Z in ASCII)
    ja invalid ; jumps to invalid when true
        
    mov ah, 9h 
    lea dx, msg2
    int 21h
    
    mov dl, bl
    mov ah, 02h
    int 21h
    
    mov ah, 4ch ; terminate
    int 21h
    
    invalid: 
    mov ah, 9h
    lea dx, msg3
    int 21h
    
    mov ah, 4ch ; terminate
    int 21h
end