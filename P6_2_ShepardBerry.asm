; Author:                     Shepard Berry
; Assignment Title:           P6_2, "Sum Input Values"
; Assignment Description:     Sum Input Values
; Due Date:                   10-14-2022
; Date Created:               10-13-2022
; Date Last Modified:         10-13-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1    BYTE    "Enter number:", 0
string     BYTE    30 DUP(?)
result     BYTE    "Sum", 0
sum        BYTE    6 DUP(?), 0


.CODE
_MainProc PROC
      sub bx, bx                  ; init sum to zero
      sub cx, cx                  ; init zero counter to zero

TOP:  input prompt1, string, 30   ; prompt user for a number
      atow string                 ; convert number to numeric

      add bx, ax                  ; add num to sum

      cmp bx, 5000                ; compare sum to 5000
      jg RES                      ; if sum > 5000 jump to RES

      cmp ax, 0                   ; compare num to zero
      jnz TOP                     ; if num != 0 jump to TOP


      inc cx                      ; increment zero counter

      cmp cx, 10                  ; compare zero counter to 10

      jne TOP                     ; jump to TOP

RES:  wtoa sum, bx                ; convert sum to ASCII, store in mem
      output result, sum          ; output sum to stdout


      sub eax, eax                ; init return code to zero
      ret                         ; return to calling code

_MainProc ENDP
END