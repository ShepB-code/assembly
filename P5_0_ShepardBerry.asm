; Author:                     Shepard Berry
; Assignment Title:           P5_0, "Calculate Average"
; Assignment Description:     Calculate the averge of 4 test scores
; Due Date:                   10-07-2022
; Date Created:               10-06-2022
; Date Last Modified:         10-07-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
exam1Prompt          BYTE    "Enter Exam 1 score: ", 0
exam2Prompt          BYTE    "Enter Exam 2 score: ", 0
exam3Prompt          BYTE    "Enter Exam 3 score: ", 0
finalExamPrompt      BYTE    "Enter Final Exam score: ", 0
string               BYTE    30 DUP (?)
resultMsg            BYTE    "The sum and average are:", 0
sum                  BYTE    6 DUP (?), 0Dh, 0Ah
quotient             BYTE    6 DUP (?), '.'
remainder            BYTE    6 DUP (?), 0


.CODE
_MainProc PROC
  input    exam1Prompt, string, 30        ; prompt user for exam 1
  atow     string                         ; convert exam 1 to numeric
  mov      bx, ax                         ; move exam 1 to scatch

  input    exam2Prompt, string, 30        ; propmt user for exam 2
  atow     string                         ; convert exam 2 to numeric
  add      bx, ax                         ; add exam 2 to exam 1

  input    exam3Prompt, string, 30        ; prompt user for exam 3
  atow     string                         ; convert exam 3 to numeric
  add      bx, ax                         ; add exam 3 to sum


  input    finalExamPrompt, string, 30    ; prompt user for final exam
  atow     string                         ; convert final exam to numeric
  add      bx, ax                         ; add final exam to sum


  add      ax, bx                         ; add final test score to sum again
  wtoa     sum, ax                        ; convert sum to ASCII, store in mem

  cwd                                     ; converts word to dword for dividend

  mov      bx, 5                          ; prepare divisor to calc quotient

  idiv     bx                             ; calculate the average
  wtoa     quotient, ax                   ; conv quotient to ASCII, store in mem

  imul     ax, dx, 100                    ; conv remainder to a whole number

  cwd                                     ; converts word to dword for dividend

  idiv     bx                             ; calculate decimal equiv of remainder
  wtoa     remainder, ax                  ; conv remainder to ASCII, store mem

  output   resultMsg, sum                 ; output the sum and average

  sub      eax, eax                       ; init return code to zero
  ret                                     ; return to calling code

_MainProc ENDP
END