; Author:                     Shepard Berry
; Assignment Title:           P4_1, "Bocce Perimeter"
; Assignment Description:     Calculate the Perimeter of a Bocce court
; Due Date:                   9-27-2022
; Date Created:               9-27-2022
; Date Last Modified:         9-27-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
lengthPrompt      BYTE    "Enter length: ", 0
widthPrompt       BYTE    "Enter width: ", 0
string            BYTE    40 DUP (?)
result            BYTE    "The perimeter is: ", 0
perimeter         BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
  input    lengthPrompt, string, 40    ; prompt user for length value
  atod     string                      ; convert input to numeric (eax)

  add      eax, eax                    ; double length
  mov      ebx, eax                    ; move the length value to scratch

  input    widthPrompt, string, 40     ; propmt user for width value
  atod     string                      ; convert input to numeric (eax)

  add      eax, eax                    ; double width

  add      eax, ebx                    ; add doubled length and width together

  dtoa     perimeter, eax              ; convert evaluation to ASCII, store
                                       ;     in memory
  output   result, perimeter           ; output the result to stdout

  sub      eax, eax                    ; init return code to zero
  ret                                  ; return to calling code

_MainProc ENDP
END