;http://www.nasm.us/doc/nasmdoc0.html
;http://www.posix.nl/linuxassembly/nasmdochtml/nasmdoc0.html
;https://godbolt.org/
;https://linux.die.net/man/1/objdump

extern printf
extern putchar
extern strlen

SECTION .data		
        a:	dd	5
        fmt:    db      "a=%d, eax=%d", 33, 10, 10, 0
        str:	db      "01) Hi-%d", 33, 0x21, 10, 0
        str_len equ $-str
        
        test_str: db "%2d) Test FCN Called!!!", 10, 0
        test_str_len equ $-test_str
        
        test_str2: db "%2d) Test FCN2 Called!!!", 10, 0
        test_str2_len equ $-test_str2

        done: db 10, "DONE!!", 10, 0
        done_len equ $-done
        
        result_str: db 10,10,"%2d) Result = %d", 10, 10, 0


SECTION .bss			; Section containing uninitialized data

        BUFFLEN	equ 1024	; Length of buffer
        buff: 	resb BUFFLEN	; Text buffer itself
        

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
            add     esp, 12	; pop 3 ints
            
            push    dword str_len
            lea     eax, [str + 1] ;skip first char in string
            push    eax
            call    printf	; Call C function
            add     esp, 8	; pop 2 ints

            call    test_fcn
            call    test_fcn2
            
            mov	    ecx, done_len
            mov	    esi, done
            mov	    edi, buff
            cld
            rep     movsb
            
            push    buff
            call    printf
            add     esp, 4	; pop int
            
            
            call sample_if      ; if code snippets
            
            
                    
            push    done        ; Get length of done string
            call    strlen
            add     esp, 4
            
            push    eax
            push    2
            push    result_str
            call    printf      ; Print length of done string
            add     esp, 12     
            
            mov     esp, ebp	; takedown stack frame
            pop     ebp		; same as "leave" op

            mov	    eax,0	;  normal, no error, return value
            ret			; return
            

    test_fcn:
            push    ebp		; set up stack frame
            mov     ebp, esp
            
            mov     ecx, 10
        .beg_loop:
            push    ecx
            push    test_str
            call    printf
            add     esp, 4	; pop int
            pop     ecx
            loop    .beg_loop, ecx
        
            mov     esp, ebp	; takedown stack frame
            pop     ebp		; same as "leave" op
            mov	    eax,0	;  normal, no error, return value
            ret
            

    test_fcn2:
            enter   0, 0
            push    10
            call    putchar
            add     esp, 4
            
            mov     ecx, 10
        .beg_loop:
            push    ecx
            push    test_str2
            call    printf
            add     esp, 4	; pop int
            pop     ecx
            sub     ecx, 1      ;decrement loop counter by 1
            jnz     .beg_loop
            
            
            push    done
            call    printf
            add     esp, 4	; pop int
            
            leave
            ret
            
            
    sample_if:
        ;prints first local variable if greater than or equal to 100
        ;else prints 50 if varaible is greater than or equal to 50 but less than 100
        ;else prints 0 if variable is less than 50
        
            enter   0, 0
            push    174          ; condition {22, 77, 120}
            
            mov     eax, [ebp - 4]
            cmp     eax, 100
            jae     near .label1
            
            cmp     eax, 50
            jae     near .label2
                        
            push    0
            jmp     .continue_fcn

            
        .label1: ;if greater than 100 print result = 100
            push    eax
            jmp     .continue_fcn
            
           
        .label2: ;if greater than 100 print result = 100
            push    50
            jmp     .continue_fcn
           
           
        .continue_fcn:
            push    1
            push    result_str
            call    printf
            add     esp, 8	; pop int and string
            
            
            add     esp, 4	; pop condition
            leave
            ret

        
