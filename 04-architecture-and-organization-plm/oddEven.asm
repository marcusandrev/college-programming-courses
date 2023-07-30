.model small
.stack 100h

.data
prompt db 'Enter a digit (0-9): ', 10, '$'
odd_msg db 'The number is odd.', 10, '$'
even_msg db 'The number is even.', 10, '$'
restart_prompt db 'Do you want to run the program again? (y/n): ', 10, '$'

.code
start: ; label for start of loop
    ; initialize data segment
    mov ax, @data
    mov ds, ax

    ; display prompt to user
    mov ah, 09h
    lea dx, prompt
    int 21h

    ; read user input
    mov ah, 01h
    int 21h
    sub al, '0'

    ; determine if input is odd or even
    mov dl, al
    and dl, 01h ; check if the least significant bit is set
    jz even ; jump to even label if input is even
odd: ; label for odd case
    ; display "odd_msg" string
    mov ah, 09h
    lea dx, odd_msg
    int 21h
    jmp restart ; jump to restart prompt
even: ; label for even case
    ; display "even_msg" string
    mov ah, 09h
    lea dx, even_msg
    int 21h
restart: ; label for restart prompt
    ; display restart prompt
    mov ah, 09h
    lea dx, restart_prompt
    int 21h
    ; read user response
    mov ah, 01h
    int 21h
    ; check user response
    cmp al, 'y'
    je start ; if user responds "y", jump to start of loop
    ; otherwise, exit program
    mov ah, 4ch
    int 21h
end start