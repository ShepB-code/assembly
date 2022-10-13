; Author:                     Shepard Berry
; Assignment Title:           P3_1 "Sum of Two"
; Assignment Description:     Add two integer value numbers together
; Due Date:                   9-24-2022
; Date Created:               9-22-2022
; Date Last Modified:         9-23-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1  BYTE    "Enter the first number: ", 0
prompt2  BYTE    "Enter the second number: ", 0
string   BYTE    40 DUP (?)
result   BYTE    "The sum is: ", 0
sum      BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
  input    prompt1, string, 40   ; prompt user for first value

  atod     string                ; convert input to numeric (eax)
  mov      ebx, eax              ; move contents of eax to ebx

  input    prompt2, string, 40   ; propmt user for second value
  atod     string                ; convert input to numeric (eax)

  add      eax, ebx              ; calculate sum of 1st and 2nd values

  dtoa     sum, eax              ; convert sum to ASCII, store in memory
  output   result, sum           ; output the result to stdout

  sub      eax, eax              ; init return code to zero
  ret                            ; return to calling code

_MainProc ENDP
END



