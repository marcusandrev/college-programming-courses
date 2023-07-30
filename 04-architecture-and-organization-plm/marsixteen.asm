.model small
.stack 100h
.data

msg1 db "Input ad lowercase letter: $"
msg2 db 0DB, 0AH, "Equivalent uppercase letter$"
.code
.startup

    mov ah, 9h 
    lea dx, msg1 
    int 21h 
    mov ah, 1h
    int 21h ;char code in AL mov b1, al
    sub bl, 32 ; b1 = b1 - 32
    mov ah, 9h 
    lea dx, msg2 
    int 21h 
    mov dl,bl 
    mov ah, 02h 
    int 21h
    mov ah, 4ch ; exit to dos int 21h
    int 21h

end

