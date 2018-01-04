
extern printf

SECTION .data		
        a:	dd	5
        fmt:    db      "a=%d, eax=%d", 33, 10, 10, 0
        str:	db      "Hi-%d", 33, 0x21, 10, 0
        str_len equ $-str


SECTION .bss			; Section containing uninitialized data

	BUFFLEN	equ 1024	; Length of buffer
	Buff: 	resb BUFFLEN	; Text buffer itself
	

SECTION .text

    global main		; the standard gcc entry point
    main:
            push    ebp		; set up stack frame
            mov     ebp,esp

            mov	    eax, [a]	; put a from store into register
            add	    eax, 33	; a+33
            push    eax		; push onto stack
            push    dword [a]	; value of variable a
            push    dword fmt	; address of ctrl string
            call    printf	; Call C function
            add     esp, 12	; pop stack

            push    dword str_len
            push    dword str
            call    printf	; Call C function
            add     esp, 8	; pop stack


            mov     esp, ebp	; takedown stack frame
            pop     ebp		; same as "leave" op

            mov	    eax,0	;  normal, no error, return value
            ret			; return

	
