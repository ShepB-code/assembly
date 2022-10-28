;  Assignment Description:      Calculate Average
;  Date Created:                10-03-2022
;  Due Date:                    10-07-2022
;  Date Last Modified:          10-07-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1    BYTE    "Enter 10 values: ", 0
string     BYTE    30 DUP (?)
msgLabel   BYTE    "The product and the number of zeros are: ", 0
productLbl BYTE    "Product: "
product    BYTE    6 DUP(?), 0Dh, 0Ah
zeroLbl    BYTE    "Number of zeros: "
numZero    BYTE    6 DUP(?), 0


.CODE
_MainProc PROC
  
	mov cx, 11
	mov bx, 1
	mov dx, 0

TOP:
  dec cx
	jz  RESULT
	input prompt1, string, 30
	atow  string

  cmp   ax, 0
	jle   BAD

	imul  bx, ax
	jmp   TOP


BAD:
  cmp ax, 0
	jne TOP
	inc dx
	jmp TOP

RESULT:
	wtoa   product, bx          ; if count is 10, conv product to ASCII, store in mem
  wtoa   numZero, dx          ; if count is 10, conv numZero to ASCII, store in mem
  output msgLabel, productLbl ; display result

	sub eax, eax                ; return code of 0 (nominal)
	ret                         ; return to calling code

_MainProc ENDP
END