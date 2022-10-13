; Author:                     Shepard Berry
; Assignment Title:           P3_2 "Sum of Three"
; Assignment Description:     Add three integer value numbers together
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
prompt3  BYTE    "Enter the third number: ", 0
string   BYTE    40 DUP (?)
result   BYTE    "The sum is: ", 0
sum      BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
  input    prompt1, string, 40   ; prompt user for first value
  atod     string                ; convert input to numeric (eax)
  mov      ebx, eax              ; initialize sum to 1st value

  input    prompt2, string, 40   ; propmt user for second value
  atod     string                ; convert input to numeric (eax)

  add      ebx, eax              ; add 2nd value to sum (ebx)

  input    prompt3, string, 40   ; prompt user for first value
  atod     string                ; convert input to numeric (eax)

  add      eax, ebx              ; calculate sum of 3 values

  dtoa     sum, eax              ; convert sum to ASCII, store in memory
  output   result, sum           ; output the result to stdout

  sub      eax, eax              ; init return code to zero
  ret                            ; return to calling code

_MainProc ENDP
END
