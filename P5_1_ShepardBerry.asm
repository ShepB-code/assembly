; Author:                     Shepard Berry
; Assignment Title:           P5_1, "Weighted Average"
; Assignment Description:     Weighted Average
; Due Date:                   10-07-2022
; Date Created:               10-07-2022
; Date Last Modified:         10-07-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
grade1          BYTE    "Enter Grade 1: ", 0
weight1         BYTE    "Enter Weight 1: ", 0
grade2          BYTE    "Enter Grade 2: ", 0
weight2         BYTE    "Enter Weight 2: ", 0
grade3          BYTE    "Enter Grade 3: ", 0
weight3         BYTE    "Enter Weight 3: ", 0
grade4          BYTE    "Enter Grade 4: ", 0
weight4         BYTE    "Enter Weight 4: ", 0
string          BYTE    30 DUP (?)
resultMsg       BYTE    "The weighted sum and average are: ", 0
sumMsg          BYTE    "The weighted sum is: "
weightSum       BYTE    6 DUP (?), 0Dh, 0Ah
avgMsg          BYTE    "The weighted average is: "
quotient        BYTE    6 DUP (?), '.'
remainder       BYTE    6 DUP (?), 0
sumWeights      WORD    ?

.CODE
_MainProc PROC
    input  grade1, string, 30     ; prompt user for grade 1
    atow   string                 ; convert grade 1 to numeric
    mov    bx, ax                 ; move grade 1 to scratch

    input  weight1, string, 30    ; prompt user for weight 1
    atow   string                 ; convert weight 1 to numeric
    mov    sumWeights, ax         ; move weight 1 to mem
    imul   bx                     ; calculate (grade 1 * weight 1)

    mov    cx, ax                 ; move result to scratch

    input  grade2, string, 30     ; prompt user for grade 2
    atow   string                 ; convert grade 2 to numeric
    mov    bx, ax                 ; move grade 2 to scratch

    input  weight2, string, 30    ; prompt user for weight 2
    atow   string                 ; convert weight 2 to numeric
    add    sumWeights, ax         ; add weight 2 to sum of weights in mem
    imul   bx                     ; calc (grade 2 * weight 2)

    add    cx, ax                 ; add calculation to result

    input  grade3, string, 30     ; prompt user for grade 3
    atow   string                 ; convert grade 3 to numeric
    mov    bx, ax                 ; move grade 3 to scratch

    input  weight3, string, 30    ; prompt user for weight 3
    atow   string                 ; convert weight 3 to numeric
    add    sumWeights, ax         ; add weight 3 to sum of weights in mem
    imul   bx                     ; calc (grade 3 * weight 3)

    add    cx, ax                 ; add calculation to result

    input  grade4, string, 30     ; prompt user for grade 4
    atow   string                 ; convert grade 4 to numeric
    mov    bx, ax                 ; move grade 4 to scratch

    input  weight4, string, 30    ; prompt user for weight 4
    atow   string                 ; convert weight 4 to numeric
    add    sumWeights, ax         ; add weight 4 to sum of weights in mem
    imul   bx                     ; calc (grade 4 * weight 4)

    add    ax, cx                 ; add calculation to result

    wtoa   weightSum, ax          ; conv weighted sum to ASCII, store in mem

    cwd                           ; prepare dividend
    idiv   sumWeights             ; divide weighted sum by the sum of weights
    wtoa   quotient, ax           ; convert quotient to ASCII, store in mem

    imul   ax, dx, 100            ; convert remainder to whole number equivalent

    cwd                           ; prepare dividend
    idiv   sumWeights             ; divide remainder by the sum of weights

    wtoa   remainder, ax          ; conv remainder to ASCII, store in mem

    output resultMsg, sumMsg      ; display weighted sum and average

    sub eax, eax                  ; init return code to zero
    ret                           ; return to calling code
_MainProc ENDP
END