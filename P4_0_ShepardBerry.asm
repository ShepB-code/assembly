; Author:                     Shepard Berry
; Assignment Title:           P4_0, "Evaluate an Expression"
; Assignment Description:     Evaluate the given expression: 5x + 5y - 2z
; Due Date:                   9-27-2022
; Date Created:               9-27-2022
; Date Last Modified:         9-27-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
xValue      BYTE    "Enter x: ", 0
yValue      BYTE    "Enter y: ", 0
zValue      BYTE    "Enter z: ", 0
string      BYTE    40 DUP (?)
result      BYTE    "The result is: ", 0
evaluation  BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
  input    xValue, string, 40    ; prompt user for x value
  atod     string                ; convert input to numeric (eax)
  mov      ebx, eax              ; move the x value to scratch

  input    yValue, string, 40    ; propmt user for second value
  atod     string                ; convert input to numeric (eax)

  add      ebx, eax              ; add x and y values

  mov      eax, ebx              ; move sum to eax (keep track of inital sum)

  add      ebx, ebx              ; double x and y sum
  add      ebx, ebx              ; double x and y sum

  add      ebx, eax              ; add original sum back to quadrupled sum

  input    zValue, string, 40    ; propmt user for second value
  atod     string                ; convert input to numeric (eax)

  add      eax, eax              ; double z value

  sub      ebx, eax              ; subtract 5(x+y) and 2z

  dtoa     evaluation, ebx       ; convert evaluation to ASCII, store in memory
  output   result, evaluation    ; output the result to stdout

  sub      eax, eax              ; init return code to zero
  ret                            ; return to calling code

_MainProc ENDP
END