; Author:                     Shepard Berry
; Assignment Title:           P6_1, "Product of Positives"
; Assignment Description:     Product of Positives
; Due Date:                   10-14-2022
; Date Created:               10-13-2022
; Date Last Modified:         10-13-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1    BYTE    "Enter a positive number:", 0
string     BYTE    30 DUP(?)
result     BYTE    "Product and Zero Count", 0
productLbl BYTE    "Product: "
product    BYTE    6 DUP(?), 0Dh, 0Ah
zeroLbl    BYTE    "Number of zeros: "
numZero    BYTE    6 DUP(?), 0




.CODE
_MainProc PROC

      mov cx, 10                ; init countdown to 10
      mov bx, 1                 ; init product to 1
      sub dx, dx                ; init zero count to 0


TOP:  cmp cx, 0                 ; compare countdown to 0
      jz DONE                   ; jump to done if cx == 0
      input prompt1, string, 30 ; prompt user to enter a positive num
      atow string               ; convert num to numeric

      dec cx                    ; decrement loop ctrl counter

      cmp ax, 0                 ; compare ax to zero
      jle BAD                   ; if ax <= 0 then jump to BAD

      imul bx, ax               ; multiply current product by num
      jmp TOP                   ; jump to TOP

BAD:  jne TOP                   ; jump to top if ax != 0

      inc dx                    ; increment zero counter
      jmp TOP                   ; jump to TOP

DONE: wtoa numZero, dx          ; convert zeroCt to ASCII, store in mem
      wtoa product, bx          ; convert product to ASCII, store in mem
      output result, productLbl ; output result to stdout

      sub eax, eax              ; init return code to zero
      ret                       ; return to calling code
_MainProc ENDP
END