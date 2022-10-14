; name:
; file:

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096
input1    BYTE    "Enter the first value: ",0
string    BYTE    40 DUP(?)
.DATA


.CODE
_MainProc PROD


    cmp ecx, 0
    je

    sub eax, eax
    ret

_MainProc ENDP
END