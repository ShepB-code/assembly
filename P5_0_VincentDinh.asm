;  Author:                      Vincent Dinh
;  Assignment Title:            P5_0_VincentDinh.asm
;  Assignment Description:      Calculate Average
;  Date Created:                10-03-2022
;  Due Date:                    10-07-2022
;  Date Last Modified:          10-07-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1    BYTE    "Enter Exam 1 score: ", 0
prompt2    BYTE    "Enter Exam 2 score: ", 0
prompt3    BYTE    "Enter Exam 3 score: ", 0
prompt4    BYTE    "Enter Final Exam score: ", 0
string     BYTE    30 DUP (?)
msgLabel   BYTE    "The sum and average are: ", 0
sum        BYTE    6 DUP (?), 0Dh, 0Ah
quot       BYTE    6 DUP (?), '.'
rem        BYTE    6 DUP (?), 0

.CODE
_MainProc PROC
  input    prompt1, string, 30    ; prompt user for test 1 score
  atow     string                 ; conv test 1 score to num
  mov      bx, ax                 ; store test 1 score to scratch

  input    prompt2, string, 30    ; propt user for test 2 score
  atow     string                 ; conv test 2 score to num
  add      bx, ax                 ; add test 2 score to test 1

  input    prompt3, string, 30    ; prompt user for test 3 score
  atow     string                 ; conv test 3 score to num
  add      bx, ax                 ; add test 3 score to result

  input    prompt4, string, 30    ; prompt user for final test score
  atow     string                 ; conv final test score to num
  add      bx, ax                 ; add final test score to result

  add      ax, bx                 ; add final test score to result again
  wtoa     sum, ax                ; conv sum to ASCII, store in mem

  cwd                             ; converts word to dword for dividend

  mov      bx, 5                  ; prepare divisor to calc quotient
  
  idiv     bx                     ; calculate average quotient
  wtoa     quot, ax               ; conv quot to ASCII, store in mem

  imul     ax, dx, 100            ; conv remainder to whole number equiv

  cwd                             ; converts word to dword for dividend

  idiv     bx                     ; calc dec equiv of remainder
  wtoa     rem, ax                ; conv rem to ASCII, store in mem

  output   msgLabel, sum          ; display sum and average

  sub eax, eax                    ; return code of 0 (nominal)
  ret                             ; return to calling code

_MainProc ENDP
END