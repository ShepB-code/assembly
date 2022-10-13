; Author:                     Shepard Berry
; Assignment Title:           P3_3 "Subtract Two Values"
; Assignment Description:     Subtract two interger values
; Due Date:                   9-24-2022
; Date Created:               9-23-2022
; Date Last Modified:         9-23-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1     BYTE    "Enter the first number: ", 0
prompt2     BYTE    "Enter the second number: ", 0
string      BYTE    40 DUP (?)
result      BYTE    "The difference is: ", 0
difference  BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
  input    prompt1, string, 40   ; prompt user for first value
  atod     string                ; convert input to numeric (eax)
  mov      ebx, eax              ; move the minuend to scratch

  input    prompt2, string, 40   ; propmt user for second value
  atod     string                ; convert input to numeric (eax)

  sub      ebx, eax              ; calculate diff between 1st and 2nd value

  dtoa     difference, ebx       ; convert difference to ASCII, store in memory
  output   result, difference    ; output the result to stdout

  sub      eax, eax              ; init return code to zero
  ret                            ; return to calling code

_MainProc ENDP
END