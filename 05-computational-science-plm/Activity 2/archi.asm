.model small
.stack 100h
.data
msg1 db "The Counting Numbers from 0-9", 0DH, 0AH
.code
.startup
    mov ah, 9h ;
    lea dx, msg1
    int 21h
    
    mov bl, 30h
    mov cx, 0 
    chico:

    
    mov dl, 30h
    mov ah, 02h    
    int 21h
    inc cx 

    cmp cx, 9
    jl chico    
    
    mov ah, 4ch ; terminate
    int 21h
end