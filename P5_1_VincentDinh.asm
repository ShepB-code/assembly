;  Author:                      Vincent Dinh
;  Assignment Title:            P5_1_VincentDinh.asm
;  Assignment Description:      Weighted Average
;  Date Created:                10-06-2022
;  Due Date:                    10-07-2022
;  Date Last Modified:          10-07-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
sumW        WORD     ?
prompt1     BYTE    "Enter Grade 1: ", 0
prompt2     BYTE    "Enter Weight 1: ", 0
prompt3     BYTE    "Enter Grade 2: ", 0
prompt4     BYTE    "Enter Weight 2: ", 0
prompt5     BYTE    "Enter Grade 3: ", 0
prompt6     BYTE    "Enter Weight 3: ", 0
prompt7     BYTE    "Enter Grade 4: ", 0
prompt8     BYTE    "Enter Weight 4: ", 0
string      BYTE    30 DUP(?)
resultLabel BYTE    "The weighted sum and average are: ", 0
sumLbl      BYTE    "The weighted sum is: "
WeightSum   BYTE    6 DUP (?), 0Dh, 0Ah
avgLbl      BYTE    "The weighted average is: "
quot        BYTE    6 DUP (?), '.'
rem         BYTE    6 DUP (?), 0

.CODE
_MainProc PROC

  input  prompt1, string, 30    ; prompt user for grade 1
  atow   string                 ; conv grade 1 to num
  mov    bx, ax                 ; move grade 1 to scratch

  input  prompt2, string, 30    ; prompt user for weight 1
  atow   string                 ; conv weight 1 to num
  mov    sumW, ax               ; move weight 1 to mem
  imul   bx                     ; calc (grade 1 * weight 1)

  mov    cx, ax                 ; move result to scratch

  input  prompt3, string, 30    ; prompt user for grade 2
  atow   string                 ; conv grade 2 to num
  mov    bx, ax                 ; move grade 2 to scratch

  input  prompt4, string, 30    ; prompt user for weight 2
  atow   string                 ; conv weight 2 to num
  add    sumW, ax               ; add weight 2 to sum of weights
  imul   bx                     ; calc (grade 2 * weight 2)

  add    cx, ax                 ; add result to weighted sum

  input  prompt5, string, 30    ; prompt user for grade 3
  atow   string                 ; conv grade 3 to num
  mov    bx, ax                 ; move grade 3 to scratch

  input  prompt6, string, 30    ; prompt user for weight 3
  atow   string                 ; conv weight 3 to num
  add    sumW, ax               ; add weight 3 to sum of weights
  imul   bx                     ; calc (grade 3 * weight 3)

  add    cx, ax                 ; add result to weighted sum

  input  prompt7, string, 30    ; prompt user for grade 4
  atow   string                 ; conv grade 4 to num
  mov    bx, ax                 ; move grade 4 to scratch

  input  prompt8, string, 30    ; prompt user for weight 4
  atow   string                 ; conv weight 4 to num
  add    sumW, ax               ; add weight 4 to sum of weights
  imul   bx                     ; calc (grade 4 * weight 4)

  add    ax, cx                 ; add result to weighted sum

  wtoa   WeightSum, ax          ; conv weighted sum to ASCII, store in mem

  cwd                           ; prepare dividend
  idiv   sumW                   ; divide weighted sum by sum of weights
  wtoa   quot, ax               ; conv quot to ASCII, store in mem

  imul   ax, dx, 100            ; conv rem to whole number equiv

  cwd                           ; prepare dividend
  idiv   sumW                   ; divide rem by sum of weights

  wtoa   rem, ax                ; conv sum of weights to ASCII, store in mem

  output resultLabel, sumLbl    ; display weighted sum and average

  sub eax, eax                  ; return code of 0 (nominal)
  ret                           ; return to calling code
_MainProc ENDP
END